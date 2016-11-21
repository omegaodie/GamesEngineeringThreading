#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <vector>

#include "Debug.h"
#include "Tile.h"
#include "Layer.h"

using namespace std;

class AStar
{
public:
	AStar();
	~AStar();
	void Update(vector<Tile> v, Tile ot, Tile et);


private:
	vector<Tile> m_TileSet;
	vector<Layer*> m_Layers;
};
#endif
#pragma once
