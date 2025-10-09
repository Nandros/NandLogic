/**
 * @file __template.hpp
 * @author your name (you@domain.com)
 * @brief Template for ciles
 * @version 0.1
 * @date 2025-05-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _CONTEXT_HPP_
#define _CONTEXT_HPP_
// --------------------------------------------------------------------------------
//      Includes
// --------------------------------------------------------------------------------
// Cpp standards
#include <cstdint> // Mendatory
#include <cstring> // Mendatory
#include <vector>

// Lib Specific
// # Raylib     (e.g.)
#include "raylib.h"

// # ImGui      (e.g.)
// #include "..."
// #include "..."
// #include "..."

// # ImGui      (e.g.)
// #include "..."

// Project
#include "Model/Drawable.hpp"

// --------------------------------------------------------------------------------
//      Macros
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//      Types def
// --------------------------------------------------------------------------------

typedef struct {
    uint16_t originX;
    uint16_t originY;
    uint16_t dimHeight;
    uint16_t dimWidth;
} ContextInit_t;

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

class Context : public Drawable
{
private:
    
    uint16_t originX;
    uint16_t originY;
    uint16_t dimHeight;
    uint16_t dimWidth;

    /**
     * List of elements contained in Context.
     * 
     * All elements in Context must be drawable (you can't click on something you can't see).
     * 
     */
    std::vector<Drawable> ctx;

    // Rendering
    Color color;
    

public:
    Context(ContextInit_t ctxInit);
    ~Context();

    // Inherited Methods
    // Drawable
    void draw(void);
};


#endif  // _CONTEXT_HPP_