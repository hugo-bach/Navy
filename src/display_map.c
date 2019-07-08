/*
** EPITECH PROJECT, 2018
** display_map.c
** File description:
** fct who display the map
*/

#include "my_navy.h"

static void display_space(int j)
{
    if (j != 7)
        write(1, " ", 1);
}

int my_strlen(char *str)
{
    int nb = 0;

    for (; str[nb]; nb++);
    return (nb);
}

void display_map(char **map, int statut)
{
    char *nb = my_calloc(1);

    if (statut == 0)
        write(1, "my positions:\n", 14);
    else
        write(1, "enemy's positions:\n", 19);
    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int i = 0; map[i]; i++) {
        nb[0] = i + 49;
        write(1, nb, 1);
        write(1, "|", 1);
        for (int j = 0; map[i][j]; j++) {
            write(1, &map[i][j], 1);
            display_space(j);
        }
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}
