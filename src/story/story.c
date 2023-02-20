/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** story
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
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void init_story(struct_t *all)
{
    all->story_bg.texture = sfTexture_createFromFile("asset/backgrounds/story_bg.jpg", NULL);
    all->story_bg.sprite = sfSprite_create();
    all->story_bg.scale.x = 1.7;
    all->story_bg.scale.y = 1.7;
    all->story_bg.pos.x = 0;
    all->story_bg.pos.y = 0;
    sfSprite_setTexture(all->story_bg.sprite, all->story_bg.texture, sfFalse);
    sfSprite_setPosition(all->story_bg.sprite, all->story_bg.pos);
    sfSprite_setScale(all->story_bg.sprite, all->story_bg.scale);

    all->bloc_text.texture = sfTexture_createFromFile("asset/text_and_font/bloc_text.png", NULL);
    all->bloc_text.sprite = sfSprite_create();
    all->bloc_text.scale.x = 10.4;
    all->bloc_text.scale.y = 10;
    sfSprite_setScale(all->bloc_text.sprite, all->bloc_text.scale);
    sfSprite_setTexture(all->bloc_text.sprite, all->bloc_text.texture, sfFalse);

    all->boy.texture = sfTexture_createFromFile("asset/mob/boy.png", NULL);
    all->boy.sprite = sfSprite_create();
    all->boy.scale.x = 4;
    all->boy.scale.y = 4;
    all->boy.pos.x = 50;
    all->boy.pos.y = 670;
    all->boy.rect.top = 0;
    all->boy.rect.left = 0;
    all->boy.rect.width = 12;
    all->boy.rect.height = 17;

    sfSprite_setTexture(all->boy.sprite, all->boy.texture, sfTrue);
    sfSprite_setScale(all->boy.sprite, all->boy.scale);
    sfSprite_setPosition(all->boy.sprite, all->boy.pos);
    sfSprite_setTextureRect(all->boy.sprite, all->boy.rect);
}

void story_manage_events(struct_t *all, sfEvent *event, sfRenderWindow *win)
{
    if (event->type == sfEvtClosed) {
        all->set = 0;
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeySpace) {
        all->set = 1;
    }
}

void story_display(struct_t *all, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("tty/prstart.ttf");
    sfVector2f pos = {50, 50};
    sfVector2f scale = {0.50, 0.50};
    sfColor color = sfColor_fromRGB(255, 255, 255);
    sfText_setColor(text, color);
    sfText_setScale(text, scale);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);

    sfText *text_skip = sfText_create();
    sfVector2f pos_skip = {900, 200};
    sfVector2f scale_skip = {0.50, 0.50};
    sfText_setColor(text_skip, color);
    sfText_setScale(text_skip, scale_skip);
    sfText_setPosition(text_skip, pos_skip);
    sfText_setFont(text_skip, font);
    sfText_setString(text_skip, "Press SPACE to skip");
    
    if (seconds > 1.5)
        sfRenderWindow_drawText(WIN, text_skip, NULL);   

    if (seconds > 1.5 && seconds < 13) {
        sfText_setString(text, "This story revolves around a kid who is on his way home from school and\n\non the way he happens to go through a nicely wooded area.\n\nAnd it is within this small forest that our advanture takes place.");
        sfRenderWindow_drawText(WIN, text, NULL);
    }
    if (seconds > 13 && seconds < 23) {
        sfText_setString(text, "The kid finds a fantastic branch and realises that if you sqint a little bit\n\nit starts to resemble a soldiers weapon, and the daydreaming begins.");
        sfRenderWindow_drawText(WIN, text, NULL);
    }
    if (seconds > 23) {
        sfText_setString(text, "He starts hearing whisper from below him and with his new weapon by his side\n\nhe decides to follow them, he does so until he stumbles upon a small hole\n\npartially covered up by the roots of the nearby tree, and he descends.");
        sfRenderWindow_drawText(WIN, text, NULL);
    }
    if (seconds > 36)
        all->set = 1;

    sfText_destroy(text);
    sfFont_destroy(font);
}

void move_boy(struct_t *all, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.2) {
        if (all->boy.rect.left == 36)
            all->boy.rect.left = 0;
        if (all->boy.rect.left == 24)
            all->boy.rect.left = 36;
        if (all->boy.rect.left == 12)
            all->boy.rect.left = 24;
        if (all->boy.rect.left == 0)
            all->boy.rect.left = 12;
        all->boy.pos.x += 4;
        all->story_bg.pos.x -= 4;
        sfSprite_setPosition(all->boy.sprite, all->boy.pos);
        sfSprite_setPosition(all->story_bg.sprite, all->story_bg.pos);
        sfSprite_setTextureRect(all->boy.sprite, all->boy.rect);
        sfClock_restart(clock);
    }
}

void story(struct_t *all)
{
    sfClock *clock = sfClock_create();
    sfClock *clock_boy = sfClock_create();
    init_story(all);
    while(all->set == -1) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        
        sfRenderWindow_drawSprite(WIN, all->story_bg.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, all->bloc_text.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, all->boy.sprite, NULL);

        story_display(all, clock);
        move_boy(all, clock_boy);

        while (sfRenderWindow_pollEvent(WIN, &all->settings.event))
            story_manage_events(all, &all->settings.event, WIN);
    }
    sfClock_destroy(clock);
}