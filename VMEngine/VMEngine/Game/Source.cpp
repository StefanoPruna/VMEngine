#include "VMEngine/Game.h"

int main(int argc, char** argv) 
{
	Game::GetGameInstance().Start("VMEngine | An OpenGl Engine", false, 1200, 720);

	Game::GetGameInstance();

	Game::DestroyGameInstance();

	return 0;
}