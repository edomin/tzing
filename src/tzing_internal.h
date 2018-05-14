#ifndef TZING_INTERNAL_H
#define TZING_INTERNAL_H

#include "tzing.h"

static inline float tzing_Min(float num1, float num2)
{
    return (num1 < num2) ? num1 : num2;
}

static inline float tzing_Max(float num1, float num2)
{
    return (num1 > num2) ? num1 : num2;
}

#endif