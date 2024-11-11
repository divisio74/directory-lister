/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-myls-pierre.baud
** File description:
** annexel
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my_ls.h"

void print_perm(mode_t mode)
{
    char permis[10];

    permis[0] = (mode & S_IRUSR) ? 'r' : '-';
    permis[1] = (mode & S_IWUSR) ? 'w' : '-';
    permis[2] = (mode & S_IXUSR) ? 'x' : '-';
    permis[3] = (mode & S_IRGRP) ? 'r' : '-';
    permis[4] = (mode & S_IWGRP) ? 'w' : '-';
    permis[5] = (mode & S_IXGRP) ? 'x' : '-';
    permis[6] = (mode & S_IROTH) ? 'r' : '-';
    permis[7] = (mode & S_IWOTH) ? 'w' : '-';
    permis[8] = (mode & S_IXOTH) ? 'x' : '-';
    permis[9] = '\0';
    write(STDOUT_FILENO, "-", 1);
    write(STDOUT_FILENO, permis, 10);
    write(STDOUT_FILENO, " ", 1);
}

void print_hardlink_count(long int hardlinks)
{
    char ttemp[20];
    char temp;
    int i = 0;
    int j = 0;

    for (; hardlinks > 0; hardlinks /= 10) {
        ttemp[i] = (hardlinks % 10) + '0';
        i++;
    }
    if (i == 0) {
        ttemp[i] = '0';
        i++;
    }
    for (j; j < i / 2; j++) {
        temp = ttemp[j];
        ttemp[j] = ttemp[i - j - 1];
        ttemp[i - j - 1] = temp;
    }
    write(STDOUT_FILENO, ttemp, i);
    write(STDOUT_FILENO, " ", 1);
}
