/*
** Global Game Jam PROJECT, 2023
** creation_of_main_window.c
** File description:
** Create the main window of the game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/my.h"
#include <stdio.h>
#include <math.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include "../include/struct.h"
#include <unistd.h> 

void ini_sounds(menu_t *menu)
{
    menu->soundtrack = malloc(sizeof(audio_t) * 1);
    menu->soundtrack[0].music = sfMusic_createFromFile("sounds/hub_music.ogg");

    sfMusic_play(menu->soundtrack[0].music);
    sfMusic_setLoop(menu->soundtrack[0].music, sfTrue);
    return;
}

void ini_sounds_gun(struct_t *all)
{
    all->gun_sound = malloc(sizeof(audio_t) * 2);
    all->gun_sound[0].music = sfMusic_createFromFile("sounds/gun_shoot.ogg");
    all->gun_sound[1].music = sfMusic_createFromFile("sounds/game_music.ogg");
    //sfMusic_play(all->gun_sound[1].music);
    return;
}

//if (sfMusic_getStatus(bh_all->aud_settings[0].music) == sfStopped)
    //sfMusic_play(bh_all->aud_settings[0].music);

//sfMusic_stop(bh_all->aud_settings[0].music);
