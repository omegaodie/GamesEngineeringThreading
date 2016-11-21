#include "Tile.h"



Tile::Tile(float x, float y) : Vector2D(x,y) {

}


Tile::~Tile() {



}


int Tile::estimateH(Tile  Dest) {//stole this
	static int xd, yd, d;


	xd = Dest.GetX() - m_x;

	yd = Dest.GetY() - m_y;

	// Euclidian Distance
	d = static_cast<int>(sqrt(xd*xd + yd*yd));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//d=max(abs(xd), abs(yd));

	return(d);
}



int Tile::estimateG(Tile  orig) {//stole this
	int xd, yd, d;

	xd = orig.GetX() - m_x;

	yd = orig.GetY() - m_y;

	// Euclidian Distance
	d = static_cast<int>(sqrt(xd*xd + yd*yd));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//d=max(abs(xd), abs(yd));

	return(d);
}

void Tile::setPriorty(int p)
{
	priority = p;
}

int Tile::getPriority()
{
	return priority;
}






int Tile::getG() {
	return g_Cost;
}

int Tile::getH() {
	return h_Cost;
}

int Tile::getF() {
	return f_Cost;
}


bool Tile::getOpen() {
	return isOpen;
}

void Tile::setG(int g) {
	g_Cost = g;
}

void Tile::setH(int h) {
	h_Cost = h;
}

void Tile::setF(int f) {
	f_Cost = f;
}