#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "tzing.h"
#include "tigr.h"
#include "Common.h"
#include "DrawCircle.h"

int main(int argc, char **argv)
{
    Tigr *screen;
    bool quit = false;
    int mouseX;
    int mouseY;
    int mouseButtons = 0;
    float circle1_x = 320;
    float circle1_y = 240;
    float circle1_radius = 32;
    float circle2_x = 400;
    float circle2_y = 400;
    float circle2_radius = 32;
    TPixel color;
    bool collision;
    float penetrationAngle;
    float penetrationDepth;

    screen = tigrWindow(640, 480, "Tzing circle to circle penetration test", 
     TIGR_FIXED);
    
    while (!quit) {
        tigrMouse(screen, &mouseX, &mouseY, &mouseButtons);
        
        circle2_x = mouseX;
        circle2_y = mouseY;
        
        if (tigrKeyDown(screen, TK_ESCAPE)) {
            quit = true;
        }
        
        if (tigrKeyHeld(screen, 'A')) {
            circle1_x--;
        }
        if (tigrKeyHeld(screen, 'D')) {
            circle1_x++;
        }
        if (tigrKeyHeld(screen, 'W')) {
            circle1_y--;
        }
        if (tigrKeyHeld(screen, 'S')) {
            circle1_y++;
        }
        if (tigrKeyHeld(screen, TK_MINUS)) {
            if (circle1_radius > 8)
                circle1_radius--;
        }
        if (tigrKeyHeld(screen, TK_EQUALS)) {
            if (circle1_radius < 64)
                circle1_radius++;
        }
        if ((mouseButtons & 0x01) == 0x01) {
            if (circle2_radius > 8)
                circle2_radius--;
        }
        if ((mouseButtons & 0x04) == 0x04) {
            if (circle2_radius < 64)
                circle2_radius++;
        }
        
        collision = Tzing_CircleToCirclePenetration(circle2_x, circle2_y, 
         circle2_radius, circle1_x, circle1_y, circle1_radius, 
         &penetrationAngle, &penetrationDepth);
        if (collision) {
            circle1_x += penetrationDepth * cosf((float)M_PI - 
             penetrationAngle * SAMPLE_DEGREE);
            circle1_y += penetrationDepth * sinf((float)M_PI - 
             penetrationAngle * SAMPLE_DEGREE);
            color = tigrRGB(0x88, 0x00, 0x00);
        }
        else
            color = tigrRGB(0x00, 0x88, 0x00);
        
        tigrClear(screen, tigrRGB(0x00, 0x00, 0x00));
        
        DrawCircle(screen, circle1_x, circle1_y, circle1_radius, color);
        DrawCircle(screen, circle2_x, circle2_y, circle2_radius, color);
        
        tigrPrint(screen, tfont, 16, 16, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "WASD for move first circle");
        tigrPrint(screen, tfont, 16, 32, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "- for size down first circle");
        tigrPrint(screen, tfont, 16, 48, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "+ for size up first circle");
        tigrPrint(screen, tfont, 16, 64, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "Mouse for move second circle");
        tigrPrint(screen, tfont, 16, 80, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "Left Mouse Button for size down second circle");
        tigrPrint(screen, tfont, 16, 96, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "Right Mouse Button for size up second circle");
        
        tigrUpdate(screen);
    }
    
    return 0;
}
