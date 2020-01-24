/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** Pong
*/

#include "../struct.h"

vector_t vector_position_at_n(vector_t vec_1, vector_t vec_v, int n)
{
    vector_t pos;

    pos.x = vec_1.x + vec_v.x * n;
    pos.y = vec_1.y + vec_v.y * n;
    pos.z = vec_1.z + vec_v.z * n;
    return (pos);
}