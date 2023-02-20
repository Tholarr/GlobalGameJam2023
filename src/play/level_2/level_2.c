/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** level_1
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

void draw_level_2(struct_t *all, sfRenderWindow *win, sprite_t *script)
{
    sfRenderWindow_drawSprite(win, all->bg.sprite, NULL);

    if (all->kills == 0) {
        sfRenderWindow_drawSprite(win, script[0].sprite, NULL);
        sfRenderWindow_drawSprite(win, script[1].sprite, NULL);
        script[0].display = 1;
        script[1].display = 1;
        script[0].delay = 1;
        script[1].delay = 1;
    }

    for (int i = 0; i < 5; i++) {
        if (all->kills == 1 && script[i].life != 0 && i != 5 && i != 4) {
            sfRenderWindow_drawSprite(win, script[i].sprite, NULL);
            script[i].display = 1;
            script[i].delay = 1;
        }
        if (all->kills > 1 && script[i].life != 0 && i != 5) {
            sfRenderWindow_drawSprite(win, script[i].sprite, NULL);
            script[i].display = 1;
            script[i].delay = 1;
        }
        if (all->kills > 2 && script[i].life != 0) {
            sfRenderWindow_drawSprite(win, script[i].sprite, NULL);
            script[i].display = 1;
            script[i].delay = 1;
        }
    }
    sfRenderWindow_drawSprite(win, all->player.sprite, NULL);
    sfRenderWindow_drawSprite(win, all->pv.sprite, NULL);
}

void manage2(struct_t *all, sfEvent *event, sfRenderWindow *win, sprite_t *script)
{
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeySpace) {
        for (int i = 0; i < 5; i++) {
            if (all->player.pos.x == script[i].pos.x && script[i].life != 0 && script[i].display == 1) {
                script[i].life = 0;
                script[i].display = 0;
                script[i].delay = 0;
                all->kills++;
            }
        }
    }
}

void level_2(struct_t *all, sfEvent *event)
{
    void transition(struct_t *all);

    sprite_t script[5];
    script[0] = init_m1(2);
    script[1] = init_m2(1);
    script[2] = init_m1(3);
    script[3] = init_m2(2);
    script[4] = init_m2(1);

    all->kills = 0;
    sfClock *clock = sfClock_create();

    while (all->set == 3 && all->level == 2) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);

        draw_level_2(all, WIN, script);
        anim_monsters2(all, WIN, script, clock);

        if (all->kills == 5)
            all->level = -3;

        if (all->player.life < 1)
            all->set = 1;

        while (sfRenderWindow_pollEvent(WIN, event)) {
            game_manage_events(all, event, WIN);
            manage2(all, event, WIN, script);
        }
    }
    sfClock_destroy(clock);
    for (int i = 0; i < 5; i++) {
        sfSprite_destroy(script[i].sprite);
        sfTexture_destroy(script[i].texture);
    }
}