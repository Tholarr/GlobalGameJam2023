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

void init_transition5(struct_t *all)
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
    sfSprite_setPosition(all->boy.sprite, all->boy.pos);
    sfSprite_setTextureRect(all->boy.sprite, all->boy.rect);
}

void transition5_display(struct_t *all, sfClock *clock)
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
        sfText_setString(text, "The weirdness of this cave just kept on getting worse and worse\n\nas all the types of monster previously met were now all hot on his trail.");
        sfRenderWindow_drawText(WIN, text, NULL);
    }
    if (seconds > 10)
        all->level = 5;

    sfText_destroy(text);
    sfFont_destroy(font);
}

void transition5(struct_t *all)
{
    sfClock *clock = sfClock_create();
    sfClock *clock_boy = sfClock_create();
    init_transition5(all);
    while(all->set == 3 && all->level == -5) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        
        sfRenderWindow_drawSprite(WIN, all->transition_bg.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, all->bloc_text.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, all->boy.sprite, NULL);

        transition5_display(all, clock);
        move_boy(all, clock_boy);

        while (sfRenderWindow_pollEvent(WIN, &all->settings.event))
            if (all->settings.event.type == sfEvtClosed) {
                all->set = 0;
        }
    }
    sfClock_destroy(clock);
}
