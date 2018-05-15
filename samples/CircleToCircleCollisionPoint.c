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
    int mouseButtons = 0;
    float circle1_x = 200;
    float circle1_y = 200;
    float circle1_radius = 32;
    float circle2_x = 400;
    float circle2_y = 400;
    float circle2_radius = 32;
    TPixel circleColor = tigrRGB(0x00, 0x88, 0x00);
    TPixel collisionPointColor = tigrRGB(0xBB, 0x00, 0x00);
    bool collision;
    float collisionPointX;
    float collisionPointY;

    screen = tigrWindow(640, 480, "Tzing circle to circle collision point test", 
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
        
        collision = Tzing_CircleToCircleCollisionPoint(circle1_x, circle1_y, 
         circle1_radius, circle2_x, circle2_y, circle2_radius, &collisionPointX, 
         &collisionPointY);
        
        tigrClear(screen, tigrRGB(0x00, 0x00, 0x00));
        
        DrawCircle(screen, circle1_x, circle1_y, circle1_radius, circleColor);
        DrawCircle(screen, circle2_x, circle2_y, circle2_radius, circleColor);
        if (collision)
            DrawCircle(screen, collisionPointX, collisionPointY, 4, 
             collisionPointColor);
        
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
