#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>
#include <vector>
#include "Vector2D.h"
#include "BasicTypes.h"

using namespace std;

class Tile
{
public:
	Tile();
	Tile(int x, int y, int nc);
	~Tile();

	int getG();
	int getH();
	int getF() const;

	Vector2D getV2D();
	int estimateDist(Tile  *tile);

	bool getEqual(Tile* t);

	bool getOpen();
	bool getClosed();

	void setOpen(bool b);
	void setClosed(bool b);

	vector<Vector2D*> getNeighBours();

	void estimateH(Tile *Dest);
	void estimateG(Tile *orig);

	void setFValue(Tile *Dest, Tile *orig);

	void setPriorty(int p);

	int getPriority();

	void setParent(Tile* tl);
	Tile* getParent();
	bool Tile::compareParent(Tile* t);

	bool operator<(const Tile& t) const;

	void setG(int g);
	void setH(int g);
	void setF(int g);

private:
	//stuff
	//bool pare
	Vector2D m_V;
	int g_Cost;
	int h_Cost;
	int f_Cost;
	Tile* parentTile;

	int numcolumns;

	int priority;
	vector<Vector2D*> neighbours;
	
	bool isOpen;
	bool isClosed;

};
#endif
#pragma once
