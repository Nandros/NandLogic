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
#include "Controller/InputHandler.hpp"

#include <iostream>

Window* winInst = nullptr;
Gate gateAND = Gate("AND");

bool leftClick(InputEvent evt) {
	if (evt != INPUT_EVENT_PRESSED) {
		return false;
	}

	std::cout << "LEFT CLICK" << "\n";
	return true;
}

bool leftDown(InputEvent evt) {
	Camera2D* camera = Window::GetInstance()->getCamera();

	if (camera == nullptr) {
		return false;
	}

	if (evt != INPUT_EVENT_DOWN) {
		return false;
	}

	if (winInst == nullptr) {
		return false;
	}

	if (CheckCollisionPointRec(GetMousePosition(), gateAND.getHitBox(*camera))) {
		std::cout << "Drag Gate" << "\n";
		gateAND.drag(GetMouseDelta(), *camera);
		goto funcLeftDragRet;
	}
	
	winInst->drag(GetMouseDelta(), *camera);

funcLeftDragRet:
	return true;
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
	InputHandler* inptsHandle = InputHandler::GetInstance();

	winInst = Window::GetInstance();
	bool wasOnScreen = false;

	WindowConfig conf = {
		.width = 800,
		.height = 450,
		.targetFPS = 60,
	};

	winInst->init(conf);

	winInst->addGate(&gateAND);

	inptsHandle->attach(MOUSE_BUTTON_LEFT, leftClick);
	inptsHandle->attach(MOUSE_BUTTON_LEFT, leftDown);

	while (!winInst->shouldClose()) {
		inptsHandle->tickKeyboard();
		inptsHandle->tickMouse();

		winInst->update();
	}
	
	winInst->close();
	
	return 0;
}
