#include <stdlib.h>
#include <stdbool.h>
#include "tzing.h"
#include "tigr.h"
#include "DrawCircle.h"

int main(int argc, char **argv)
{
    Tigr *screen;
    bool quit = false;
    int mouseX;
    int mouseY;
    int mouseButtons;
    float circleX = 200;
    float circleY = 200;
    float circleRadius = 32;
    float pointX;
    float pointY;
    TPixel color;

    screen = tigrWindow(640, 480, "Tzing AABB to AABB test", TIGR_FIXED);
    
    while (!quit) {
        tigrMouse(screen, &mouseX, &mouseY, &mouseButtons);
        pointX = mouseX;
        pointY = mouseY;
        
        if (tigrKeyDown(screen, TK_ESCAPE)) {
            quit = true;
        }
        
        if (tigrKeyHeld(screen, 'A')) {
            circleX--;
        }
        if (tigrKeyHeld(screen, 'D')) {
            circleX++;
        }
        if (tigrKeyHeld(screen, 'W')) {
            circleY--;
        }
        if (tigrKeyHeld(screen, 'S')) {
            circleY++;
        }
        if (tigrKeyHeld(screen, TK_MINUS)) {
            if (circleRadius > 8)
                circleRadius--;
        }
        if (tigrKeyHeld(screen, TK_EQUALS)) {
            if (circleRadius < 64)
                circleRadius++;
        }
        
        if (Tzing_PointToCircle(pointX, pointY, circleX, circleY, circleRadius))
            color = tigrRGB(0x88, 0x00, 0x00);
        else
            color = tigrRGB(0x00, 0x88, 0x00);
        
        tigrClear(screen, tigrRGB(0x00, 0x00, 0x00));
        
        DrawCircle(screen, circleX, circleY, circleRadius, color);
        
        tigrPrint(screen, tfont, 16, 16, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "WASD for move circle");
        tigrPrint(screen, tfont, 16, 32, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "- for size down circle");
        tigrPrint(screen, tfont, 16, 48, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "+ for size up circle");
        tigrPrint(screen, tfont, 16, 64, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "Mouse for move point");
        
        tigrUpdate(screen);
    }
    
    return 0;
}