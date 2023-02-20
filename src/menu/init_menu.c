/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** init_start_menu
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
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void init_buttons(menu_t *menu)
{
    menu->buttons = malloc(sizeof(sprite_t) * 4);
    menu->buttons[0].sprite = sfSprite_create();
    menu->buttons[0].texture = sfTexture_createFromFile("asset/buttons/play_button.png", NULL);
    menu->buttons[0].scale.y = 4;
    menu->buttons[0].scale.x = 4;
    menu->buttons[0].pos.y = 400;
    menu->buttons[0].pos.x = 400;
    menu->buttons[0].rect.top = 0;
    menu->buttons[0].rect.left = 0;
    menu->buttons[0].rect.height = 20;
    menu->buttons[0].rect.width = 39;
    sfSprite_setTextureRect(menu->buttons[0].sprite, menu->buttons[0].rect);
    sfSprite_setTexture(menu->buttons[0].sprite, menu->buttons[0].texture, sfFalse);
    sfSprite_setScale(menu->buttons[0].sprite, menu->buttons[0].scale);
    sfSprite_setPosition(menu->buttons[0].sprite, menu->buttons[0].pos);

    menu->buttons[1].sprite = sfSprite_create();
    menu->buttons[1].texture = sfTexture_createFromFile("asset/buttons/exit_button.png", NULL);
    menu->buttons[1].scale.y = 4;
    menu->buttons[1].scale.x = 4;
    menu->buttons[1].pos.y = 600;
    menu->buttons[1].pos.x = 400;
    menu->buttons[1].rect.top = 0;
    menu->buttons[1].rect.left = 0;
    menu->buttons[1].rect.height = 20;
    menu->buttons[1].rect.width = 39;
    sfSprite_setTextureRect(menu->buttons[1].sprite, menu->buttons[1].rect);
    sfSprite_setTexture(menu->buttons[1].sprite, menu->buttons[1].texture, sfFalse);
    sfSprite_setScale(menu->buttons[1].sprite, menu->buttons[1].scale);
    sfSprite_setPosition(menu->buttons[1].sprite, menu->buttons[1].pos);

    menu->buttons[2].sprite = sfSprite_create();
    menu->buttons[2].texture = sfTexture_createFromFile("asset/buttons/tuto_button.png", NULL);
    menu->buttons[2].scale.y = 4;
    menu->buttons[2].scale.x = 4;
    menu->buttons[2].pos.y = 500;
    menu->buttons[2].pos.x = 400;
    menu->buttons[2].rect.top = 0;
    menu->buttons[2].rect.left = 0;
    menu->buttons[2].rect.height = 20;
    menu->buttons[2].rect.width = 44;
    sfSprite_setTextureRect(menu->buttons[2].sprite, menu->buttons[2].rect);
    sfSprite_setTexture(menu->buttons[2].sprite, menu->buttons[2].texture, sfFalse);
    sfSprite_setScale(menu->buttons[2].sprite, menu->buttons[2].scale);
    sfSprite_setPosition(menu->buttons[2].sprite, menu->buttons[2].pos);

    menu->buttons[3].sprite = sfSprite_create();
    menu->buttons[3].texture = sfTexture_createFromFile("asset/buttons/home_button.png", NULL);
    menu->buttons[3].scale.y = 4;
    menu->buttons[3].scale.x = 4;
    menu->buttons[3].pos.y = 700;
    menu->buttons[3].pos.x = 1050;
    menu->buttons[3].rect.top = 0;
    menu->buttons[3].rect.left = 0;
    menu->buttons[3].rect.height = 20;
    menu->buttons[3].rect.width = 39;
    sfSprite_setTextureRect(menu->buttons[3].sprite, menu->buttons[3].rect);
    sfSprite_setTexture(menu->buttons[3].sprite, menu->buttons[3].texture, sfFalse);
    sfSprite_setScale(menu->buttons[3].sprite, menu->buttons[3].scale);
    sfSprite_setPosition(menu->buttons[3].sprite, menu->buttons[3].pos);

    return;
}

void init_text_title(menu_t *menu)
{
    menu->t_title.text = sfText_create();
    menu->t_title.font = sfFont_createFromFile("asset/text_and_font/press-start/prstart.ttf");
    menu->t_title.color = sfColor_fromRGB(45, 238, 212);
    menu->t_title.pos.y = 215;
    menu->t_title.pos.x = 90;
    sfText_setString(menu->t_title.text, "UNDEROOTS");
    sfText_setFont(menu->t_title.text, menu->t_title.font);
    sfText_setColor(menu->t_title.text, menu->t_title.color);
    sfText_setCharacterSize(menu->t_title.text, 50);
    sfText_setPosition(menu->t_title.text, menu->t_title.pos);
    return;
}

void init_menu(menu_t *menu)
{
    menu->bg.texture = sfTexture_createFromFile("asset/backgrounds/menu_bg.png", NULL);
    menu->bg.sprite = sfSprite_create();
    menu->bg.scale.x = 2;
    menu->bg.scale.y = 2;
    sfSprite_setTexture(menu->bg.sprite, menu->bg.texture, sfFalse);
    sfSprite_setScale(menu->bg.sprite, menu->bg.scale);
    init_text_title(menu);
    init_buttons(menu);
}