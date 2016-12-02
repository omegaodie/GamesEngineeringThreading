#pragma once
#ifndef VISUALBRICK_H
#define VISUALBRICK_H

#include "GameObject.h"

class VisualBrick : public GameObject
{
public:
	VisualBrick();
	~VisualBrick();
	void Initialize(const GameObjectParameters* params);
	void Initialize(const GameObjectParameters* params, SDL_Renderer* m_p, SDL_Window* m_p_W);
	void Initialize(Uint16 x, Uint16 y, SDL_Renderer* m_p, SDL_Window* m_p_W);
	void Initialize(SDL_Renderer* m_p);
	void Render();
	void Render(SDL_Renderer* m_p);
	void Update();
	void CleanUp();




};
#endif
