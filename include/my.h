/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** my
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
#include "struct.h"

#ifndef MY_H_
    #define MY_H_

void story(struct_t *all);

void play_menu(struct_t *all, menu_t *menu, sfEvent *event);
void init_menu(menu_t *menu);
void destroy_menu(menu_t *menu, struct_t *all);
void play_keybinds(struct_t *all, menu_t *menu, sfEvent *event);

void play_game(struct_t *all, sfEvent *event);
void init_game(struct_t *all);
void gun_anim(struct_t *all, sfRenderWindow *win);
void game_manage_events(struct_t *all, sfEvent *event, sfRenderWindow *win);

void level_1(struct_t *all, sfEvent *event);
void anim_monsters1(struct_t *all, sfRenderWindow *win, sprite_t *script, sfClock *clock);

void transition2(struct_t *all);
void level_2(struct_t *all, sfEvent *event);
void anim_monsters2(struct_t *all, sfRenderWindow *win, sprite_t *script, sfClock *clock);

void transition3(struct_t *all);
void level_3(struct_t *all, sfEvent *event);
void anim_monsters3(struct_t *all, sfRenderWindow *win, sprite_t *script, sfClock *clock);

void transition4(struct_t *all);
void level_4(struct_t *all, sfEvent *event);
void anim_monsters4(struct_t *all, sfRenderWindow *win, sprite_t *script, sfClock *clock);

void transition5(struct_t *all);
void level_5(struct_t *all, sfEvent *event);
void anim_monsters5(struct_t *all, sfRenderWindow *win, sprite_t *script, sfClock *clock);

void transitionEnd(struct_t *all);
void transitionEnd2(struct_t *all);
void end_story(struct_t *all);

void move_boy(struct_t *all, sfClock *clock);
sprite_t init_m1(int pos);
sprite_t init_m2(int pos);
sprite_t init_m3(int pos);
sprite_t init_m4(int pos);
sprite_t init_m5(int pos);

void ini_sounds(menu_t *menu);
void ini_sounds_gun(struct_t *all);

#endif /* !MY_H_ */
