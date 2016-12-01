#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <vector>

#include "Debug.h"
#include "Tile.h"
#include "Vector2D.h"
#include "Layer.h"
#include <queue>

using namespace std;

class AStar
{
public:
	AStar();
	~AStar();
	void getValue(int x1, int y1, int x2, int y2);
	void sort( Tile* ot, Tile* et);


private:
	Tile* theTiles[10][10];
	vector<Layer*> m_Layers;
};
#endif
#pragma once
