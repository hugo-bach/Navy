/*
** EPITECH PROJECT, 2018
** error_check input of my navy
** File description:
** check input of my navy
*/

#include "my_navy.h"

char *error_input(char **map)
{
    char *str;

    write(1, "attack:\t", 8);
    str = get_next_line(0);
    if (str == NULL)
        return (NULL);
    while ((my_strlen(str) != 2) || (str[0] < 65 || str[0] > 72) ||
        (str[1] < '1' || str[1] > '8')) {
        write(1, "wrong position\n", 15);
        write(1, "attack:\t", 8);
        str = get_next_line(0);
        if (str == NULL)
            return (NULL);
    }
    return (str);
}
