/*
** EPITECH PROJECT, 2021
** window
** File description:
** description
*/

#include "struct.h"

void duck_frame(sfIntRect *frame, int offset, int max)
{
    frame->left = frame->left + offset;
    if (frame->left >= max)
        frame->left = 0;
}

int shoot(t_var var)
{
    sfVector2i mouse_pos;

    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        mouse_pos = sfMouse_getPositionRenderWindow(var.window);
        sfSound_play(var.sonido);
        if ((mouse_pos.x < (var.pos.x + 80) && mouse_pos.x > (var.pos.x - 80))
        && (mouse_pos.y < (var.pos.y + 80) && mouse_pos.y > (var.pos.y - 80))) {
            var.explosion_clock_time = sfClock_getElapsedTime(
            var.explosion_clock);
            while (sfTime_asSeconds(var.explosion_clock_time) < 0.5) {
                sfSprite_setPosition(var.explosion_info, var.pos);
                sfRenderWindow_drawSprite(var.window, var.explosion_info, NULL);
                var.explosion_clock_time = sfClock_getElapsedTime(
                var.explosion_clock);
            }
            sfClock_restart(var.explosion_clock);
            return (1);
        }
    }
    return (0);
}

t_var first(t_var var, sfVector2f velocity)
{
    sfRenderWindow_drawSprite(var.window, var.background_info, NULL);
    sfRenderWindow_drawSprite(var.window, var.duck, NULL);
    var.clock_time = sfClock_getElapsedTime(var.clock);
    var.pos = sfSprite_getPosition(var.duck);
    if (var.pos.x >= 800 || shoot(var) == 1) {
        var.pos.x = -110;
        var.pos.y = rand() % 500;
        sfSprite_setPosition(var.duck, var.pos);
        velocity.x = (rand() % (7 - 3 + 1)) + 3;
    }
    sfSprite_setTextureRect(var.duck, var.duck_area);
    sfSprite_move(var.duck, velocity);
    if (sfTime_asSeconds(var.clock_time) > 0.1) {
        duck_frame(&var.duck_area, 110, 220);
        sfClock_restart(var.clock);
    }
    return var;
}

t_var render(t_var var)
{
    sfEvent event;

    sfRenderWindow_display(var.window);
    while (sfRenderWindow_pollEvent(var.window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(var.window);
    }
    return var;
}


void  Window(t_var var)
{
    var.clock = sfClock_create();
    var.background_info = background();
    var.explosion_info = explosion();
    var.pos.y = rand() % 600;
    var.pos.x = -110;
    var.window = sfRenderWindow_create(var.video_mode, "MyWin",
    sfDefaultStyle, NULL);
    var.explosion_clock = sfClock_create();
    sfVector2f velocity = {((rand() % (5 - 3 + 1)) + 3), 0};
    sfVector2f scale = {0.5, 0.5};
    sfSprite_scale(var.explosion_info, scale);
    while (sfRenderWindow_isOpen(var.window)) {
        sfRenderWindow_setFramerateLimit(var.window, 60);
        var = first(var, velocity);
        var = render(var);
    }
    sfRenderWindow_destroy(var.window);
}
