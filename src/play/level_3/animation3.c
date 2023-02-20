/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** animation1
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
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../include/struct.h"
#include "../../../include/my.h"
#include "../../../include/define.h"

void anim_monsters3(struct_t *all, sfRenderWindow *win, sprite_t *script, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    sfSprite *hit = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("asset/backgrounds/hit.png", NULL);
    sfSprite_setTexture(hit, texture, sfTrue);

    if (seconds > 0.4 && seconds < 0.6) {
        for (int i = 0; i < 6; i++) {
            if (script[i].delay == 1) {
                if (script[i].type == 1)
                    script[i].rect.left = 9;
                if (script[i].type == 2)
                    script[i].rect.left = 13;
                if (script[i].type == 3)
                    script[i].rect.left = 14;
                sfSprite_setTextureRect(script[i].sprite, script[i].rect);
            }
        }
    }

    if (seconds > 1) {
        for (int i = 0; i < 6; i++) {
            if (script[i].delay == 1) {
                if (script[i].pos.y > 649) {
                    script[i].delay = 0;
                    all->player.life--;
                    if (all->player.life == 2)
                        all->pv.texture = sfTexture_createFromFile("asset/pv02.png", NULL);
                    if (all->player.life == 1)
                        all->pv.texture = sfTexture_createFromFile("asset/pv01.png", NULL);
                    if (all->player.life <= 0)
                        all->pv.texture = sfTexture_createFromFile("asset/pv00.png", NULL);
                    sfSprite_setTexture(all->pv.sprite, all->pv.texture, sfTrue);
                    sfRenderWindow_drawSprite(win, all->pv.sprite, NULL);
                    sfRenderWindow_drawSprite(win, hit, NULL);
                    sfRenderWindow_drawSprite(win, hit, NULL);
                    sfRenderWindow_drawSprite(win, hit, NULL);
                }
                if (script[i].pos.y > 609) {
                    script[i].pos.y = 650;
                    script[i].scale.x = 10.5;
                    script[i].scale.y = 10.5;
                }
                if (script[i].pos.y < 601) {
                    script[i].pos.y = 610;
                    script[i].scale.x = 9;
                    script[i].scale.y = 9;
                }
                sfSprite_setPosition(script[i].sprite, script[i].pos);
                sfSprite_setScale(script[i].sprite, script[i].scale);
                sfRenderWindow_drawSprite(win, script[i].sprite, NULL);
                script[i].rect.left = 0;
                sfSprite_setTextureRect(script[i].sprite, script[i].rect);
            }
        }
        sfClock_restart(clock);
    }
    sfSprite_destroy(hit);
    sfTexture_destroy(texture);
}
