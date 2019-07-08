/*
** EPITECH PROJECT, 2018
** player_two.c
** File description:
** all fct who treat the player 2
*/

#include "my_navy.h"

extern navy_t my_navy;

void p(char *str)
{
    write(1, str, my_strlen(str));
}

int player_game_two(char **map, char **maptwo)
{
    char *result = NULL;

    while (count_boat(map) != 14 && count_boat(maptwo) != 14) {
        (1) ? display_map(map, 0), display_map(maptwo, 1) : 0;
        write(1, "waiting for enemy's attack...\n", 30);
        (count_boat(map) != 14 && count_boat(maptwo) != 14) ? pause() : 0;
        (1) ? receive_signal(), usleep(10000), check_point(map) : 0;
        if (count_boat(map) == 14 || count_boat(maptwo) == 14)
            break;
        result = error_input(maptwo);
        if (result == NULL)
            return (0);
        if (send_signal(result) == -1)
            return (84);
        (1) ? check_signal(result), check_point_two(maptwo, result) : 0;
    }
    (1) ? display_map(map, 0), display_map(maptwo, 1) : 0;
    (count_boat(map) == 14) ? p("Enemy won\n\n") : p("I won\n\n");
    return (count_boat(map) == 14 ? 1 : 0);
}

int player_two(char **map, int pid)
{
    struct sigaction sig;
    char **maptwo = fill_map();

    write(1, "my_pid:\t", 8);
    my_put_nbr(getpid());
    write(1, "\n", 1);
    if (kill(pid, SIGUSR1) == -1)
        return (84);
    fill_sig(&sig);
    while (my_navy.my_pid == 0 && my_navy.my_pid != pid);
    write(1, "successfully connected\n\n", 24);
    return (player_game_two(map, maptwo));
}
