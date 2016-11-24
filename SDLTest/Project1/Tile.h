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
	Tile();
	Tile(float x, float y) : Vector2D(x, y) {
		isOpen = false;
	};
	~Tile();

	int getG();
	int getH();
	int getF();

	bool getOpen();

	vector<Tile> getNeighBours();

	void estimateH(Tile  Dest);
	void estimateG(Tile  orig);

	void setFValue(Tile  Dest, Tile  orig);

	void setPriorty(int p);

	int getPriority();

	void setParent(Vector2D v);
	Tile getParent();

	void setG(int g);
	void setH(int g);
	void setF(int g);

private:
	//stuff
	int g_Cost;
	int h_Cost;
	int f_Cost;
	Vector2D parentTile;

	int priority;
	vector<Tile> neighbours;
	
	bool isOpen;

};
#endif
#pragma once
