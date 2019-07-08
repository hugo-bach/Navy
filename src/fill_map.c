/*
** EPITECH PROJECT, 2018
** fill_map.c
** File description:
** fct who fill map
*/

#include "my_navy.h"

extern navy_t my_navy;

void check_point(char **map)
{
    char c = my_navy.x + 65;
    int y = my_navy.y;
    int x = my_navy.x;

    write(1, &c, 1);
    if (map[y][x] == '2' || map[y][x] == '3' || map[y][x] == '4' || map[y][x] ==
        '5') {
        map[y][x] = 'x';
        kill(my_navy.my_pid, SIGUSR1);
        usleep(10000);
        my_put_nbr(my_navy.y + 1);
        write(1, ":\thit\n", 6);
    } else {
        (map[y][x] == '.') ? map[y][x] = 'o' : 0;
        kill (my_navy.my_pid, SIGUSR2);
        usleep(10000);
        my_put_nbr(my_navy.y + 1);
        write(1, ":\tmissed\n", 9);
    }
    write(1, "\n", 1);
}
