/*
** EPITECH PROJECT, 2018
** handler_pl_one.c
** File description:
** fct who treat all handler of player one
*/

#include "my_navy.h"

extern navy_t my_navy;

void my_getpid(int sig, siginfo_t *info, void *ucontext)
{
    my_navy.my_pid = info->si_pid;
}

void error_pid(int sig, siginfo_t *info, void *ucontext)
{
    my_navy.pid_error = info->si_pid;
}
