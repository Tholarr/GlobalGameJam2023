/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** main
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
#include "../include/struct.h"
#include "../include/my.h"
#include "../include/define.h"

void init_window(struct_t *all)
{
    all->settings.height = 790;
    all->settings.width = 1250;
    MODE.bitsPerPixel = 32;
    MODE.height = all->settings.height;
    MODE.width = all->settings.width;
    WIN = sfRenderWindow_create(MODE, "underoots", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WIN, 60);
}

void main_loop(struct_t *all)
{
    menu_t menu;
    init_menu(&menu);
    all->set = -1;
    ini_sounds(&menu);
    while (sfRenderWindow_isOpen(WIN)) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        switch (all->set) {
            case 0: sfRenderWindow_close(WIN); return;
            case -1: story(all); break;
            case 1: play_menu(all, &menu, &all->settings.event); break;
            case 2: play_keybinds(all, &menu, &all->settings.event); break;
            case 3: sfMusic_stop(menu.soundtrack[0].music); ini_sounds_gun(all); sfMusic_play(all->gun_sound[1].music); sfMusic_setLoop(all->gun_sound[1].music, sfTrue); play_game(all, &all->settings.event); sfMusic_stop(all->gun_sound[1].music); break;
        }
        if (sfMusic_getStatus(menu.soundtrack[0].music) == sfStopped)
            sfMusic_play(menu.soundtrack[0].music);
    }
    destroy_menu(&menu, all);
}

int main(void)
{
    struct_t all;
    init_window(&all);
    main_loop(&all);
}
