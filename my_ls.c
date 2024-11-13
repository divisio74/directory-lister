/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-myls-pierre.baud
** File description:
** my_test
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include "my_ls.h"
#include "struct.h"


void boucleflags(char **argv, flags_d_t *flags, int i)
{
    int j = 0;

    for (j; argv[i][j] != '\0'; j++) {
        if (argv[i][j] == 'a')
            flags->fa = 1;
        if (argv[i][j] == 'l')
            flags->fl = 1;
        if (argv[i][j] == 't')
            flags->ft = 1;
    }
}

int boucle_argv(int argc, char **argv, flags_d_t *flags)
{
    int path_index = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            boucleflags(argv, flags, i);
        } else {
            path_index = i;
        }
    }
    return path_index;
}

int boucle_fl(char *name)
{
    struct stat datafiles;

    if (stat(name, &datafiles) == 0) {
        print_l(name, &datafiles);
        return 0;
    } else {
        return 1;
    }
}

int structa(char *namelist, flags_d_t flags)
{
    struct stat datafiles;
    int lend = my_strlen(namelist);

    if (flags.fa == 1 || namelist[0] != '.') {
        if (flags.fl == 1) {
            boucle_fl(namelist);
        } else {
            write(STDOUT_FILENO, namelist, lend);
            write(STDOUT_FILENO, " ", 1);
        }
    }
}

int my_ls(int argc, char *argv[])
{
    DIR *direc;
    struct dirent *dir_str;
    flags_d_t flags = {0, 0, 0, 0};
    int path_index;
    char *namelist[100];
    int n = 0;

    path_index = boucle_argv(argc, argv, &flags);
    if (path_index == 0) {
        direc = opendir(".");
    } else {
        direc = opendir(argv[path_index]);
    }
    if (direc == NULL) {
        perror("Pas de répertoire");
        return 1;
    }
    pre_ls(dir_str, namelist, direc, flags);
    return 0;
}
