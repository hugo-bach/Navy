/*
** EPITECH PROJECT, 2018
** my_get_nbr.c
** File description:
** fct get the number in the string
*/

#include "my_navy.h"

int my_getnbr(char *str)
{
    int result = 0;
    int count = 0;
    int statut = 0;

    for (int i = 0; (str[i] >= '0' && str[i] <= '9') || str[i] == '-' ||
        str[i] == '+'; i++) {
        (str[i] == '-' && statut == 0) ? count++ : 0;
        (str[i] == '+' && statut == 0) ? count = 0 : 0;
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - 48);
            statut = 1;
        }
        if (result < 0)
            return (0);
        if (statut == 1 && (str[i] < '0' || str[i] > '9'))
            return (0);
    }
    if (count % 2 == 1)
        result = -result;
    return (result);
}
