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
#ifndef _INPUT_HANDLER_HPP_
#define _INPUT_HANDLER_HPP_
// --------------------------------------------------------------------------------
//      Includes
// --------------------------------------------------------------------------------
// Cpp standards
#include <cstdint> // Mendatory
#include <cstring> // Mendatory
#include <map>
#include <vector>

// Lib Specific
// # Raylib
#include "raylib.h"

// Project
// #include "Gate.hpp"

// --------------------------------------------------------------------------------
//      Macros
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      Types def
// --------------------------------------------------------------------------------

enum InputMouse {
    INPUT_MOUSE_BUTTON_NONE = 0,

    INPUT_MOUSE_BUTTON_LEFT,
    INPUT_MOUSE_BUTTON_RIGHT,
    INPUT_MOUSE_BUTTON_MIDDLE,

    INPUT_MOUSE_BUTTON_NB, // SHOULD BE THE LAST
};

enum InputEvent {
    INPUT_EVENT_PRESSED,
    INPUT_EVENT_DOWN,
    INPUT_EVENT_RELEASED,
};

/**
 * @brief Attached callback take as argument an InputEvent.
 * 
 * Should return true if it has used the event to do an action.
 * 
 */
typedef bool (*funcAttachCallback)(InputEvent);

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
//      Classes
// --------------------------------------------------------------------------------

class InputHandler
{
private:
    
    // TODO : Avoir une liste des bouton appuy dans l'odre du plus vieux vers le plus récent.
    // TODO : Attacher des fonction sur certain évenement / touches

    std::map<MouseButton, std::vector<funcAttachCallback>> attachedCallback;

protected:
    InputHandler(/* args */);
    ~InputHandler();

public:
    // Needed for singleton
    InputHandler(InputHandler &other) = delete; // Not clonable
    void operator=(const InputHandler &) = delete;    // Not assignable

    static InputHandler* GetInstance(void);

    void attach(MouseButton mouseButton, funcAttachCallback callback);
    void detach(MouseButton mouseButton, funcAttachCallback callback);

    void tickKeyboard(void);
    void tickMouse(void);

};

#endif  // _INPUT_HANDLER_HPP_