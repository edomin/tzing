#include "tzing_internal.h"

bool Tzing_AabbToAabb(float aabb1_x1, float aabb1_y1, float aabb1_x2, 
 float aabb1_y2, float aabb2_x1, float aabb2_y1, float aabb2_x2, float aabb2_y2)
{
    if (aabb1_x1 < aabb2_x2 && 
     aabb1_x2 > aabb2_x1 &&
     aabb1_y1 < aabb2_y2 && 
     aabb1_y2 > aabb2_y1)
        return true;
        
    return false;
}

bool tzing_pointtocircle(float pointx, float pointy, float circlecenterx, 
 float circlecentery, float circleradius)
{
    return false;
}