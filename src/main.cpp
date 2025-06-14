/**
 * @file main.cpp
 * @author Nathan.A (nathan.andre.etudiant@gmail.com)
 * @brief A Project inspired by Digital Logic Sim from Sebastian Lague
 * @version 0.1
 * @date 2025-05-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "View/Window.hpp"

#include <iostream>

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
	Window* winInst = Window::GetInstance();
	bool wasOnScreen = false;

	WindowConfig conf = {
		.width = 800,
		.height = 450,
		.targetFPS = 60,
	};

	winInst->init(conf);

	while (!winInst->shouldClose()) {
		if (IsCursorOnScreen() && !wasOnScreen) {
			wasOnScreen = true;
			std::cout << "Entered screen" << "\n";
		} else if (!IsCursorOnScreen() && wasOnScreen) {
			wasOnScreen = false;
			std::cout << "Existed screen" << "\n";
		}

		winInst->update();
	}
	
	winInst->close();
	
	return 0;
}
