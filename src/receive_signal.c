/*
** EPITECH PROJECT, 2018
** receive_signal.c
** File description:
** fct who receive and treat signal
*/

#include "my_navy.h"

extern navy_t my_navy;

void set_navy(void)
{
    my_navy.status = 0;
    my_navy.y = -1;
    my_navy.x = 0;
}

void handler_sig_two(int sig, siginfo_t *info, void *ucontext)
{
    my_navy.status += 1;
}

void handler_sig_one(int sig, siginfo_t *info, void *ucontext)
{
    if (info->si_pid != my_navy.my_pid)
        return;
    if (my_navy.status == 0)
        my_navy.x += 1;
    if (my_navy.status == 1)
        my_navy.y += 1;
}

void receive_signal(void)
{
    struct sigaction sigone;
    struct sigaction sigtwo;

    set_navy();
    sigone.sa_sigaction = &handler_sig_one;
    sigone.sa_flags = SA_SIGINFO;
    sigtwo.sa_sigaction = &handler_sig_two;
    sigtwo.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigone, NULL);
    sigaction(SIGUSR2, &sigtwo, NULL);
    while (my_navy.status != 2)
        pause();
}
