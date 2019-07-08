/*
** EPITECH PROJECT, 2018
** player_one.c
** File description:
** fct who treat all fct for player one
*/

#include "my_navy.h"

extern navy_t my_navy;

void fill_sig(struct sigaction *sig)
{
    my_navy.my_pid = 0;
    sig->sa_sigaction = &my_getpid;
    sig->sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, sig, NULL);
    pause();
}

int player_game(char **map, char **maptwo)
{
    char *result = NULL;

    while (count_boat(map) != 14 && count_boat(maptwo) != 14) {
        (1) ? display_map(map, 0), display_map(maptwo, 1) : 0;
        result = error_input(maptwo);
        if (result == NULL)
            return (0);
        if (send_signal(result) == -1)
            return (84);
        (1) ? check_signal(result), check_point_two(maptwo, result) : 0;
        if (count_boat(map) == 14 || count_boat(maptwo) == 14)
            break;
        write(1, "waiting for enemy's attack...\n", 30);
        (count_boat(map) != 14 && count_boat(maptwo) != 14) ? pause() : 0;
        (1) ? receive_signal(), usleep(10000), check_point(map) : 0;
    }
    (1) ? display_map(map, 0), display_map(maptwo, 1) : 0;
    (count_boat(map) == 14) ? p("Enemy won\n\n") : p("I won\n\n");
    return (count_boat(map) == 14 ? 1 : 0);
}

int player_one(char **map)
{
    struct sigaction sig;
    char **maptwo = fill_map();

    write(1, "my_pid:\t", 8);
    my_put_nbr(getpid());
    write(1, "\nwaiting for enemy connection...\n", 33);
    fill_sig(&sig);
    while (my_navy.my_pid == 0);
    usleep(10000);
    while (kill(my_navy.my_pid, SIGUSR1) == -1);
    write(1, "\nenemy connected\n\n", 18);
    return (player_game(map, maptwo));
}
