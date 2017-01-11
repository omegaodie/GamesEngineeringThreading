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
	void mousePress(SDL_MouseButtonEvent& b);
	void randomStart();
	Vector2D getStart();
	Vector2D getEnd();
	void setB(vector<Vector2D> v);
	AStar* getAstar();

	void clean();

	bool getDataToSend();
	void setDataToSend(bool b);
private:
	bool waiting, redraw, dataToSend;
	vector<Vector2D> wallOne;
	AStar myStar;
	bool m_running;
	Renderer m_REND;
	vector<Vector2D> route;
	vector<Vector2D> routeA;
	vector<Vector2D> routeB;
	Vector2D start;
	Vector2D end;
	Size m_screenSize;
	int gridSize;

 
};
#endif

