/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** init_game
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

void init_gun(struct_t *all)
{
    all->player.texture = sfTexture_createFromFile("asset/gun.png", NULL);
    all->player.sprite = sfSprite_create();
    all->player.scale.x = 4;
    all->player.scale.y = 4;
    all->player.pos.x = 682;
    all->player.pos.y = 670;
    all->player.rect.top = 0;
    all->player.rect.left = 0;
    all->player.rect.width = 18;
    all->player.rect.height = 30;
    all->player.life = 3;

    sfSprite_setTexture(all->player.sprite, all->player.texture, sfTrue);
    sfSprite_setScale(all->player.sprite, all->player.scale);
    sfSprite_setPosition(all->player.sprite, all->player.pos);
    sfSprite_setTextureRect(all->player.sprite, all->player.rect);
}

void init_pv(struct_t *all)
{
    all->pv.sprite = sfSprite_create();
    all->pv.texture = sfTexture_createFromFile("asset/pv03.png", NULL);
    all->pv.scale.x = 5;
    all->pv.scale.y = 5;
    all->pv.pos.x = 50;
    all->pv.pos.y = 50;
    sfSprite_setTexture(all->pv.sprite, all->pv.texture, sfFalse);
    sfSprite_setScale(all->pv.sprite, all->pv.scale);
    sfSprite_setPosition(all->pv.sprite, all->pv.pos);
}

void init_game(struct_t *all)
{
    all->bg.texture = sfTexture_createFromFile("asset/backgrounds/game_bg.jpg", NULL);
    all->bg.sprite = sfSprite_create();
    all->bg.scale.x = 2;
    all->bg.scale.y = 2;
    sfSprite_setTexture(all->bg.sprite, all->bg.texture, sfFalse);
    sfSprite_setScale(all->bg.sprite, all->bg.scale);
    init_gun(all);
    init_pv(all);
}
