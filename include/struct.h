/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** struct
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct audio{
        sfMusic *music;
    }audio_t;

    typedef struct {
        sfVideoMode video_mode;
        sfRenderWindow *window;
        sfEvent event;
        int height;
        int width;
    } window_t;

    typedef struct sprite {
        sfTexture* texture;
        sfSprite* sprite;
        sfVector2f scale;
        sfVector2f pos;
        sfIntRect rect;
        int display;
        int delay;
        int set;
        int life;
        int type;
    } sprite_t;

    typedef struct text {
        sfText *text;
        sfFont *font;
        sfColor color;
        sfVector2f scale;
        sfVector2f pos;
    } text_t;

    typedef struct {
        sprite_t bg;
        text_t t_title;
        sprite_t *buttons;
        audio_t *soundtrack;
    } menu_t;

    typedef struct {
        window_t settings;
        sprite_t story_bg;
        sprite_t transition_bg;
        sprite_t bloc_text;
        sprite_t boy;
        sprite_t bg;
        sprite_t player;
        sprite_t *m1;
        sprite_t *m2;
        sprite_t *m3;
        sprite_t *m4;
        sprite_t *m5;
        sprite_t pv;
        text_t skip;
        audio_t *gun_sound;
        int set;
        int level;
        int kills;
    } struct_t;

#endif /* !STRUCT_H_ */
