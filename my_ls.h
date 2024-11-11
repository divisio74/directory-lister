/*
** EPITECH PROJECT, 2024
** B-CPE-101-LYN-1-1-myls-pierre.baud
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef MY_LS_H
    #define MY_LS_H

int my_ls(int argc, char **argv);
int my_strlen(char const *str);
int my_strcmp(char *s1, char *s2);
void print_l(const char *nom_fichier, struct stat *datafiles);
void afficher_date(time_t mtime);
void print_prop(uid_t uid);
void print_t(long int taille);
void print_hardlink_count(long int hardlinks);
void print_perm(mode_t mode);
void print_group(gid_t gid);
int boucle_fl(struct dirent *directory_struct);

#endif
