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

bool Tzing_AabbToAabbPenetration(float aabb1_x1, float aabb1_y1, float aabb1_x2, 
 float aabb1_y2, float aabb2_x1, float aabb2_y1, float aabb2_x2, float aabb2_y2, 
 float *angle, float *depth)
{
    float aabb1_centerX;
    float aabb1_centerY;
    float aabb2_centerX;
    float aabb2_centerY;
    
    if (aabb1_x1 < aabb2_x2 && 
     aabb1_x2 > aabb2_x1 &&
     aabb1_y1 < aabb2_y2 && 
     aabb1_y2 > aabb2_y1) {
        
    }
        
    return false;
}

bool Tzing_PointToAabb(float pointX, float pointY, float aabb_x1, float aabb_y1,
 float aabb_x2, float aabb_y2)
{
    return (pointX > aabb_x1 && 
     pointX < aabb_x2 && 
     pointY > aabb_y1 && 
     pointY < aabb_y2);
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

bool Tzing_CircleToCircle(float circle1_centerX, float circle1_centerY, 
 float circle1_radius, float circle2_centerX, float circle2_centerY, 
 float circle2_radius)
{
    float xOffset;
    float yOffset;
    float hypot_sq; /* Square of hypotenuse */
    float radiuses_sum;
    
    if (circle1_centerX + circle1_radius + circle2_radius > circle2_centerX 
     && circle1_centerX < circle2_centerX + circle1_radius + circle2_radius
     && circle1_centerY + circle1_radius + circle2_radius > circle2_centerY 
     && circle1_centerY < circle2_centerY + circle1_radius + circle2_radius)
    {
        xOffset = tzing_Max(circle1_centerX, circle2_centerX) - 
         tzing_Min(circle1_centerX, circle2_centerX);
        yOffset = tzing_Max(circle1_centerY, circle2_centerY) - 
         tzing_Min(circle1_centerY, circle2_centerY);
        hypot_sq = xOffset * xOffset + yOffset * yOffset;
        radiuses_sum = circle1_radius + circle2_radius;
        if (hypot_sq < radiuses_sum * radiuses_sum)
            return true;
    }
    
    return false;
}

bool Tzing_CircleToCircleCollisionPoint(float circle1_centerX, 
 float circle1_centerY, float circle1_radius, float circle2_centerX, 
 float circle2_centerY, float circle2_radius, float *collisionPointX, 
 float *collisionPointY)
{
    float xOffset;
    float yOffset;
    float hypot_sq; /* Square of hypotenuse */
    float radiuses_sum;
    
    if (circle1_centerX + circle1_radius + circle2_radius > circle2_centerX 
     && circle1_centerX < circle2_centerX + circle1_radius + circle2_radius
     && circle1_centerY + circle1_radius + circle2_radius > circle2_centerY 
     && circle1_centerY < circle2_centerY + circle1_radius + circle2_radius)
    {
        xOffset = tzing_Max(circle1_centerX, circle2_centerX) - 
         tzing_Min(circle1_centerX, circle2_centerX);
        yOffset = tzing_Max(circle1_centerY, circle2_centerY) - 
         tzing_Min(circle1_centerY, circle2_centerY);
        hypot_sq = xOffset * xOffset + yOffset * yOffset;
        radiuses_sum = circle1_radius + circle2_radius;
        if (hypot_sq < radiuses_sum * radiuses_sum) {
            *collisionPointX = ((circle1_centerX * circle2_radius) + 
             (circle2_centerX * circle1_radius)) / 
             (circle1_radius + circle2_radius);
            *collisionPointY = ((circle1_centerY * circle2_radius) + 
             (circle2_centerY * circle1_radius)) / 
             (circle1_radius + circle2_radius);
            return true;
        }
    }
    
    return false;
}

bool Tzing_CircleToCirclePenetration(float circle1_centerX, 
 float circle1_centerY, float circle1_radius, float circle2_centerX, 
 float circle2_centerY, float circle2_radius, float *angle, float *depth)
{
    float xOffset;
    float yOffset;
    float hypot_sq; /* Square of hypotenuse */
    float radiuses_sum;
    float opposite;
    float adjacent;
    
    if (circle1_centerX + circle1_radius + circle2_radius > circle2_centerX 
     && circle1_centerX < circle2_centerX + circle1_radius + circle2_radius
     && circle1_centerY + circle1_radius + circle2_radius > circle2_centerY 
     && circle1_centerY < circle2_centerY + circle1_radius + circle2_radius)
    {
        xOffset = tzing_Max(circle1_centerX, circle2_centerX) - 
         tzing_Min(circle1_centerX, circle2_centerX);
        yOffset = tzing_Max(circle1_centerY, circle2_centerY) - 
         tzing_Min(circle1_centerY, circle2_centerY);
        hypot_sq = xOffset * xOffset + yOffset * yOffset;
        radiuses_sum = circle1_radius + circle2_radius;
        if (hypot_sq < radiuses_sum * radiuses_sum) {
            opposite = circle1_centerY - circle2_centerY;
            adjacent = circle1_centerX - circle2_centerX;
            if (adjacent > 0)
                *angle = (TZING_2PI - atanf(opposite / adjacent)) * 
                 TZING_RADIAN;
            else
                *angle = (M_PI - atanf(opposite / adjacent)) * TZING_RADIAN;
            
            *depth = radiuses_sum - sqrtf(hypot_sq);
            return true;
        }
    }
    
    return false;
}
