/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-myls-pierre.baud
** File description:
** flagl
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


void print_prop(uid_t uid)
{
    struct passwd *pw = getpwuid(uid);

    if (pw != NULL) {
        write(STDOUT_FILENO, pw->pw_name, my_strlen(pw->pw_name));
        write(STDOUT_FILENO, " ", 1);
    } else {
        write(STDOUT_FILENO, "unknown", 7);
        write(STDOUT_FILENO, " ", 1);
    }
}

void print_group(gid_t gid)
{
    struct group *gr = getgrgid(gid);

    if (gr != NULL) {
        write(STDOUT_FILENO, gr->gr_name, my_strlen(gr->gr_name));
        write(STDOUT_FILENO, " ", 1);
    } else {
        write(STDOUT_FILENO, "unknown", 7);
        write(STDOUT_FILENO, " ", 1);
    }
}

void print_t(long int taille)
{
    char ttemp[20];
    char temp;
    int i = 0;
    int j = 0;

    for (; taille > 0; taille /= 10) {
        ttemp[i] = (taille % 10) + '0';
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

void afficher_date(time_t mtime)
{
    char *date = ctime(&mtime);
    char *start = date + 4;
    char *end = date + my_strlen(date) - 9;

    date[my_strlen(date) - 1] = '\0';
    *end = '\0';
    write(STDOUT_FILENO, start, my_strlen(start));
    write(STDOUT_FILENO, " ", 1);
}

void print_l(const char *nom_fichier, struct stat *datafiles)
{
    print_perm(datafiles->st_mode);
    print_hardlink_count(datafiles->st_nlink);
    print_prop(datafiles->st_uid);
    print_group(datafiles->st_gid);
    print_t(datafiles->st_size);
    afficher_date(datafiles->st_mtime);
    write(STDOUT_FILENO, nom_fichier, my_strlen(nom_fichier));
    write(STDOUT_FILENO, "\n", 1);
}
