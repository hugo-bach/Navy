/*
** EPITECH PROJECT, 2018
** my_strcalloc.c
** File description:
** fct who return a char ** malloc fill with 0
*/

#include "my_navy.h"

char **my_strcalloc(int len)
{
    char **result = malloc(sizeof(char *) * (len + 1));

    for (int i = 0; i <= len; i++)
        result[i] = '\0';
    return (result);
}
