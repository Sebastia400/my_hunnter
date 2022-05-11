/*
** EPITECH PROJECT, 2021
** window
** File description:
** description
*/

#include "struct.h"

void help(int argc, char **argv)
{
    if (argc > 2) {
        my_putstr("Invalid arguments\n");
        exit(84);
    } else if (argc == 2) {
        my_putstr("This is a game based on the duck hunter videogame\n");
        my_putstr("which consists on chasing ducks. To kill the duck, \n");
        my_putstr("you need to put your coursor on the duck and left click\n");
    }
}

int main(int argc, char **argv)
{
    t_var var;

    if (argc >= 2) {
        help(argc, argv);
        return (0);
    }
    var.video_mode = (sfVideoMode){800, 600, 32};
    var.duck = create_duck();
    var.music = sfMusic_createFromFile("./sounds/music.wav");
    var.buffer = sfSoundBuffer_createFromFile("./sounds/shoot_sound.wav");
    var.sonido = sfSound_create();
    var.duck_area =  (sfIntRect){0, 0, 110, 110};
    sfSound_setBuffer(var.sonido, var.buffer);
    sfMusic_setLoop(var.music, sfTrue);
    sfMusic_play(var.music);
    srand(time(NULL));
    Window(var);
    return (0);
}
