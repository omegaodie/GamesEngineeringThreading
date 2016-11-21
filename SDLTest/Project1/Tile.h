#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>
#include <vector>
#include "Vector2D.h"


using namespace std;

class Tile : public Vector2D
{
public:
	Tile(float x, float y) : Vector2D(x, y) {};
	~Tile();

	int getG();
	int getH();
	int getF();

	bool getOpen();


	int estimateH(Tile  Dest);
	int estimateG(Tile  orig);

	void setPriorty(int p);

	int getPriority();

	void setG(int g);
	void setH(int g);
	void setF(int g);

private:
	//stuff
	int g_Cost;
	int h_Cost;
	int f_Cost;

	int priority;

	bool isOpen;

};
#endif
#pragma once
