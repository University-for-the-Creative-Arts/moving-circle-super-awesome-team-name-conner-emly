#include <iostream>
#include <raylib.h>

using namespace std;



int main () {
    int LocX = 0;
    int LocY = 0;

    InitWindow(800,800,"Random super cool circle DLC expansion");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_A)) LocX += -10;
        else if(IsKeyDown(KEY_S)) LocY += 10;
        else if(IsKeyDown(KEY_W)) LocY += -10;
        else if(IsKeyDown(KEY_D)) LocX += 10;


        BeginDrawing();
        ClearBackground(BLUE);
        DrawCircle(LocX,LocY,20,WHITE);
        EndDrawing();
    }

    CloseWindow();
}



