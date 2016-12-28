#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include "Player.h"
#include <SDL.h>
#include "AStar.h"
#include "VisualBrick.h"

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
	VisualBrick** theTiles;
private:
	
	AStar myStar;
	bool m_running;
	SDL_Window* m_p_Window;
	SDL_Renderer* m_p_Renderer;
	SDL_Texture* m_p_Texture;
	SDL_Rect m_Source;
	SDL_Rect m_Destination;
	SDL_Surface* m_p_Surface;
	Player*  m_Player;
 
};
#endif

