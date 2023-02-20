/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** transition2
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
#include <unistd.h>
#include "../../../include/struct.h"
#include "../../../include/my.h"
#include "../../../include/define.h"

void init_transitionEnd(struct_t *all)
{
    all->transition_bg.texture = sfTexture_createFromFile("asset/backgrounds/transition_bg.jpg", NULL);
    all->transition_bg.sprite = sfSprite_create();
    all->transition_bg.scale.x = 1.7;
    all->transition_bg.scale.y = 1.7;
    sfSprite_setTexture(all->transition_bg.sprite, all->transition_bg.texture, sfFalse);
    sfSprite_setScale(all->transition_bg.sprite, all->transition_bg.scale);

    all->boy.rect.top = 0;
    all->boy.rect.left = 0;
    all->boy.rect.width = 12;
    all->boy.rect.height = 17;
    all->boy.pos.x = 900;
    sfSprite_setPosition(all->boy.sprite, all->boy.pos);
    sfSprite_setTextureRect(all->boy.sprite, all->boy.rect);
}

void transitionEnd_display(struct_t *all, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("tty/prstart.ttf");
    sfVector2f pos = {50, 50};
    sfVector2f scale = {0.50, 0.50};
    sfColor color = sfColor_fromRGB(0, 0, 0);
    sfText_setColor(text, color);
    sfText_setScale(text, scale);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);

    if (seconds > 0.5 && seconds < 10) {
        sfText_setString(text, "Fighting his way through, he finally makes it to what seems to be\n\nthe root of this onslaught of monster, a small pond beneath desecrated roots.");
        sfRenderWindow_drawText(WIN, text, NULL);
    }
    if (seconds > 10) {
        sfText_setString(text, "Not knowing what to do but hearing the monsters close in the distance,\n\nit grips him that he must jump in the pond to escape them.");
        sfRenderWindow_drawText(WIN, text, NULL);
    }
    if (seconds > 18)
        all->level = -7;
}

void transitionEnd(struct_t *all)
{
    sfClock *clock = sfClock_create();
    sfClock *clock_boy = sfClock_create();
    init_transitionEnd(all);
    while(all->set == 3 && all->level == -6) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        
        sfRenderWindow_drawSprite(WIN, all->transition_bg.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, all->bloc_text.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, all->boy.sprite, NULL);

        transitionEnd_display(all, clock);
        move_boy(all, clock_boy);

        while (sfRenderWindow_pollEvent(WIN, &all->settings.event))
            if (all->settings.event.type == sfEvtClosed) {
                all->set = 0;
        }
    }
    sfClock_destroy(clock);
}
