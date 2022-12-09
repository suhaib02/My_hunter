/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** sound
*/

#include "../includes/hunter.h"
#include <SFML/Audio.h>

void create_music(r_win *sing)
{
    sing->music = sfMusic_createFromFile("sound/Fallen.ogg");
    sfMusic_setLoop(sing->music, sfTrue);
    sfMusic_setVolume(sing->music, 20);
    sfMusic_play(sing->music);
}
// sfMusic_destroy(sing->music);
