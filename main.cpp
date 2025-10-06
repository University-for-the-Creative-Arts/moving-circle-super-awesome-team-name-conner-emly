#include <iostream>
#include <raylib.h>

using namespace std;

// Commented code contains functionality for a DVD logo texture to replace the circle
int main() {


    // Initializes window, with a defined screen size and window name
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Super Awesome Circle");
    SetTargetFPS(120);
    
    // Sets initial position to center of the screen
    int hPos = screenWidth / 2;
    int vPos = screenHeight / 2;

    // Sets initial position for red circle to center of the screen as well as its radius
    int locX = screenWidth / 2;
    int locY = screenHeight / 2;
    int moveCircRadius = 20;

    // Sets the radius (aka size) of the circle to be drawn
    //const int circleRadius = 25;

    // Sets the speed in pixels per frame
    int hSpeed = 2;
    int vSpeed = 2;

    // True values correspond to right/down, false values correspond to left/up
    bool hDir = 1;
    bool vDir = 1;

    Texture2D dvd = LoadTexture("dvd_logo.png");

    // Main game loop
    while (!WindowShouldClose()) {

        //Input gathering
        if (locX >= moveCircRadius && locX <= screenWidth - moveCircRadius && locY >= moveCircRadius && locY <= screenHeight - moveCircRadius) {
            if(IsKeyDown(KEY_S)) locY += 10;
            if(IsKeyDown(KEY_A)) locX -= 10;
            if(IsKeyDown(KEY_W)) locY -= 10;
            if(IsKeyDown(KEY_D)) locX += 10;       
        }
        else {
            if (locX < moveCircRadius) {
                locX = moveCircRadius;
            }
            if (locY < moveCircRadius) {
                locY = moveCircRadius;
            } 
            if (locX > screenWidth - moveCircRadius) {
                locX = screenWidth - moveCircRadius;
            } 
            if (locY > screenHeight - moveCircRadius) {
                locY = screenHeight - moveCircRadius;
            } 
        }

        // Clears the screen before drawing begins
        ClearBackground(BLUE);
        BeginDrawing();

        DrawCircle(locX,locY,moveCircRadius,RED);

        // Swaps direction when sides of the screen are hit
        /*if ((hDir && (hPos >= (screenWidth - circleRadius))) || (!hDir && (hPos <= circleRadius))) {
            hDir = !hDir;
            cout << "Horizontal swapped!" << endl;
        }
        if ((vDir && vPos >= (screenHeight - circleRadius)) || (!vDir && vPos <= circleRadius)) {
            vDir = !vDir;
            cout << "Vertical swapped!" << endl;
        }*/

        // Same as above for the DVD logo
        if ((hDir && (hPos >= (screenWidth - dvd.width))) || (!hDir && (hPos <= 0))) {
            hDir = !hDir;
            cout << "Horizontal swapped!" << endl;
        }
        if ((vDir && vPos >= (screenHeight - dvd.height)) || (!vDir && vPos <= 0)) {
            vDir = !vDir;
            cout << "Vertical swapped!" << endl;
        }

        // Increments horizontal position by the defined speeds multiplied by positive/negative 1 depending on the current directions
        hPos += hSpeed * (hDir ? 1 : -1);
        vPos += vSpeed * (vDir ? 1 : -1);

        // Draws a white circle relative to the defined positions and radius
        //DrawCircle(hPos, vPos, circleRadius, WHITE);

        // Same as above for the DVD logo
        DrawTexture(dvd, hPos, vPos, WHITE);

        // Debug code to display current direction and position info
        /*if (hDir) { DrawText("Right", 0, 0, 8, WHITE);}
        else { DrawText("Left", 0, 0, 8, WHITE);}
        if (vDir) { DrawText("Down", 0, 16, 8, WHITE);}
        else { DrawText("Up", 0, 16, 8, WHITE);}
        DrawText(TextFormat("X: %d", hPos), 0, 32, 8, WHITE);
        DrawText(TextFormat("Y: %d", vPos), 0, 48, 8, WHITE);*/

        // Stops the program from drawing, self explanatory
        EndDrawing();
    }

    // Once while loop is exited, close window and return int
    CloseWindow();
    return 0;
}