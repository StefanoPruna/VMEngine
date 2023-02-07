#include "VMEngine/Graphics/GraphicsEngine.h"
#include "GLEW/glew.h"
#include <iostream>

using namespace std;

GraphicsEngine::GraphicsEngine()
{
	SdlWindow = nullptr;
	SdlGLContext = NULL;
}

GraphicsEngine::~GraphicsEngine()
{
	cout << "Destroy" << "\n";
	//Delete the SDL window from memory
	SDL_DestroyWindow(SdlWindow);
	//destroy the GL 
	SDL_GL_DeleteContext(SdlGLContext);
	//close the SDL framework
	SDL_Quit();
}

bool GraphicsEngine::InitGE(const char* WTitle, bool bFullscreen, int WWidth, int WHeight)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "SDL failed: " << SDL_GetError() << "\n";
		return false;
	}

	//Use OpenGL 3.1
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);

	//Set the fullscreen
	int FullscreenFlag = 0;

	if (bFullscreen)
	{
		FullscreenFlag = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;
	}
	else
	{
		FullscreenFlag = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
	}

	//Create the SDL2 window
	SdlWindow = SDL_CreateWindow(
		WTitle,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WWidth, WHeight,
		FullscreenFlag
	);

	if (SdlWindow == nullptr)
	{
		cout << "SDL window failed: " << SDL_GetError() << "\n";
		return false;
	}

	//add the GL attributes to the window
	SdlGLContext = SDL_GL_CreateContext(SdlWindow);

	if (SdlGLContext == NULL)
	{
		cout << "SDL GL context failed: " << SDL_GetError() << "\n";
		return false;
	}

	//To make 
	glewExperimental = GL_TRUE;

	const GLenum InitGLEW = glewInit();

	if (InitGLEW != GLEW_OK)
	{
		cout << "GLEW failed: " << glewGetErrorString(InitGLEW) << "\n";
		return false;
	}

	return true;
}

void GraphicsEngine::PresentGraphics()
{
	//Present the new graphics using OpenGL
	SDL_GL_SwapWindow(SdlWindow);
}

void GraphicsEngine::ClearGraphics()
{
	//R G B A for background
	glClearColor(0.23f, 0.38f, 0.47f, 1.0f);

	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);
}

SDL_Window* GraphicsEngine::GetWindow() const
{
	return SdlWindow;
}