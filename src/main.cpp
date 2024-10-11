#include "ball.h"
#include "raylib.h" // Ensure you include the Raylib header

// Main function
int main(int argc, char** argv) 
{   
    // Screen dimensions
    constexpr int screen_width = 800;
    constexpr int screen_height = 600;

    // Application title
    const char* app_title = "My program";
    
    // Create a new Ball object
    Ball *ball = new Ball();
    
    // Initialize the window
    InitWindow(screen_width, screen_height, app_title);
    SetTargetFPS(60); // Set the frame rate to 60 frames per second
    
    // Main game loop
    while (!WindowShouldClose()) // Loop until the window should close
    {
        // Update the ball's state
        ball->Update();
        
        // Start drawing
        BeginDrawing();
            ClearBackground(DARKGRAY); // Clear the screen with a dark gray color

            // Display the number of bounces
            const char* text = TextFormat("Bounces: %d", ball->Bounces());
            int text_width = MeasureText(text, 28);
            DrawText(text, (screen_width - text_width) / 2, (screen_height - 28) / 2, 28, WHITE);
            
            // Draw the ball
            ball->Draw();
        EndDrawing(); // End drawing
    }
    
    // Close the window and clean up
    CloseWindow();
    
    // Delete the ball object to free memory
    delete ball;
}
