#ifndef TZING_H
#define TZING_H

#include <stdbool.h>

#define TZING_VERSION 0x000000U
#define Tzing_VersionMajor() ((TZING_VERSION & 0xFF0000) >> 16)
#define Tzing_VersionMinor() ((TZING_VERSION & 0x00FF00) >> 8)
#define Tzing_VersionPatch() ((TZING_VERSION & 0x0000FF))

bool Tzing_AabbToAabb(float aabb1_x1, float aabb1_y1, float aabb1_x2, 
 float aabb1_y2, float aabb2_x1, float aabb2_y1, float aabb2_x2, 
 float aabb2_y2);
 
bool Tzing_PointToAabb(float pointX, float pointY, float aabb_x1, float aabb_y1,
 float aabb_x2, float aabb_y2);
 
bool Tzing_PointToCircle(float pointX, float pointY, float circleCenterX, 
 float circleCenterY, float circleRadius);

bool Tzing_CircleToCircle(float circle1_centerX, float circle1_centerY, 
 float circle1_radius, float circle2_centerX, float circle2_centerY, 
 float circle2_radius);
 
bool Tzing_CircleToCircleCollisionPoint(float circle1_centerX, 
 float circle1_centerY, float circle1_radius, float circle2_centerX, 
 float circle2_centerY, float circle2_radius, float *collisionPointX, 
 float *collisionPointY);
 
bool Tzing_CircleToCirclePenetration(float circle1_centerX, 
 float circle1_centerY, float circle1_radius, float circle2_centerX, 
 float circle2_centerY, float circle2_radius, float *angle, float *depth);
 
#endif
