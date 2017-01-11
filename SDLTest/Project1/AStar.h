#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <vector>

#include "Tile.h"
#include "Vector2D.h"
#include <queue>

using namespace std;

class AStar
{
public:
	AStar();
	AStar(AStar& a);
	~AStar();
	void initiialise(vector<Vector2D> w, int s);
	void getWalls(vector<Vector2D> w);
	vector<Vector2D> getValue(int x1, int y1, int x2, int y2);
	vector<Vector2D> sort( Tile& ot, Tile& et);
	vector<Vector2D> reconstruct_path(Tile* et, Tile* st);

private:
	vector<Vector2D> wall;
	Tile** theTiles;
	//vector<Vector2D> m_Layers;
};
#endif
#pragma once
