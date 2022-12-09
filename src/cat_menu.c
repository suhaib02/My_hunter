/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-suhaib.selmi
** File description:
** cat_menu
*/

#include "../includes/hunter.h"
#include <stdio.h>

void create_cat_menu(r_menu *menu)
{
    menu->cat_menu_pos.x = 1700;
    menu->cat_menu_pos.y = 700;
    menu->cat_menu_txt = sfTexture_createFromFile("img/supercat.png", NULL);
    menu->cat_menu_spr = sfSprite_create();
    sfSprite_setPosition(menu->cat_menu_spr, menu->cat_menu_pos);
    sfSprite_setTexture(menu->cat_menu_spr, menu->cat_menu_txt, sfTrue);
}

void clock_cat_menu(r_menu *menu)
{
    sfTime time = sfClock_getElapsedTime(menu->cat_menu_clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.03) {
        menu->cat_menu_pos.x -= 3;
        menu->cat_menu_pos.y -= 3;
        if (menu->cat_menu_pos.y < 300)
            menu->cat_menu_pos.x -= 3;
        if (menu->cat_menu_pos.y < 10) {
            menu->cat_menu_pos.y += 3;
            menu->cat_menu_pos.x += 3;
        }
        sfSprite_setPosition(menu->cat_menu_spr, menu->cat_menu_pos);
        sfClock_restart(menu->cat_menu_clock);
    }
}
//menu->let_pos.y -= 3;
