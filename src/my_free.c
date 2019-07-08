/*
** EPITECH PROJECT, 2018
** my_free.c
** File description:
** fct who free all
*/

#include "my_navy.h"

void my_free_str(char **str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i]; i++)
        free (str[i]);
    free (str);
}

void my_free(char *str)
{
    if (str == NULL)
        return;
    free (str);
}
