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

bool Tzing_PointToAabb(float pointX, float pointY, float aabb_x1, float aabb_y1,
 float aabb_x2, float aabb_y2)
{
    return (pointX >= aabb_x1 && 
     pointX <= aabb_x2 && 
     pointY >= aabb_y1 && 
     pointY <= aabb_y2);
}

bool Tzing_PointToCircle(float pointX, float pointY, float circleCenterX, 
 float circleCenterY, float circleRadius)
{
    float xOffset = tzing_Max(pointX, circleCenterX) - 
     tzing_Min(pointX, circleCenterX);
    float yOffset = tzing_Max(pointY, circleCenterY) - 
     tzing_Min(pointY, circleCenterY);
    /* Square of hypotenuse */
    float hypot_sq = xOffset * xOffset + yOffset * yOffset;
    
    if (hypot_sq < circleRadius * circleRadius)
        return true;
    
    return false;
}
