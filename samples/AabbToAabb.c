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
    float aabb1_x1 = 100;
    float aabb1_y1 = 100;
    float aabb1_x2 = 150;
    float aabb1_y2 = 150;
    float aabb2_x1 = 200;
    float aabb2_y1 = 200;
    float aabb2_x2 = 250;
    float aabb2_y2 = 250;
    TPixel aabbColor;

    screen = tigrWindow(640, 480, "Tzing AABB to AABB test", TIGR_FIXED);
    
    while (!quit) {
        tigrMouse(screen, &mouseX, &mouseY, &mouseButtons);
        aabb2_x1 = mouseX - 25;
        aabb2_x2 = mouseX + 25;
        aabb2_y1 = mouseY - 25;
        aabb2_y2 = mouseY + 25;
        
        if (tigrKeyDown(screen, TK_ESCAPE)) {
            quit = true;
        }
        
        if (tigrKeyHeld(screen, 'A')) {
            aabb1_x1--;
            aabb1_x2--;
        }
        if (tigrKeyHeld(screen, 'D')) {
            aabb1_x1++;
            aabb1_x2++;
        }
        if (tigrKeyHeld(screen, 'W')) {
            aabb1_y1--;
            aabb1_y2--;
        }
        if (tigrKeyHeld(screen, 'S')) {
            aabb1_y1++;
            aabb1_y2++;
        }
        
        if (Tzing_AabbToAabb(aabb1_x1, aabb1_y1, aabb1_x2, aabb1_y2, aabb2_x1, 
         aabb2_y1, aabb2_x2, aabb2_y2))
            aabbColor = tigrRGB(0x88, 0x00, 0x00);
        else
            aabbColor = tigrRGB(0x00, 0x88, 0x00);
        
        tigrClear(screen, tigrRGB(0x00, 0x00, 0x00));
        
        tigrRect(screen, aabb1_x1, aabb1_y1, aabb1_x2 - aabb1_x1, 
         aabb1_y2 - aabb1_y1, aabbColor);
        tigrRect(screen, aabb2_x1, aabb2_y1, aabb2_x2 - aabb2_x1, 
         aabb2_y2 - aabb2_y1, aabbColor);
        
        tigrPrint(screen, tfont, 16, 16, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "WASD for move AABB 1");
        tigrPrint(screen, tfont, 16, 32, tigrRGB(0x88, 0x88, 0x88), "%s", 
         "Mouse for move AABB 2");
        
        tigrUpdate(screen);
    }
    
    return 0;
}