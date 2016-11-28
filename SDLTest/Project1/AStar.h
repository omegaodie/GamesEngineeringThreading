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
	void Update( Tile ot, Tile et);


private:
	Tile theTiles[10][10];
	vector<Tile> m_TileSet;
	vector<Layer*> m_Layers;
};
#endif
#pragma once
