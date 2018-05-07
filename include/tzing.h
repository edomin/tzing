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

#endif