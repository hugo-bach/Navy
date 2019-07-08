/*
** EPITECH PROJECT, 2018
** my_navy.h
** File description:
** header of my project navy
*/

#ifndef MY_NAVY
#define MY_NAVY

#define READ_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <criterion/criterion.h>
#include <signal.h>

typedef struct navy_t
{
    pid_t my_pid;
    pid_t pid_error;
    int x;
    int y;
    int status;
} navy_t;

char *my_calloc(int);
char *copy(char *, char *);
char *error(int, char *, char *, int);
char *line(int, char **, char *, int);
char *get_next_line(int);
int error_handling(char **, int);
void info(void);
char **my_strcalloc(int);
char **generate_map(char **);
void display_map(char **, int);
int my_strlen(char *);
int error_check_boat(char **, char *);
void my_free_str(char **);
void my_free(char *);
int player_one(char **);
void my_put_nbr(int);
char **fill_map(void);
void error_pid(int, siginfo_t *, void *);
void my_getpid(int, siginfo_t *, void *);
int player_two(char **, int);
int my_getnbr(char *);
void fill_sig(struct sigaction *);
int count_boat(char **);
char *error_input(char **);
int send_signal(char *);
int player_game(char **, char **);
void receive_signal(void);
void check_signal(char *);
void check_point(char **);
void check_point_two(char **, char *);
void p(char *);

#endif
