/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** init_monsters
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

sprite_t init_m5(int pos)
{
    float x = 0;
    switch (pos) {
        case 1: x = 419; break;
        case 2: x = 682; break;
        case 3: x = 891; break; 
    }
    sprite_t monster;
    monster.texture = sfTexture_createFromFile("asset/mob/m5.png", NULL);
    monster.sprite = sfSprite_create();
    monster.scale.x = 7;
    monster.scale.y = 7;
    monster.pos.x = x;
    monster.pos.y = 500;
    monster.rect.top = 0;
    monster.rect.left = 0;
    monster.rect.width = 24;
    monster.rect.height = 34;
    monster.life = 4    ;
    monster.set = 0;
    monster.display = 0;
    monster.delay = 0;
    monster.type = 5;

    sfSprite_setTexture(monster.sprite, monster.texture, sfTrue);
    sfSprite_setScale(monster.sprite, monster.scale);
    sfSprite_setPosition(monster.sprite, monster.pos);
    sfSprite_setTextureRect(monster.sprite, monster.rect);
    
    return monster;
}

sprite_t init_m4(int pos)
{
    float x = 0;
    switch (pos) {
        case 1: x = 419; break;
        case 2: x = 682; break;
        case 3: x = 891; break; 
    }
    sprite_t monster;
    monster.texture = sfTexture_createFromFile("asset/mob/m4.png", NULL);
    monster.sprite = sfSprite_create();
    monster.scale.x = 7;
    monster.scale.y = 7;
    monster.pos.x = x;
    monster.pos.y = 570;
    monster.rect.top = 0;
    monster.rect.left = 0;
    monster.rect.width = 21;
    monster.rect.height = 20;
    monster.life = 3;
    monster.set = 0;
    monster.display = 0;
    monster.delay = 0;
    monster.type = 4;

    sfSprite_setTexture(monster.sprite, monster.texture, sfTrue);
    sfSprite_setScale(monster.sprite, monster.scale);
    sfSprite_setPosition(monster.sprite, monster.pos);
    sfSprite_setTextureRect(monster.sprite, monster.rect);
    
    return monster;
}

sprite_t init_m3(int pos)
{
    float x = 0;
    switch (pos) {
        case 1: x = 419; break;
        case 2: x = 682; break;
        case 3: x = 891; break; 
    }
    sprite_t monster;
    monster.texture = sfTexture_createFromFile("asset/mob/m3.png", NULL);
    monster.sprite = sfSprite_create();
    monster.scale.x = 7;
    monster.scale.y = 7;
    monster.pos.x = x;
    monster.pos.y = 570;
    monster.rect.top = 0;
    monster.rect.left = 0;
    monster.rect.width = 14;
    monster.rect.height = 17;
    monster.life = 2;
    monster.set = 0;
    monster.display = 0;
    monster.delay = 0;
    monster.type = 3;

    sfSprite_setTexture(monster.sprite, monster.texture, sfTrue);
    sfSprite_setScale(monster.sprite, monster.scale);
    sfSprite_setPosition(monster.sprite, monster.pos);
    sfSprite_setTextureRect(monster.sprite, monster.rect);
    
    return monster;
}

sprite_t init_m2(int pos)
{
    float x = 0;
    switch (pos) {
        case 1: x = 419; break;
        case 2: x = 682; break;
        case 3: x = 891; break; 
    }
    sprite_t monster;
    monster.texture = sfTexture_createFromFile("asset/mob/m2.png", NULL);
    monster.sprite = sfSprite_create();
    monster.scale.x = 7;
    monster.scale.y = 7;
    monster.pos.x = x;
    monster.pos.y = 600;
    monster.rect.top = 0;
    monster.rect.left = 0;
    monster.rect.width = 13;
    monster.rect.height = 11;
    monster.life = 1;
    monster.set = 0;
    monster.display = 0;
    monster.delay = 0;
    monster.type = 2;

    sfSprite_setTexture(monster.sprite, monster.texture, sfTrue);
    sfSprite_setScale(monster.sprite, monster.scale);
    sfSprite_setPosition(monster.sprite, monster.pos);
    sfSprite_setTextureRect(monster.sprite, monster.rect);
    
    return monster;
}

sprite_t init_m1(int pos)
{
    float x = 0;
    switch (pos) {
        case 1: x = 419; break;
        case 2: x = 682; break;
        case 3: x = 891; break; 
    }
    sprite_t monster;
    monster.texture = sfTexture_createFromFile("asset/mob/m1.png", NULL);
    monster.sprite = sfSprite_create();
    monster.scale.x = 7;
    monster.scale.y = 7;
    monster.pos.x = x;
    monster.pos.y = 630;
    monster.rect.top = 0;
    monster.rect.left = 0;
    monster.rect.width = 9;
    monster.rect.height = 10;
    monster.life = 1;
    monster.set = 0;
    monster.display = 0;
    monster.delay = 0;
    monster.type = 1;

    sfSprite_setTexture(monster.sprite, monster.texture, sfTrue);
    sfSprite_setScale(monster.sprite, monster.scale);
    sfSprite_setPosition(monster.sprite, monster.pos);
    sfSprite_setTextureRect(monster.sprite, monster.rect);
    
    return monster;
}
