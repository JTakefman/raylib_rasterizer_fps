/*******************************************************************************************
*
*   raylib [core] example - 3d camera first person
*
*   Example originally created with raylib 1.3, last time updated with raylib 1.3
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2015-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "rcamera.h"

#define MAX_COLUMNS 20
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

void DrawWireFrameTriangle(Vector2 p0, Vector2 p1, Vector2 p2, Color color) {

    DrawLineV(p0, p1, color);
    DrawLineV(p1, p2, color);
    DrawLineV(p2, p0, color);
}



void FillTriangle(Vector2 p0, Vector2 p1, Vector2 p2, Color color) {

    float maxY, minY = p0.y;
    float maxX, minX = p0.x;

    maxY = max(maxY, p1.y); maxY = max(maxY, p2.y);
    minY = min(minY, p1.y); minY = min(minY, p2.y);


}

int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 675;

    Vector2 p1 = (Vector2){0, 0};
    Vector2 p2 = (Vector2){800, 50};

    Vector2 p3 = (Vector2){1100, 550};

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");


    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
         BeginDrawing();

            DrawWireFrameTriangle(p1, p2, p3, GREEN);
            
         EndDrawing();
        
    }
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


