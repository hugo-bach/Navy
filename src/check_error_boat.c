/*
** EPITECH PROJECT, 2018
** check_error_boat.c
** File description:
** all fct check error boat
*/

#include "my_navy.h"

int boat_error_next(char *str)
{
    if (str[3] == str[6])
        if (((str[5] - str[2]) + 1) != (str[0] - 48))
            return (-1);
    if ((str[2] != str[5]) && (str[3] != str[6]))
        return (-1);
    if ((str[3] < '1' || str[3] > '8') && (str[6] < '1' || str[6] > '8'))
        return (-1);
    return (0);
}

int boat_error(char *str)
{
    if (my_strlen(str) != 7)
        return (-1);
    if (str[0] < '2' || str[0] > '5')
        return (-1);
    if ((str[2] < 'A' || str[2] > 'H') && (str[5] < 'A' || str[5] > 'H'))
        return (-1);
    if (str[2] == str[5])
        if (((str[6] - str[3]) + 1) != (str[0] - 48))
            return (-1);
    return (boat_error_next(str));
}

int error_check_boat(char **str, char *file)
{
    int i = 0;
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return (-1);
    for (; (str[i] = get_next_line(fd)) != NULL; i++);
    if (i != 4)
        return (-1);
    for (int i = 0, j = 2; str[i]; i++, j++) {
        if (boat_error(str[i]) == -1)
            return (-1);
        if (str[i][2] > str[i][5])
            return (-1);
        if (str[i][3] > str[i][6])
            return (-1);
        if ((str[i][0] - 48) != j)
            return (-1);
    }
    close(fd);
    return (0);
}
