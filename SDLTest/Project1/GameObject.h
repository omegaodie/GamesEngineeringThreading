#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include <SDL.h>
#include "Debug.h"
#include "GameObjectParameters.h"

using namespace std;

class GameObject
{
public:
	GameObject();
	~GameObject();
	virtual void Initialize(const GameObjectParameters*) = 0; 
	virtual void Render() = 0;
	virtual void Update() = 0;
	virtual void CleanUp() = 0;
	int GetX();
	void SetX(int);
	int GetY();
	void SetY(int);
protected:
	int m_x;//world position
	int m_y;//"
	int f_x;// frame
	int f_y;// frame
	SDL_Texture* m_p_Texture;
	SDL_Rect m_Source;
	SDL_Rect m_Destination;
	SDL_Surface* m_p_Surface;
};
#endif
