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
#include "utility.c"

int main(void)
{  
    char args = 'c';
    Vector2 p0 = (Vector2){0, 0};
    Vector2 p1 = (Vector2){0, 300};
    Vector2 p2 = (Vector2){300, 150};

    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");

    
    while (!WindowShouldClose() && args != 'q')        // Detect window close button or ESC key
    {
         BeginDrawing();
            ClearBackground(BLACK);
            DrawWireFrameTriangle(p0, p1, p2, RED);
            DrawWireFrameTriangleMXB(p0, p1, p2, BLUE);
            
            FillTriangle(p0,p1,p2, RED);
            FillTriangle(MidToLeftCoords(p0),MidToLeftCoords(p1),MidToLeftCoords(p2), PURPLE);

         EndDrawing();

        //printf("\n\n enter any character: ");
        //scanf("%c", &args);
        
    }
    
    //--------------------------------------------------------------------------------------
    //CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


