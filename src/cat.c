/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** cat_power
*/

#include "../includes/hunter.h"
#include <stdio.h>
#include <stdlib.h>

void clock_cat(r_catpower *cat, r_score *score)
{
    float speed = 0.050;
    sfTime time = sfClock_getElapsedTime(cat->clock);
    float seconds = time.microseconds / 1000000.0;
    if (score->score_rec.left % 100 == 0)
        speed = speed - 0.035;
    sfSprite_setPosition(cat->cat_spr, cat->position);
    if (seconds > speed) {
        cat->position.x += 10;
        if (cat->position.x >= 2050) {
            cat->position.x = -200;
            sfSprite_setPosition(cat->cat_spr, cat->position);
        }
        move_rect(&cat->cat_rec, 110, 1100);
        sfSprite_setScale(cat->cat_spr, cat->size);
        sfSprite_setTextureRect(cat->cat_spr, cat->cat_rec);
        sfClock_restart(cat->clock);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void set_cat(r_catpower *cat)
{
    cat->size.x = 1.3;
    cat->size.y = 1.3;
    cat->position.x = -200;
    cat->position.y = 500;
    cat->cat_rec.top = 0;
    cat->cat_rec.left = 0;
    cat->cat_rec.width = 91;
    cat->cat_rec.height = 110;
}

void create_cat(r_catpower *cat)
{
    cat->cat_tex = sfTexture_createFromFile("img/cat.png", NULL);
    cat->cat_spr = sfSprite_create();
    sfSprite_setTexture(cat->cat_spr, cat->cat_tex, sfTrue);
    set_cat(cat);
}

void create_winner(r_catpower *cat)
{
    cat->win_txt = sfTexture_createFromFile("img/winnerr.png", NULL);
    cat->win_spr = sfSprite_create();
    sfSprite_setTexture(cat->win_spr, cat->win_txt, sfTrue);
}
