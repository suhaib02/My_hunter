/*
** EPITECH PROJECT, 2022
** day04
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    if (str == NULL) {
        write(0, "(null)", 6);
        return 84;
    }

    int i = 0;
    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
