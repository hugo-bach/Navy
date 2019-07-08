/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** check error of initialise prog
*/

#include "my_navy.h"

int error_handling(char **av, int ac)
{
    int fd = 0;

    if (av[1][0] == '-' && av[1][1] == 'h') {
        info();
        return (0);
    }
    fd = open(av[ac - 1], O_RDONLY);
    if (fd == -1)
        return (84);
    return (1);
}
