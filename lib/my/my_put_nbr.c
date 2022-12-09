/*
** EPITECH PROJECT, 2022
** day03
** File description:
** put_nbr
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 10 != 0)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return 0;
}
