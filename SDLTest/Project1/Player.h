#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();
	void Initialize(const GameObjectParameters*);
	void Render();
	void Render(SDL_Renderer* m_p);
	void Update();
	void CleanUp();
};
#endif
