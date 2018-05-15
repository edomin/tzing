#ifndef TZING_INTERNAL_H
#define TZING_INTERNAL_H

#include <math.h>
#include "tzing.h"

#define TZING_RADIAN 57.295779513082320876798154814105f
#define TZING_2PI 6.283185307179586476925286766559f

static inline float tzing_Min(float num1, float num2)
{
    return (num1 < num2) ? num1 : num2;
}

static inline float tzing_Max(float num1, float num2)
{
    return (num1 > num2) ? num1 : num2;
}

#endif
