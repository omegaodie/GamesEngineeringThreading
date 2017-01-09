#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include "Player.h"
#include <SDL.h>
#include "AStar.h"
#include "Renderer.h"
#include <random>

class Game
{
public:
	Game();
	~Game();
	bool Initialize(const char*, int, int, int, int, int);
	void LoadContent();
	void UnloadContent();
	void Render();
	void Update();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();

	void randomStart();
private:
	
	AStar myStar;
	bool m_running;
	Renderer m_REND;
	vector<Vector2D> route;
	Vector2D start;
	Vector2D end;
	Size m_screenSize;
	//SDL_Window* m_p_Window;
	////SDL_Renderer* m_p_Renderer;
	////SDL_Texture* m_p_Texture;
	//SDL_Rect m_Source;
	//SDL_Rect m_Destination;
	//SDL_Surface* m_p_Surface;
	//Player*  m_Player;
 
};
#endif

