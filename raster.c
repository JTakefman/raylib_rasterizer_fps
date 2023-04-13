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
    Vector2 p0 = (Vector2){0, 3};
    Vector2 p1 = (Vector2){200, 500};

    printLineABC(convertToLine(p0, p1));
    printLineMXB(convertToLine(p0, p1));


    LineMXB l1 = (LineMXB){-3, 2};
    LineMXB l2 = (LineMXB){0, 8.3};

    Vector2 testVec = getPoiMXB(l1, l2);

    printf("Poi of lines is    x: %f     y:   %f", testVec.x, testVec.y);

    printf("enter any character");

    scanf("%c", &args);


    /*
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");

    
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
         BeginDrawing();
            RasterDrawPlane(screenWidth, screenHeight);
            Vector2 p0 = (Vector2){0, 0};
            Vector2 p1 = (Vector2){500, 200};
            DrawMid(p0, p1, RED);
            DrawLineEx(p0, p1, 3.0, BLUE);

            Line l = convertToLine(LeftToMidCoords(p0), LeftToMidCoords(p1));

            printLineABC(l);
            printLineMXB(l);
         EndDrawing();
        
    }*/
    //--------------------------------------------------------------------------------------
    //CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


