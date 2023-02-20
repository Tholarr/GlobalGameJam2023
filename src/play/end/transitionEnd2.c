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

void init_transitionEnd2(struct_t *all)
{
    all->transition_bg.texture = sfTexture_createFromFile("asset/backgrounds/end_transition_bg.png", NULL);
    all->transition_bg.sprite = sfSprite_create();
    all->transition_bg.scale.x = 0.78;
    all->transition_bg.scale.y = 0.78;
    sfSprite_setTexture(all->transition_bg.sprite, all->transition_bg.texture, sfFalse);
    sfSprite_setScale(all->transition_bg.sprite, all->transition_bg.scale);

    all->bloc_text.texture = sfTexture_createFromFile("asset/text_and_font/bloc_text3.png", NULL);
    sfSprite_setTexture(all->bloc_text.sprite, all->bloc_text.texture, sfFalse);
}

void transitionEnd2_display(struct_t *all, sfClock *clock)
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

    if (seconds > 0.5) {
        sfText_setString(text, "As he comes in contact with the water, he suddenly reopens his eyes,\n\nhe is just laying next to an old oak tree, his branch firmly in his hands.");
        sfRenderWindow_drawText(WIN, text, NULL);
    }
    if (seconds > 10)
        all->level = -8;
}

void transitionEnd2(struct_t *all)
{
    sfClock *clock = sfClock_create();
    sfClock *clock_boy = sfClock_create();
    init_transitionEnd2(all);
    while(all->set == 3 && all->level == -7) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        
        sfRenderWindow_drawSprite(WIN, all->transition_bg.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, all->bloc_text.sprite, NULL);

        transitionEnd2_display(all, clock);

        while (sfRenderWindow_pollEvent(WIN, &all->settings.event))
            if (all->settings.event.type == sfEvtClosed)
                all->set = 0;
    }
    sfClock_destroy(clock);
}
