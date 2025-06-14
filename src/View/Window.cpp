/**
 * @file Window.cpp
 * @author Nandros
 * @brief Window is used to handle the application window.
 * @version 0.1
 * @date 2025-05-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

// --------------------------------------------------------------------------------
//      Includes
// --------------------------------------------------------------------------------
#include "Window.hpp"

// Cpp standards
#include <cstdint> // Mendatory
#include <cstring> // Mendatory

#include <iostream>

// Lib Specific
// # Raylib

// Project

// --------------------------------------------------------------------------------
//      Macros
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      Types def
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      Constants
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      Globals
// --------------------------------------------------------------------------------

Window* pinstance_ = {nullptr};

// --------------------------------------------------------------------------------
//      Prototypes
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      File's functions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      Private Methods
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      Protected Methods
// --------------------------------------------------------------------------------
Window::Window(void) {
}

Window::~Window() {
    
}
// --------------------------------------------------------------------------------
//      Public Methods
// --------------------------------------------------------------------------------

Window* Window::GetInstance(void) {
    if (pinstance_ == nullptr) {
        pinstance_ = new Window();
    }
    
    return pinstance_;
}

void Window::init(WindowConfig conf) {
    // TODO : Should save if singleton has been init ?

    this->conf = conf;  // Save Config

    // Init window
    InitWindow(this->conf.width, this->conf.height, "NandLogic");
    
    std::cout << "Set Window Resizable" << "\n";
    // SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_UNDECORATED);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    this->camera.zoom = 1.0f;

    SetTargetFPS(this->conf.targetFPS);

    return;
}

void Window::close(void) {
    CloseWindow();
}

bool Window::shouldClose(void) {
    return WindowShouldClose();
}

void Window::drawCircle(void) {
    
}

void Window::update(void) {
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyPressed(KEY_ONE)) {
        this->zoomMode = 0;
    }
    else if (IsKeyPressed(KEY_TWO)) {
        this->zoomMode = 1;
    }
    
    // Translate based on mouse right click
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/this->camera.zoom);
        this->camera.target = Vector2Add(this->camera.target, delta);
    }

    if (this->zoomMode == 0)
    {
        // Zoom based on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {
            // Get the world point that is under the mouse
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), this->camera);

            // Set the offset to where the mouse is
            this->camera.offset = GetMousePosition();

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            this->camera.target = mouseWorldPos;

            // Zoom increment
            // Uses log scaling to provide consistent zoom speed
            float scale = 0.2f*wheel;
            this->camera.zoom = Clamp(expf(logf(this->camera.zoom)+scale), 0.125f, 64.0f);
        }
    }
    else
    {
        // Zoom based on mouse right click
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            // Get the world point that is under the mouse
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), this->camera);

            // Set the offset to where the mouse is
            this->camera.offset = GetMousePosition();

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            this->camera.target = mouseWorldPos;
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            // Zoom increment
            // Uses log scaling to provide consistent zoom speed
            float deltaX = GetMouseDelta().x;
            float scale = 0.005f*deltaX;
            this->camera.zoom = Clamp(expf(logf(this->camera.zoom)+scale), 0.125f, 64.0f);
        }
    }
    BeginDrawing();
        ClearBackground(this->backgroundColor);

        BeginMode2D(this->camera);

            // Draw the 3d grid, rotated 90 degrees and centered around 0,0 
            // just so we have something in the XY plane
            rlPushMatrix();
                rlTranslatef(0, 25*50, 0);
                rlRotatef(90, 1, 0, 0);
                DrawGrid(100, 50);
            rlPopMatrix();

            // Draw a reference circle
            DrawCircle(GetScreenWidth()/2, GetScreenHeight()/2, 50, MAROON);
            
        EndMode2D();
        
        // Draw mouse reference
        //Vector2 mousePos = GetWorldToScreen2D(GetMousePosition(), camera)
        DrawCircleV(GetMousePosition(), 4, DARKGRAY);
        DrawTextEx(GetFontDefault(), TextFormat("[%i, %i]", GetMouseX(), GetMouseY()), 
            Vector2Add(GetMousePosition(), (Vector2){ -44, -24 }), 20, 2, BLACK);

        // DrawText("[1][2] Select mouse zoom mode (Wheel or Move)", 20, 20, 20, DARKGRAY);
        // if (zoomMode == 0) DrawText("Mouse left button drag to move, mouse wheel to zoom", 20, 50, 20, DARKGRAY);
        // else DrawText("Mouse left button drag to move, mouse press and move to zoom", 20, 50, 20, DARKGRAY);
    
    EndDrawing();
}

// --------------------------------------------------------------------------------
//      Getter & Setter
// --------------------------------------------------------------------------------
void Window::setConfiguration(WindowConfig conf) {
    this->conf = conf;
    return;
}

void Window::getConfiguration(WindowConfig* conf) const {
    *conf = this->conf;
    return;
}
