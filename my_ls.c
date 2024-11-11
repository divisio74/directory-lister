/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-myls-pierre.baud
** File description:
** my_test
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include "my_ls.h"

typedef struct {
    int fl;
    int fa;
} Flags_d;


void boucleflags(char **argv, Flags_d *flags, int i)
{
    int j = 0;

    for (j; argv[i][j] != '\0'; j++) {
        if (argv[i][j] == 'a')
            flags->fa = 1;
        if (argv[i][j] == 'l')
            flags->fl = 1;
    }
}

int boucle_argv(int argc, char **argv, Flags_d *flags)
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

int boucle_fl(struct dirent *directory_struct)
{
    struct stat datafiles;

    if (stat(directory_struct->d_name, &datafiles) == 0) {
        print_l(directory_struct->d_name, &datafiles);
        return 0;
    } else {
        return 1;
    }
}

int structa(struct dirent *directory_struct, Flags_d flags, DIR *directory)
{
    struct stat datafiles;
    int lend = my_strlen(directory_struct->d_name);

    if (flags.fa == 1 || directory_struct->d_name[0] != '.') {
        if (flags.fl == 1) {
            boucle_fl(directory_struct);
        } else {
            write(STDOUT_FILENO, directory_struct->d_name, lend);
            write(STDOUT_FILENO, " ", 1);
        }
    }
}

int my_ls(int argc, char *argv[])
{
    DIR *directory;
    struct dirent *directory_struct;
    Flags_d flags = {0, 0};
    int path_index;

    path_index = boucle_argv(argc, argv, &flags);
    if (path_index == 0) {
        directory = opendir(".");
    } else {
        directory = opendir(argv[path_index]);
    }
    if (directory == NULL) {
        perror("Pas de répertoire");
        return 1;
    }
    directory_struct = readdir(directory);
    while (directory_struct != NULL) {
        structa(directory_struct, flags, directory);
        directory_struct = readdir(directory);
    }
    closedir(directory);
    return 0;
}
