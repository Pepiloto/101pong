/*
** EPITECH PROJECT, 2019
** Bootstrap pong
** File description:
** Header for vector_functions
*/

#define norm(vec_0) vector_norm(vec_0)
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include "struct.h"

vector_t vector_position_at_n(vector_t vec_1, vector_t vec_v, int n);
vector_t vector_velocity(vector_t vec_0, vector_t vec_1);

static inline vector_t vector_create(float x, float y, float z)
{
    vector_t vector_1 = {x, y, z};
    return (vector_1);
}

static inline float vector_scal(vector_t vec_0, vector_t vec_1)
{
    return (vec_0.x * vec_1.x + vec_0.y * vec_1.y + vec_0.z * vec_1.z);
}

static inline double vector_norm(vector_t vector_1)
{
    double norm = 0;

    norm = sqrt(pow(vector_1.x, 2) + pow(vector_1.y, 2) + pow(vector_1.z, 2));
    return (norm);
}

static inline double vector_angle(vector_t vec_v)
{
    double res = asin(vec_v.z / vector_norm(vec_v)) * 180 / 3.14159;
    if (res < 0)
        return -1 * res;
    return res;
}
