/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-suhaib.selmi
** File description:
** menu
*/

#include "../includes/hunter.h"
#include <stdio.h>



void create_bgmenu(r_menu *menu)
{
    menu->menu_txt = sfTexture_createFromFile("img/catcat.png", NULL);
    menu->menu_spr = sfSprite_create();
    sfSprite_setTexture(menu->menu_spr, menu->menu_txt, sfTrue);
}

void clock_let(r_menu *menu)
{
    sfTime time = sfClock_getElapsedTime(menu->let_clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.045) {
        menu->let_pos.x += 3;
        sfSprite_setPosition(menu->let_spr, menu->let_pos);
        if (menu->let_pos.x == 426) {
            menu->let_pos.x -= 6;
            sfSprite_setPosition(menu->let_spr, menu->let_pos);
        }
        sfClock_restart(menu->let_clock);
    }

}

void create_let_chase_the_cat(r_menu *menu)
{
    menu->let_pos.x = 417;
    menu->let_pos.y = 40;
    menu->let_txt = sfTexture_createFromFile("img/let_chase_the_cat.png", NULL);
    menu->let_spr = sfSprite_create();
    sfSprite_setPosition(menu->let_spr, menu->let_pos);
    sfSprite_setTexture(menu->let_spr, menu->let_txt, sfTrue);
}
