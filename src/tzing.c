#include "tzing_internal.h"

bool Tzing_AabbToAabb(float aabb1_x1, float aabb1_y1, float aabb1_x2, 
 float aabb1_y2, float aabb2_x1, float aabb2_y1, float aabb2_x2, float aabb2_y2)
{
    /* Before detect collision we need fix boxes input coords.
     * x2 must be greater x1, y2 must be greated y1 
     */
    float fixedAabb1_x1;
    float fixedAabb1_y1;
    float fixedAabb1_x2;
    float fixedAabb1_y2;
    float fixedAabb2_x1;
    float fixedAabb2_y1;
    float fixedAabb2_x2;
    float fixedAabb2_y2;
    
    if (aabb1_x2 > aabb1_x1) {
        fixedAabb1_x1 = aabb1_x1;
        fixedAabb1_x2 = aabb1_x2;
    } else {
        fixedAabb1_x1 = aabb1_x2;
        fixedAabb1_x2 = aabb1_x1;
    }
    
    if (aabb1_y2 > aabb1_y1) {
        fixedAabb1_y1 = aabb1_y1;
        fixedAabb1_y2 = aabb1_y2;
    } else {
        fixedAabb1_y1 = aabb1_y2;
        fixedAabb1_y2 = aabb1_y1;
    }
    
    if (aabb2_x2 > aabb2_x1) {
        fixedAabb2_x1 = aabb2_x1;
        fixedAabb2_x2 = aabb2_x2;
    } else {
        fixedAabb2_x1 = aabb2_x2;
        fixedAabb2_x2 = aabb2_x1;
    }
    
    if (aabb2_y2 > aabb2_y1) {
        fixedAabb2_y1 = aabb2_y1;
        fixedAabb2_y2 = aabb2_y2;
    } else {
        fixedAabb2_y1 = aabb2_y2;
        fixedAabb2_y2 = aabb2_y1;
    }
    
    if (fixedAabb1_x1 < fixedAabb2_x2 && 
     fixedAabb1_x2 > fixedAabb2_x1 &&
     fixedAabb1_y1 < fixedAabb2_y2 && 
     fixedAabb1_y2 > fixedAabb2_y1)
        return true;
        
    return false;
}

// bool Tzing_PointToCircle(float pointX, float pointX, float circleCenterX, 
 // float circleCenterY, float circleRadius)
// {
    
// }