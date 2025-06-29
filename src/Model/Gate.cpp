/**
 * @file Gate.cpp
 * @author Nandros (nathan.andre.etudiant@gmail.com)
 * @brief Class used to represent all gates. A Gates is an atomical element, you can't have 
 * @version 0.1
 * @date 2025-05-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

// --------------------------------------------------------------------------------
//      Includes
// --------------------------------------------------------------------------------
#include "Gate.hpp" // Always first

// Cpp standards
#include <cstdint> // Mendatory
#include <cstring> // Mendatory

// Lib Specific
// # Raylib     (e.g.)
#include "raymath.h"

// # ImGui      (e.g.)

// # ImGui      (e.g.)

// Project
// #include "Gate.hpp"

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
//      Public Methods
// --------------------------------------------------------------------------------

Gate::Gate(std::string id) : id(id) {

    this->shapeBox = {
        .x = 0,
        .y = 0,
        .width = GATE_MINIMAL_WIDTH,
        .height = GATE_MINIMAL_HEIGHT
    };

    this->color = (Color) { 29, 143, 215, 255 };
    this->fontSize = 25;
}

Gate::~Gate() {

}

/**
 * @brief Return rectangle hitbox, with position adjusted with the camera
 * 
 * @param camera 
 * @return Rectangle 
 */
Rectangle Gate::getHitBox(Camera2D camera) {

    Vector2 pos = {
        .x = this->shapeBox.x,
        .y = this->shapeBox.y
    };
    Vector2 dim = {
        .x = this->shapeBox.width,
        .y = this->shapeBox.height,
    };

    // Change pos from camera pov
    pos = GetWorldToScreen2D(pos, camera);
    // Change size from camera pov
    dim = Vector2Scale(dim, camera.zoom);

    Rectangle ret = {
        .x = pos.x,
        .y = pos.y,
        .width = dim.x,
        .height = dim.y
    };

    return ret;
}

void Gate::drag(Vector2 vect, Camera2D cam) {

    Vector2 delta = vect;
    delta = Vector2Scale(delta, 
        1.0f/cam.zoom);
    Vector2 pos = {
        .x = this->shapeBox.x,
        .y = this->shapeBox.y,
    };

    pos = Vector2Add(pos, delta);

    this->shapeBox.x = pos.x;
    this->shapeBox.y = pos.y;
}

/**
 * @brief Draw the shape of the gate.
 * 
 */
void Gate::draw(void) {
    // TODO : Find a way to save shape in structure to make Another class draw it instead of the model.

    const float rectPercentage = 0.70;

    float rectWidth = this->shapeBox.width * rectPercentage;
    float midHeight = this->shapeBox.height/2;
    uint8_t lineWidth = 4;
    float midLineWidth = lineWidth/2;


    Vector2 circleCenter = {
        .x = this->shapeBox.x + rectWidth,
        .y = this->shapeBox.y + midHeight,
    };

    DrawRectangleRec(this->shapeBox, (Color) {200, 250, 255, 100});

    // Fill
    DrawRectangle(this->shapeBox.x, this->shapeBox.y, rectWidth, this->shapeBox.height, this->color);
    DrawCircleV(circleCenter, midHeight, this->color);

    // Contour
    // Horizontal Top
    DrawRectangle(this->shapeBox.x, this->shapeBox.y - midLineWidth, rectWidth, lineWidth, BLACK);
    // Horizontal Bottom
    DrawRectangle(this->shapeBox.x, this->shapeBox.y + this->shapeBox.height - midLineWidth, rectWidth, lineWidth, BLACK);
    // Vertical Left
    DrawRectangle(this->shapeBox.x, this->shapeBox.y, lineWidth, this->shapeBox.height, BLACK);
    DrawRing(circleCenter, midHeight - midLineWidth, midHeight + midLineWidth, 90, -90, 25, BLACK);

    uint16_t textWidth = MeasureText(this->id.c_str(), this->fontSize);
    DrawText(this->id.c_str(), this->shapeBox.x + (this->shapeBox.height / 2) - (textWidth >> 1), this->shapeBox.y + (this->shapeBox.width / 2) - (this->fontSize >> 1), this->fontSize, BLACK);

    return;
}


std::string Gate::getId(void) {
    return this->id;
}