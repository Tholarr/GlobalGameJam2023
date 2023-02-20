/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** game
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <unistd.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void draw_game(struct_t *all, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, all->bg.sprite, NULL);
    sfRenderWindow_drawSprite(win, all->player.sprite, NULL);
}

void gun_anim(struct_t *all, sfRenderWindow *win)
{
    sfMusic_play(all->gun_sound[0].music);
    sleep(0.5);
    all->player.rect.left = 18;
    sfSprite_setTextureRect(all->player.sprite, all->player.rect);
    sfRenderWindow_drawSprite(win, all->player.sprite, NULL);
    for (int delay = 0; delay < 1000; delay++);
    all->player.rect.left = 36;
    sfSprite_setTextureRect(all->player.sprite, all->player.rect);
    sfRenderWindow_drawSprite(win, all->player.sprite, NULL);
    for (int delay = 0; delay < 10000; delay++);
    all->player.rect.left = 0;
    sfSprite_setTextureRect(all->player.sprite, all->player.rect);
    sfRenderWindow_drawSprite(win, all->player.sprite, NULL);
}

void game_manage_events(struct_t *all, sfEvent *event, sfRenderWindow *win)
{
    if (event->type == sfEvtClosed) {
        all->set = 0;
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyRight) {
        if (all->player.pos.x == 682)
            all->player.pos.x = 891;
        if (all->player.pos.x == 419)
            all->player.pos.x = 682;
        sfSprite_setPosition(all->player.sprite, all->player.pos);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyLeft) {
        if (all->player.pos.x == 682)
            all->player.pos.x = 419;
        if (all->player.pos.x == 891)
            all->player.pos.x = 682;
        sfSprite_setPosition(all->player.sprite, all->player.pos);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeySpace) {
        sfMusic_stop(all->gun_sound[0].music);
        gun_anim(all, win);
    }
}

void play_game(struct_t *all, sfEvent *event)
{
    init_game(all);
    all->level = 1;
    while (all->set == 3) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);

        switch (all->level) {
            case 1: level_1(all, event); break;
            case -2: transition2(all); break;
            case 2: level_2(all, event); break;
            case -3: transition3(all); break;
            case 3: level_3(all, event); break;
            case -4: transition4(all); break;
            case 4: level_4(all, event); break;
            case -5: transition5(all); break;
            case 5: level_5(all, event); break;
            case -6: transitionEnd(all); break;
            case -7: transitionEnd2(all); break;
            case -8: end_story(all); break;
            case -9: all->set = 1; return;
        }
    }
}
