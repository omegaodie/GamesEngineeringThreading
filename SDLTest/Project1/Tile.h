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
		isClosed = false;
	};
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

	vector<Tile*> getNeighBours();

	void estimateH(Tile *Dest);
	void estimateG(Tile *orig);

	void setFValue(Tile *Dest, Tile *orig);

	void setPriorty(int p);

	int getPriority();

	void setParent(Tile* tl);
	Tile* getParent();

	bool operator<(const Tile& t) const;

	void setG(int g);
	void setH(int g);
	void setF(int g);

private:
	//stuff
	int g_Cost;
	int h_Cost;
	int f_Cost;
	Tile* parentTile;

	int priority;
	vector<Tile*> neighbours;
	
	bool isOpen;
	bool isClosed;

};
#endif
#pragma once
