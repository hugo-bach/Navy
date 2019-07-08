/*
** EPITECH PROJECT, 2018
** set_point.c
** File description:
** fct who set a point on a map
*/

#include "my_navy.h"

extern navy_t my_navy;

void check_point_two(char **map_two, char *result)
{
    int x = result[0] - 65;
    int y = result[1] - 49;

    if (my_navy.status == -1)
        map_two[y][x] = 'x';
    else if (map_two[y][x] != 'x')
        map_two[y][x] = 'o';
}
