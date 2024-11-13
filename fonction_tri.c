/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-myls-pierre.baud
** File description:
** fonction_tri
*/


int fonction_compare(const char *a, const char *b)
{
    char char_a;
    char char_b;

    while (*a != '\0' && *b != '\0') {
        char_a = *a;
        char_b = *b;
        if (char_a >= 'a' && char_a <= 'z') {
            char_a = char_a - 'a' + 'A' - 0.5;
        }
        if (char_b >= 'a' && char_b <= 'z') {
            char_b = char_b - 'a' + 'A' - 0.5;
        }
        if (char_a != char_b) {
            return char_a - char_b;
        }
        a++;
        b++;
    }
    return *a - *b;
}

void fonction_tri(char **arr, int n)
{
    char *key;
    int i = 0;
    int j = 0;

    for (i; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && fonction_compare(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
