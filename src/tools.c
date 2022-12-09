/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** tools
*/

#include "../includes/my.h"
#include "../includes/hunter.h"
#include <stdlib.h>

void tools(r_box *box)
{
    creat_background(box->backg_r);
    create_cat(box->cat_r);
    create_score(box->score_r);
    create_music(box->win_r);
    create_winner(box->cat_r);
    create_levelup(box->cat_r);
}

int print_usage(char **help)
{
    if (help[1][0] == '-' && help[1][1] == 'h') {
        my_putstr("\nMy_hunter is a shooting game created by SS corporate.\n");
        my_putstr("The goal is to shoot a flying cat to get ");
        my_putstr("maximum points.\n\nUSAGE\n\t./my_hunter\n\n");
        my_putstr("I hope you like this game\n");
        my_putstr("Good luck.\n\n");
        return 0;
    }
    return 1;
}

int program(int c, char **v)
{
    r_box *box = malloc(sizeof(r_box));
    box->win_r = malloc(sizeof(r_win));
    box->backg_r = malloc(sizeof(r_backg));
    box->cat_r = malloc(sizeof(r_catpower));
    box->mouse_r = malloc(sizeof(r_mouse));
    box->score_r = malloc(sizeof(r_score));
    box->menu_r = malloc(sizeof(r_menu));
    if (c == 1) {
        open_a_window(box);
        sfRenderWindow_destroy(box->win_r->window);
        free(box);
        return 0;
    }
    if (print_usage(v) == 0) {
        return 0;
    }
    if (c > 2)
        return 84;
    return 0;
}
