/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-myls-pierre.baud
** File description:
** pre_ls
*/

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my_ls.h"
#include "struct.h"

int pre_ls(struct dirent *dir_str, char **namelist,
    DIR *direc, flags_d_t flags)
{
    int n = 0;

    dir_str = readdir(direc);
    while (dir_str != NULL) {
        namelist[n] = dir_str->d_name;
        n++;
        dir_str = readdir(direc);
    }
    if (flags.ft == 1) {
        fonction_tri_t((char **)namelist, n);
    } else {
        fonction_tri((char **)namelist, n);
    }
    for (int i = 0; i < n; i++) {
        structa(namelist[i], flags);
    }
    closedir(direc);
}
