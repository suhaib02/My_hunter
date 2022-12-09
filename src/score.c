/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-suhaib.selmi
** File description:
** score
*/

#include "../includes/hunter.h"
#include <stdio.h>

void set_score(r_score *score)
{
    score->score_pos.x = 1750;
    score->score_pos.y = 80;
    score->score_rec.top = 0;
    score->score_rec.left = -6;
    score->score_rec.width = 90;
    score->score_rec.height = 110;
}

void create_score(r_score *score)
{
    score->score_txt = sfTexture_createFromFile("img/score.png", NULL);
    score->score_spr = sfSprite_create();
    sfSprite_setTexture(score->score_spr, score->score_txt, sfTrue);
    set_score(score);
    sfSprite_setPosition(score->score_spr, score->score_pos);
    sfSprite_setTextureRect(score->score_spr, score->score_rec);
}
