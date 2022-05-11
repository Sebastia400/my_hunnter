/*
** EPITECH PROJECT, 2021
** window
** File description:
** description
*/

#include "struct.h"

sfSprite *background(void)
{
    sfTexture *background_image = sfTexture_createFromFile("./images/background.png"
    , NULL);
    sfSprite *sprite_backgroung = sfSprite_create();
    sfSprite_setTexture(sprite_backgroung, background_image, 0);
    return (sprite_backgroung);
}

sfSprite *create_duck(void)
{
    sfTexture *duck_image = sfTexture_createFromFile("./images/duck.png", NULL);
    sfSprite *sprite_duck = sfSprite_create();
    sfSprite_setTexture(sprite_duck, duck_image, 0);
    return (sprite_duck);
}

sfSprite *explosion(void)
{
    sfTexture *explosion_image = sfTexture_createFromFile("./images/explosion.png",
    NULL);
    sfSprite *sprite_explosion = sfSprite_create();
    sfSprite_setTexture(sprite_explosion, explosion_image, 0);
    return (sprite_explosion);
}
