/*
** EPITECH PROJECT, 2018
** generate_map.c
** File description:
** fct who generate the map
*/

#include "my_navy.h"

int fill_map_one(char *str, char **map)
{
    int error = 0;
    int begin = str[2] - 65;
    int b = str[3] - 48;
    int e = str[6] - 48;

    for (int i = b - 1; i != e;i++) {
        if (map[i][begin] != '.')
            return (-1);
        map[i][begin] = str[0];
    }
    return (0);
}

int fill_map_two(char *str, char **map)
{
    int error = 0;
    int begin = str[3] - 49;
    int b = str[2] - 65;
    int e = str[5] - 65;

    for (int i = b; i <= e; i++) {
        if (map[begin][i] != '.')
            return (-1);
        map[begin][i] = str[0];
    }
    return (0);
}

int generate_boat(char **str, char **map)
{
    int error = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i][2] == str[i][5])
            error = fill_map_one(str[i], map);
        else
            error = fill_map_two(str[i], map);
        if (error == -1)
            return (-1);
    }
    return (0);
}

char **fill_map(void)
{
    char **map = my_strcalloc(8);

    for (int i = 0; i < 8; i++) {
        map[i] = my_calloc(8);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    }
    return (map);
}

char **generate_map(char **str)
{
    int error = 0;
    char **map = fill_map();

    error = generate_boat(str, map);
    if (error == -1) {
        my_free_str(map);
        return (NULL);
    }
    return (map);
}
