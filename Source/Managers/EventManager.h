#pragma once

#include "Core/RenderWindow.h"

class EventManager
{
private:

	EventManager() = default;

public:

	static void Update();

public:

	static void AttachGlobalWindow(RenderWindow& renderWindow);
	static void DetachGlobalWindow();

public:

	static RenderWindow* pGlobalWindow;

};

