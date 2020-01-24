/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** Pong
*/

#include "../vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int pong(char **av)
{
    int n = atoi(av[7]);
    vector_t vec_0 = vector_create(atof(av[1]), atof(av[2]), atof(av[3]));
    vector_t vec_1 = vector_create(atof(av[4]), atof(av[5]), atof(av[6]));
    vector_t vec_v = vector_velocity(vec_0, vec_1);
    vector_t pos = vector_position_at_n(vec_1, vec_v, n);
    double angle = vector_angle(vec_v);

    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", vec_v.x, vec_v.y, vec_v.z);
    printf("At time t + %d, ball coordinates will be:\n", n);
    printf("(%.2f, %.2f, %.2f)\n", pos.x, pos.y, pos.z);
    if (angle >= 0 && angle <= 90 && (vec_1.z > 0 && vec_v.z < 0) ||
        angle >= 0 && angle <= 90 && (vec_1.z < 0 && vec_v.z > 0)) {
        printf("The incidence angle is:\n");
        printf("%.2f degrees\n", angle);
    } else
        printf("The ball won't reach the paddle.\n");
    return 0;
}

int is_number(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int error_handling(char **av)
{
    for (int i = 1; av[i] != 0; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '-' || is_number(av[i][j]) == 1 || av[i][j] == '.'
                && is_number(av[i][j - 1]) == 1 && is_number(av[i][j + 1]) == 1)
                continue;
            else {
                write(2, "Invalid arguments.\n", 19);
                return 84;
            }
        }
    }
    for (int i = 0; av[7][i] != '\0'; i++) {
        if (av[7][i] >= '0' && av[7][i] <= '9')
            continue;
        else {
            write(2, "Invalid time shift.\n", 20);
            return 84;
        }
    }
}

int main(int ac, char **av)
{
    if (ac < 8) {
        write(2, "Not enough arguments.\n", 22);
        return 84;
    }
    else if (ac > 8) {
        write(2, "Too many arguments.\n", 20);
        return 84;
    }
    if (error_handling(av) == 84)
        return 84;
    if (ac == 8){
        pong(av);
        return 0;
    }
}