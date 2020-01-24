/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** Pong
*/

#include "../struct.h"

vector_t vector_velocity(vector_t vec_0, vector_t vec_1)
{
    vector_t vec_v;

    vec_v.x = vec_1.x - vec_0.x;
    vec_v.y = vec_1.y - vec_0.y;
    vec_v.z = vec_1.z - vec_0.z;
    return (vec_v);
}