/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** keybinds
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

void keybinds_manage_events(struct_t *all, menu_t *menu, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        all->set = 0;
    }
    if (event->mouseButton.x >= 1050 && event->mouseButton.x <= 1200) {
        if (event->mouseButton.y >= 700 && event->mouseButton.y <= 775) {
            all->set = 1;
        }
    }
}

void play_keybinds(struct_t *all, menu_t *menu, sfEvent *event)
{
    sfSprite *keybind_menu = sfSprite_create();
    sfTexture *keybind_menu_txt = sfTexture_createFromFile("asset/backgrounds/keybinds_bg.png", NULL);
    sfSprite_setTexture(keybind_menu, keybind_menu_txt, sfFalse);

    while (all->set == 2) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);

        sfRenderWindow_drawSprite(WIN, keybind_menu, NULL);
        sfRenderWindow_drawSprite(WIN, menu->buttons[3].sprite, NULL);
        
        while (sfRenderWindow_pollEvent(WIN, event)) {  
            keybinds_manage_events(all, menu, event);
            
        }
    }
    sfSprite_destroy(keybind_menu);
    sfTexture_destroy(keybind_menu_txt);
    return;
}
