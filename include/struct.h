/*
** EPITECH PROJECT, 2021
** window
** File description:
** description
*/

#ifndef STRUCT_H_
#define STRCUT_H_

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <time.h>
#include <stdio.h>
#include <SFML/System.h>
#include <unistd.h>

typedef struct s_var {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfSprite *duck;
    sfMusic *music;
    sfClock *clock;
    sfClock *explosion_clock;
    sfSprite *background_info;
    sfSprite *explosion_info;
    sfVector2f pos;
    sfIntRect duck_area;
    sfTime clock_time;
    sfTime explosion_clock_time;
    sfVector2f velocity;
    sfSoundBuffer *buffer;
    sfSound *sonido;
} t_var;

sfSprite *background();
sfSprite *create_duck();
sfSprite *explosion();
void duck_frame(sfIntRect *frame, int offset, int max);
int shoot(t_var var);
t_var first(t_var var, sfVector2f velocity);
t_var render(t_var var);
void  Window(t_var var);
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);


#endif