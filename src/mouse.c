/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** mouse
*/

#include "../includes/hunter.h"
#include <stdio.h>
#include <stdlib.h>

void create_mouse(r_win *wind, r_mouse *mouse)
{
    sfRenderWindow_setMouseCursorVisible(wind->window, sfFalse);
    mouse->mouse_txt = sfTexture_createFromFile("img/cible.png", NULL);
    mouse->mouse_spr = sfSprite_create();
}

int level_up(r_score *score, r_catpower *cat, r_win *wind)
{
    if (score->score_rec.left == 1494)
        sfRenderWindow_drawSprite(wind->window, cat->cat_spr,
            NULL);
    if (score->score_rec.left == 1594)
        score->score_rec.left = 0;
    if (score->score_rec.left == 0)
        return 1;
    return 0;
}

int get_mouse(r_catpower *cat, r_win *wind, r_mouse *mouse, r_score *score)
{
    int max_x_cat = cat->position.x, max_y_cat = cat->position.y;
    int max_y_mouse = mouse->mouse_pos_i.y - 80;
    int max_x_mouse = mouse->mouse_pos_i.x;
    create_mouse(wind, mouse);
    sfSprite_setTexture(mouse->mouse_spr, mouse->mouse_txt, sfTrue);
    mouse->mouse_pos_i = sfMouse_getPosition(wind->wond);
    mouse->mouse_pos.x = mouse->mouse_pos_i.x - 45;
    mouse->mouse_pos.y = mouse->mouse_pos_i.y - 95;
    sfSprite_setPosition(mouse->mouse_spr, mouse->mouse_pos);
    sfRenderWindow_drawSprite(wind->window, mouse->mouse_spr, NULL);
        if (max_y_mouse >= max_y_cat && max_y_mouse <= max_y_cat + 80
            && max_x_mouse >= max_x_cat && max_x_mouse <= max_x_cat + 145
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            cat->position.x -= cat->position.x + 200;
            cat->position.y = rand() % 700;
            score->score_rec.left += 100;
            sfSprite_setTextureRect(score->score_spr, score->score_rec);
            level_up(score, cat, wind);
        }
    return 0;
}
