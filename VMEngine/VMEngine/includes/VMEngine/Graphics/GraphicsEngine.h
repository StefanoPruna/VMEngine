#pragma once

#include "SDL2//SDL.h"

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	//Initialised Graphic Engine/ the Window
	bool InitGE(const char* WTitle, bool bFullscreen, int WWidth, int WHeight);

	//Show the newest frame graphic
	void PresentGraphics();
	//Clear the old frame
	void ClearGraphics();

	//Return the sdl window
	SDL_Window* GetWindow() const;

private:
	SDL_Window* SdlWindow;
	SDL_GLContext SdlGLContext;
};