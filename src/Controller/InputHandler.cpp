/**
 * @file InputHandler.hpp
 * @author Nathan ANDRE
 * @brief Class that take the inputs and call attached fonction to an event
 * @version 0.1
 * @date 2025-05-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

// --------------------------------------------------------------------------------
//      Includes
// --------------------------------------------------------------------------------
#include "InputHandler.hpp" // Always first

// Cpp standards
#include <cstdint> // Mendatory
#include <cstring> // Mendatory
#include <iostream>

// Lib Specific
// # Raylib

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

const MouseButton mouseButtonList[] = {
    MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_RIGHT
};
const uint8_t mouseButtonListSize = 2;

// --------------------------------------------------------------------------------
//      Globals
// --------------------------------------------------------------------------------

InputHandler* pInputInstance_ = nullptr;

// --------------------------------------------------------------------------------
//      Prototypes
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      File's functions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      Private Methods
// --------------------------------------------------------------------------------

InputHandler::InputHandler(/* args */)
{
    SetGesturesEnabled(GESTURE_DRAG);

}

InputHandler::~InputHandler()
{

}

// --------------------------------------------------------------------------------
//      Public Methods
// --------------------------------------------------------------------------------

InputHandler* InputHandler::GetInstance(void) {
    if (pInputInstance_ == nullptr) {
        pInputInstance_ = new InputHandler();
    }
    
    return pInputInstance_;
}

void InputHandler::attach(MouseButton mouseButton, funcAttachCallback callback) {

    this->attachedCallback[mouseButton].push_back(callback);

}

void InputHandler::detach(MouseButton mouseButton, funcAttachCallback callback) {

    for (uint16_t i = 0; i < this->attachedCallback[mouseButton].size(); i++) {
        if (this->attachedCallback[mouseButton].at(i) == callback) {
            this->attachedCallback[mouseButton].erase(this->attachedCallback[mouseButton].begin() + i);
            break;
        }
    }
    
}

void InputHandler::tickKeyboard(void) {
    char c;
    int key;
    
    do {
        c = GetCharPressed();
        
        if (c) {
            std::cout << "Key pressed: " << c << "\n";
        } else {
            key = GetKeyPressed();

            if (key) {
                std::cout << "Key pressed: " << key << "\n";
            }
        }

    } while (c != 0);
    
}

void InputHandler::tickMouse(void) {

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        for (uint16_t i = 0; i < this->attachedCallback[MOUSE_BUTTON_LEFT].size(); i++) {
            this->attachedCallback[MOUSE_BUTTON_LEFT].at(i)(INPUT_EVENT_DOWN);
        }
    }
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (uint16_t i = 0; i < this->attachedCallback[MOUSE_BUTTON_LEFT].size(); i++) {
            this->attachedCallback[MOUSE_BUTTON_LEFT].at(i)(INPUT_EVENT_PRESSED);
        }
    }
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        for (uint16_t i = 0; i < this->attachedCallback[MOUSE_BUTTON_RIGHT].size(); i++) {
            this->attachedCallback[MOUSE_BUTTON_RIGHT].at(i)(INPUT_EVENT_PRESSED);
        }
    }
    
    return;
}
