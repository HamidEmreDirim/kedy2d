#include "Engine.h"
#include "TextureManeger.h"
#include "Vector2D.h"
#include "Transform.h"
#include "Warrior.h"
#include "Input.h"
#include "Timer.h"

Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;

Engine::Engine() 
{

}


bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initilaze SDL: %s", SDL_GetError());

		return false;
	}


	m_Window = SDL_CreateWindow("kedy Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_HEIGHT, 0);
	if (m_Window == nullptr) {
		SDL_Log("Failed to initilaze window: %s", SDL_GetError());
		return false;

	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) {
		SDL_Log("Failed to initilaze renderer: %s", SDL_GetError());
		return false;
	}

	TextureManeger::GetInstance()->Load("player", "assets/Idle.png");
	TextureManeger::GetInstance()->Load("player_run", "assets/Run.png");

	player = new Warrior(new Properties("player_run", 0, 0, 200, 200));


	

	return m_IsRunning= true;
}

bool Engine::Clean() 
{
	TextureManeger::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
	return true;

}

void Engine::Quit() 
{
	m_IsRunning = false;

}

void Engine::Update() 
{
	float dt = Timer::GetInstance()->GetDeltaTime();
	player->Update(dt);
	
}

void Engine::Render() {
	SDL_SetRenderDrawColor(m_Renderer, 124, 210, 254, 255);
	SDL_RenderClear(m_Renderer);

	player->Draw();
	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
	Input::GetInstance()->Listen();

}

