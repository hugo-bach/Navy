/*
** EPITECH PROJECT, 2018
** send_signal.c
** File description:
** fct who send signal
*/

#include "my_navy.h"

extern navy_t my_navy;

int send_signal(char *str)
{
    int x = str[0] - 64;
    int y = str[1] - 48;

    for (int i = 0; i < x; i++) {
        if (kill(my_navy.my_pid, SIGUSR1) == -1)
            return (-1);
        usleep(10000);
    }
    if (kill(my_navy.my_pid, SIGUSR2) == -1)
        return (-1);
    usleep(10000);
    for (int i = 0; i < y; i++) {
        if (kill(my_navy.my_pid, SIGUSR1) == -1)
            return (-1);
        usleep(10000);
    }
    if (kill(my_navy.my_pid, SIGUSR2) == -1)
        return (-1);
    usleep(10000);
    return (0);
}
