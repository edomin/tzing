#include "DrawCircle.h"

void DrawCircle(Tigr *bmp, float x, float y, float radius, TPixel color)
{
    int   i;
    float oldX;
    float oldY;
    float newX;
    float newY;
    float startX;
    float startY;
    float currentAngle;

    currentAngle = 0.0f;
    startX = radius * cosf((float)M_PI * 2);
    startY = radius * sinf((float)M_PI * 2);
    for (i = 0; i < 32; i++)
    {
        if (i != 0) {
            currentAngle = ((float)M_PI * 2) / 32 * i;
            oldX = newX;
            oldY = newY;
            newX = radius * cosf(currentAngle);
            newY = radius * sinf(currentAngle);
        } else {
            currentAngle = 0.0f;
            oldX = startX;
            oldY = startY;
            newX = radius * cosf(currentAngle);
            newY = radius * sinf(currentAngle);
        }
        tigrLine(bmp, x + oldX, y + oldY, x + newX, y + newY, color);
    }
    tigrLine(bmp, x + newX, y + newY, x + startX, y + startY, color);
}