/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** fct principal of my projet navy
*/

#include "my_navy.h"

struct navy_t my_navy;

int count_file(char *str)
{
    int fd = open(str, O_RDONLY);
    int i = 0;

    if (fd == -1)
        return (-1);
    for (; get_next_line(fd) != NULL; i++);
    close(fd);
    return (i);
}

int main(int ac, char **av)
{
    char **str;
    char **map;
    int error = 84;
    int fd = 0;

    if (ac == 1 || ac > 3 || (error = error_handling(av, ac)) != 1)
        return (error);
    if ((fd = count_file(av[ac - 1])) != -1)
        str = my_strcalloc(fd);
    if (fd == -1 || error_check_boat(str, av[ac - 1]) == -1)
        return (84);
    map = generate_map(str);
    if (map == NULL)
        return (84);
    fd = (ac == 2) ? player_one(map) : player_two(map, my_getnbr(av[1]));
    (1) ? my_free_str(map), my_free_str(str) : 0;
    return (fd);
}
