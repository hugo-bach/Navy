/*
** EPITECH PROJECT, 2018
** check_signal.c
** File description:
** fct who check the signal
*/

#include "my_navy.h"

extern navy_t my_navy;

void handler_one(int sig, siginfo_t *info, void *ucontext)
{
    my_navy.status = -1;
}

void handler_two(int sig, siginfo_t *info, void *ucontext)
{
    my_navy.status = -2;
}

void print_status(char *result)
{
    write(1, result, 2);
    if (my_navy.status == -1)
        write(1, ": hit\n", 6);
    else
        write(1, ": missed\n", 9);
    write(1, "\n", 1);
}

void check_signal(char *result)
{
    struct sigaction sigone;
    struct sigaction sigtwo;

    sigone.sa_sigaction = &handler_one;
    sigtwo.sa_sigaction = &handler_two;
    sigone.sa_flags = SA_SIGINFO;
    sigtwo.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigone, NULL);
    sigaction(SIGUSR2, &sigtwo, NULL);
    pause();
    print_status(result);
}
