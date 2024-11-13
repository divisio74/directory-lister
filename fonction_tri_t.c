/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-myls-pierre.baud
** File description:
** fonction_tri_t
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include "my_ls.h"
#include "struct.h"

time_t fonction_time(const char *filename)
{
    struct stat file_stat;

    if (stat(filename, &file_stat) == 0) {
        return file_stat.st_mtime;
    } else {
        return 0;
    }
}

int fonction_compare_t(const char *a, const char *b)
{
    time_t time_a = fonction_time(a);
    time_t time_b = fonction_time(b);

    if (time_a < time_b) {
        return 1;
    } else {
        return 0;
    }
}

void fonction_tri_t(char **arr, int n)
{
    char *k;
    int i = 0;
    int j = 0;

    for (i; i < n; i++) {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && fonction_compare_t(arr[j], k) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}
