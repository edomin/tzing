#include <stdlib.h>
#include <stdbool.h>
#include "tzing.h"
#include "tigr.h"

int main(int argc, char **argv)
{
    Tigr *screen;
    bool quit = false;
    int mouseX;
    int mouseY;
    int mouseButtons;
    float aabb_x1 = 100;
    float aabb_y1 = 100;
    float aabb_x2 = 150;
    float aabb_y2 = 150;
    TPixel aabbColor;

    screen = tigrWindow(640, 480, "Tzing point to AABB test", TIGR_FIXED);
    
    while (!quit) {
        tigrMouse(screen, &mouseX, &mouseY, &mouseButtons);
        
        if (tigrKeyDown(screen, TK_ESCAPE)) {
            quit = true;
        }
        
        if (tigrKeyHeld(screen, 'A')) {
            aabb_x1--;
            aabb_x2--;
        }
        if (tigrKeyHeld(screen, 'D')) {
            aabb_x1++;
            aabb_x2++;
        }
        if (tigrKeyHeld(screen, 'W')) {
            aabb_y1--;
            aabb_y2--;
        }
        if (tigrKeyHeld(screen, 'S')) {
            aabb_y1++;
            aabb_y2++;
        }
        
        if (
         Tzing_PointToAabb(mouseX, mouseY, aabb_x1, aabb_y1, aabb_x2, aabb_y2))
            aabbColor = tigrRGB(0x88, 0x00, 0x00);
        else
            aabbColor = tigrRGB(0x00, 0x88, 0x00);
        
        tigrClear(screen, tigrRGB(0x00, 0x00, 0x00));
        
        tigrRect(screen, aabb_x1, aabb_y1, aabb_x2 - aabb_x1, 
         aabb_y2 - aabb_y1, aabbColor);
        
        tigrPrint(screen, tfont, 16, 16, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "WASD for move AABB");
        tigrPrint(screen, tfont, 16, 32, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "Mouse for move point");
        
        tigrUpdate(screen);
    }
    
    return 0;
}
