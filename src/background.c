/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** background
*/

#include "../includes/hunter.h"
#include <stdio.h>

void handle_window(r_win *wind)
{
    wind->mode.height = 1080;
    wind->mode.width = 1920;
    wind->mode.bitsPerPixel = 32;
    wind->window = sfRenderWindow_create(wind->mode, "MyHunter",
        sfDefaultStyle, NULL);
}

void set_posotion_city(r_backg *city)
{
    city->position.x = -10;
    city->position.y = -50;
}

void creat_background(r_backg *city)
{
    city->city_tex = sfTexture_createFromFile("img/night.png", NULL);
    city->city_spr = sfSprite_create();
    set_posotion_city(city);
    sfSprite_setPosition(city->city_spr, city->position);
    sfSprite_setTexture(city->city_spr, city->city_tex, sfTrue);
    set_posotion_city(city);
}

void clock_city(r_backg *city)
{
    sfTime time = sfClock_getElapsedTime(city->clock);
    float seconds = time.microseconds / 1000000.0;
    sfSprite_setPosition(city->city_spr, city->position);
    if (seconds > 0.04) {
        city->position.x -= 2;
        if (city->position.x <= -1919) {
            city->position.x = 0;
            sfSprite_setPosition(city->city_spr, city->position);
        }

        sfSprite_setTexture(city->city_spr, city->city_tex, sfTrue);
        sfClock_restart(city->clock);
    }
}
