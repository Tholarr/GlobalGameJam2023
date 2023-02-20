/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** start_menu
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

void draw_menu(menu_t *menu, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, menu->bg.sprite, NULL);
    sfRenderWindow_drawText(win, menu->t_title.text, NULL);
    sfRenderWindow_drawSprite(win, menu->buttons[0].sprite, NULL);
    sfRenderWindow_drawSprite(win, menu->buttons[1].sprite, NULL);
    sfRenderWindow_drawSprite(win, menu->buttons[2].sprite, NULL);
}

void menu_manage_mouse_click(struct_t *all, menu_t *menu, sfEvent *event)
{
    if (event->mouseButton.x >= 410 && event->mouseButton.x <= 550) {
        if (event->mouseButton.y >= 410 && event->mouseButton.y <= 475) {
            all->set = 3;
        }
    }
    if (event->mouseButton.x >= 410 && event->mouseButton.x <= 570) {
        if (event->mouseButton.y >= 510 && event->mouseButton.y <= 575) {
            all->set = 2;
        }
    }
    if (event->mouseButton.x >= 410 && event->mouseButton.x <= 550) {
        if (event->mouseButton.y >= 610 && event->mouseButton.y <= 675) {
            all->set = 0;
        }
    }
}

void menu_manage_events(struct_t *all, menu_t *menu, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        all->set = 0;
    }
    if (event->type == sfEvtMouseButtonPressed)
        menu_manage_mouse_click(all, menu, event);
}

void play_menu(struct_t *all, menu_t *menu, sfEvent *event)
{
    while (all->set == 1) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);

        draw_menu(menu, WIN);
        
        while (sfRenderWindow_pollEvent(WIN, event))
            menu_manage_events(all, menu, event);
    }
    return;
}