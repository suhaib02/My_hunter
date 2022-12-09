/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** open_win
*/

#include "../includes/hunter.h"
#include <stdlib.h>
#include <stdio.h>

int close_win(r_win *wind, sfEvent event)
{
    while (sfRenderWindow_pollEvent(wind->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(wind->window);
            return 1;
        }
    }
    return 0;
}

int quit_game(r_win *wind, sfEvent event)
{
    while (sfRenderWindow_pollEvent(wind->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(wind->window);
            return 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            return 1;
    }
    return 0;
}

void tools_urg(r_box *box)
{
    if (box->score_r->score_rec.left == 1600) {
        sfRenderWindow_drawSprite(box->win_r->window, box->cat_r->win_spr,
            NULL);
        box->cat_r->position.x = -200;
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            sfMusic_stop(box->win_r->music);
            loop_game(box);
        }
    }
}

void loop_game(r_box *box)
{
    sfEvent event;
    box->cat_r->clock = sfClock_create();
    box->backg_r->clock = sfClock_create();
    tools(box);
    while (quit_game(box->win_r, event) != 1) {
        sfRenderWindow_clear(box->win_r->window, sfBlack);
        draw_game(box);
        clock_city(box->backg_r);
        clock_cat(box->cat_r, box->score_r);
        close_win(box->win_r, event);
        get_mouse(box->cat_r, box->win_r, box->mouse_r, box->score_r);
        if (box->score_r->score_rec.left == 1494) {
            sfRenderWindow_drawSprite(box->win_r->window,
                box->cat_r->levelup_spr, NULL);
        }
        tools_urg(box);
        sfRenderWindow_display(box->win_r->window);
    }
    sfMusic_destroy(box->win_r->music);
}

int open_a_window(r_box *box)
{
    sfEvent event;
    if (!box->win_r)
        return 84;
    box->menu_r->let_clock = sfClock_create();
    box->menu_r->cat_menu_clock = sfClock_create();
    handle_window(box->win_r);
    create_bgmenu(box->menu_r);
    create_let_chase_the_cat(box->menu_r);
    create_cat_menu(box->menu_r);
    while (sfRenderWindow_isOpen(box->win_r->window)) {
        clock_let(box->menu_r);
        clock_cat_menu(box->menu_r);
        sfRenderWindow_display(box->win_r->window);
        draw_win(box);
        close_win(box->win_r, event);
        if (sfKeyboard_isKeyPressed(sfKeyEnter))
            loop_game(box);
    }
    return 0;
}
