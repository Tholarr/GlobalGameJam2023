/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** destroy_menu
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

void destroy_menu(menu_t *menu, struct_t *all)
{
    sfSprite_destroy(all->player.sprite);
    sfTexture_destroy(all->player.texture);

    sfSprite_destroy(all->bg.sprite);
    sfTexture_destroy(all->bg.texture);
    sfSprite_destroy(all->m1->sprite);
    sfTexture_destroy(all->m1->texture);
    sfSprite_destroy(all->m2->sprite);
    sfTexture_destroy(all->m2->texture);
    sfSprite_destroy(all->m3->sprite);
    sfTexture_destroy(all->m3->texture);
    sfSprite_destroy(all->m4->sprite);
    sfTexture_destroy(all->m4->texture);
    sfSprite_destroy(all->m5->sprite);
    sfTexture_destroy(all->m5->texture);

    sfSprite_destroy(all->transition_bg.sprite);
    sfTexture_destroy(all->transition_bg.texture);

    sfSprite_destroy(all->bloc_text.sprite);
    sfTexture_destroy(all->bloc_text.texture);

    sfSprite_destroy(all->story_bg.sprite);
    sfTexture_destroy(all->story_bg.texture);

    sfSprite_destroy(menu->bg.sprite);
    sfTexture_destroy(menu->bg.texture);

    sfText_destroy(menu->t_title.text);
    sfFont_destroy(menu->t_title.font);

    sfSprite_destroy(menu->buttons[0].sprite);
    sfTexture_destroy(menu->buttons[0].texture);
    sfSprite_destroy(menu->buttons[1].sprite);
    sfTexture_destroy(menu->buttons[1].texture);
    sfSprite_destroy(menu->buttons[2].sprite);
    sfTexture_destroy(menu->buttons[2].texture);
    sfSprite_destroy(menu->buttons[3].sprite);
    sfTexture_destroy(menu->buttons[3].texture);
    free(menu->buttons);
}