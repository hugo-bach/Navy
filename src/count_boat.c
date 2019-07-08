/*
** EPITECH PROJECT, 2018
** count_boat.c
** File description:
** fct who count number of boat
*/

#include "my_navy.h"

static int check_boat(char c)
{
    if (c == 'x')
        return (1);
    return (0);
}

int count_boat(char **map)
{
    int nb = 0;

    for (int i = 0; map[i]; i++)
        for (int y = 0; map[i][y]; y++)
            nb += check_boat(map[i][y]);
    return (nb);
}
