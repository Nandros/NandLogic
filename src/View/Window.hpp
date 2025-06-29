/**
 * @file Window.hpp
 * @author Nandros
 * @brief Window is used to handle the application window.
 * @version 0.1
 * @date 2025-05-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_
// --------------------------------------------------------------------------------
//      Includes
// --------------------------------------------------------------------------------
// Cpp standards
#include <cstdint> // Mendatory
#include <cstring> // Mendatory
#include <vector>

// Lib Specific
// # Raylib
#include "raylib.h"
#include "GLFW/glfw3.h"

#include "rlgl.h"
#include "raymath.h"

// Project
#include "Model/Gate.hpp"
#include "Model/Draggable.hpp"

// --------------------------------------------------------------------------------
//      Macros
// --------------------------------------------------------------------------------

#define WINDOW_ZOOM_MAX_WIDTH
#define WINDOW_ZOOM_MAX_HEIGHT

// --------------------------------------------------------------------------------
//      Types def
// --------------------------------------------------------------------------------

typedef struct {
    
    uint32_t width;
    uint32_t height;

    uint8_t targetFPS;

} WindowConfig;


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

class Window : public Draggable
{
private:
    Color backgroundColor = LIGHTGRAY;
    Camera2D camera = {0};
    uint8_t zoomMode = 0; // 0-Mouse Wheel, 1-Mouse Move

    WindowConfig conf;

    std::vector<Gate*> gates;

protected:
    Window(void);
    ~Window();

public:
    // Needed for singleton
    Window(Window &other) = delete; // Not clonable
    void operator=(const Window &) = delete;    // Not assignable

    static Window* GetInstance(void);

    void init(WindowConfig conf);
    void close(void);
    
    // Gate related methods
    void addGate(Gate* gate);
    void rmGate(Gate* gate);
    
    void drag(Vector2 vect, Camera2D cam);
    
    bool shouldClose(void);
    void drawCircle(void);
    void update(void);
    
    // ----- Getter & Setter -----
    void setConfiguration(WindowConfig conf);
    void getConfiguration(WindowConfig* conf) const;
    Camera2D* getCamera(void);
};

#endif  // _WINDOW_HPP_