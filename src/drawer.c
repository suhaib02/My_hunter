/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-suhaib.selmi
** File description:
** drawer
*/

#include "../includes/hunter.h"

void draw_game(r_box *box)
{
    sfRenderWindow_drawSprite(box->win_r->window, box->backg_r->city_spr,
        NULL);
    sfRenderWindow_drawSprite(box->win_r->window, box->cat_r->cat_spr,
        NULL);
    sfRenderWindow_drawSprite(box->win_r->window, box->score_r->score_spr,
        NULL);
}

void draw_win(r_box *box)
{
    sfRenderWindow_drawSprite(box->win_r->window, box->menu_r->menu_spr,
        NULL);
    sfRenderWindow_drawSprite(box->win_r->window, box->menu_r->let_spr,
        NULL);
    sfRenderWindow_drawSprite(box->win_r->window, box->menu_r->cat_menu_spr,
        NULL);
}

void create_levelup(r_catpower *cat)
{
    cat->levelup_position.x = 500;
    cat->levelup_position.y = 200;
    cat->levelup_txt = sfTexture_createFromFile("img/levelup.png", NULL);
    cat->levelup_spr = sfSprite_create();
    sfSprite_setPosition(cat->levelup_spr, cat->levelup_position);
    sfSprite_setTexture(cat->levelup_spr, cat->levelup_txt, sfTrue);
}
