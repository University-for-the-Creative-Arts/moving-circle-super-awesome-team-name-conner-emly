#include <iostream>
#include <raylib.h>

using namespace std;

class GameObject{
    public:
        int x;
        int y;

        GameObject(int _x, int _y){
            this -> x = _x;
            this -> y = _y;
        }
};

int main () {

    GameObject player(0,0);

    InitWindow(800,800,"Random super cool circle DLC expansion");
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        if(IsKeyDown(KEY_A)) player.x += -10;
        else if(IsKeyDown(KEY_S)) player.y += 10;
        else if(IsKeyDown(KEY_W)) player.y += -10;
        else if(IsKeyDown(KEY_D)) player.x += 10;



        BeginDrawing();
        ClearBackground(BLUE);
        DrawCircle(player.x,player.y,20,WHITE);
        EndDrawing();
    }

    CloseWindow();
}



