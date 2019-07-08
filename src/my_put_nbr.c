/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** write a number
*/

#include "my_navy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    int pow = 1;
    int nbcpy = nb;
    int lon = 0;

    while (nbcpy > 9) {
        pow = pow * 10;
        nbcpy = nbcpy / 10;
        lon = lon + 1;
    }
    while (lon > 0) {
        my_putchar((nb / pow) + 48);
        nb = nb % pow;
        pow = pow / 10;
        lon = lon - 1;
    }
    my_putchar(nb + '0');
}
