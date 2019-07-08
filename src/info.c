/*
** EPITECH PROJECT, 2018
** info.c
** File description:
** fct who display info
*/

#include "my_navy.h"

void info(void)
{
    write(1, "USAGE\n", 6);
    write(1, "     ./navy [first_player_pid] navy_positions\n", 46);
    write(1, "DESCRIPTION\n", 12);
    write(1, "     first_player_pid:  only for the 2nd player.", 48);
    write(1, "  pid of the first player.\n", 27);
    write(1, "     navy_positions:  file representing the positions of", 56);
    write(1, " the ships.\n", 12);
}
