#include "VMEngine/Game.h"

Game& Game::GetGameInstance()
{
	//Create the game only one time, because it's static
	static Game* GameInstance = new Game();
	return *GameInstance;
}

void Game::DestroyGameInstance()
{
	static Game* GameInstance = &GetGameInstance();

	delete GameInstance;
}

void Game::Start(const char* WTitle, bool bFullscreen, int WWidth, int WHeight)
{
	Graphics = new GraphicsEngine();

	if (!Graphics->InitGE(WTitle, bFullscreen, WWidth, WHeight))
	{
		bIsGameOver = true;
	}

	Run();
}

Game::Game()
{
	cout << "Game Initialised" << "\n";

	Graphics = nullptr;

	bIsGameOver = false;
}

Game::~Game()
{
	cout << "Game Over..." << endl;
}

void Game::Run()
{
	while (!bIsGameOver)
	{
		ProcessInput();

		Update();

		Draw();
	}

	CloseGame();
}

void Game::ProcessInput()
{
	//TO DO input
}

void Game::Update()
{
	//TO DO logic
}

void Game::Draw()
{
	// TO DO graphics
}

void Game::CloseGame()
{
	//TO DO end the game
}