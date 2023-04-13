
#include "raylib.h"
#include "rcamera.h"
#include "stdio.h"
#define MAX_COLUMNS 20
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


//Line of form ax + by + c = 0

typedef struct LineMXB {
    float m;
    float b;
} LineMXB;

typedef struct Line {
    float a;
    float b;
    float c;
}Line;

const int screenWidth = 1200;
const int screenHeight = 675;

Vector2 centerScreen = {screenWidth/2.0f, screenHeight/2.0f};


void DrawWireFrameTriangle(Vector2 p0, Vector2 p1, Vector2 p2, Color color); //Draws outline of triangle from given points.
void RasterDrawPlane(int width, int height); //Draws plane 
Vector2 MidToLeftCoords(Vector2 p); //Converts top-left origin coordinates to centered origin.
Vector2 LeftToMidCoords(Vector2 p); //Converts centered origin coordinates to top-left origin.
void DrawMid(Vector2 p0, Vector2 p1, Color color); //Draws line based on mid-centered origin points.

Line convertToLine(Vector2 p0, Vector2 p1); //Convert to ponits to a line.
Vector2 getPoi(Line l1, Line l2);
Vector2 getPoiMXB(LineMXB l1, LineMXB l2);

Line MXBtoABC(LineMXB l) {
    return (Line){(0-l.m), 1, (0-l.b)};
}

//See the following for reference: https://www.cuemath.com/point-of-intersection-formula/
Vector2 getPoi(Line l1, Line l2) {

    float x = ( (l1.b*l2.c) - (l2.b*l1.c) ) / ( (l1.a*l2.b) - (l2.a*l1.b) );

    float y = ( (l2.a*l1.c) - (l1.a*l2.c) ) / ( (l1.a*l2.b) - (l2.a*l1.b) );

    return (Vector2){x, y};
}

Vector2 getPoiMXB(LineMXB l1, LineMXB l2) {
    return getPoi( MXBtoABC(l1), MXBtoABC(l2) );
}


void printLineMXB(Line l) {
    printf("line of form: y = %f + %f \n", l.a, l.c);
}

void printLineABC(Line l) {
    printf("line of form: %fx + %fy + %f = 0 \n", l.a, l.b, l.c);
}

Line convertToLine(Vector2 p0, Vector2 p1) {

    float slope = (p1.y - p0.y) / (p1.x - p0.x);
    
    return (Line) {slope, 1, (p1.y - (slope*p1.x))};

}


void DrawWireFrameTriangle(Vector2 p0, Vector2 p1, Vector2 p2, Color color) {

    DrawLineV(p0, p1, color);
    DrawLineV(p1, p2, color);
    DrawLineV(p2, p0, color);
}

/*

void FillTriangle(Vector2 p0, Vector2 p1, Vector2 p2, Color color) {

    float maxY, minY = p0.y;
    float maxX, minX = p0.x;

    maxY = max(maxY, p1.y); maxY = max(maxY, p2.y);
    minY = min(minY, p1.y); minY = min(minY, p2.y);

}*/


void RasterDrawPlane(int width, int height) {

    Vector2 p1 = (Vector2){width/2.0f, height};
    Vector2 p2 = (Vector2){width/2.0f, 0};

    Vector2 p3 = (Vector2){0, height/2.0f};
    Vector2 p4 = (Vector2){width, height/2.0f};

    DrawLineV(p1, p2, WHITE);
    DrawLineV(p3, p4, WHITE);
    
}

Vector2 MidToLeftCoords(Vector2 p) {
    return (Vector2){screenWidth/2.0f + p.x, screenHeight/2.0f - p.y};
}

Vector2 LeftToMidCoords(Vector2 p) {

    return (Vector2){p.x - (screenWidth/2.0f), p.y - (screenHeight/2.0f)};
}

void DrawMid(Vector2 p0, Vector2 p1, Color color) {
    Vector2 lp0 = MidToLeftCoords(p0);
    Vector2 lp1 = MidToLeftCoords(p1);

    DrawLineV(lp0, lp1, color);
}
