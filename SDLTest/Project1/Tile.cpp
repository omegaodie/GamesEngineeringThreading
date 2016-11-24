#include "Tile.h"





Tile::Tile()
{
}

Tile::~Tile() {



}

void Tile::setFValue(Tile  Dest, Tile  orig) {
	estimateH(Dest);
	estimateG(orig);
	f_Cost = h_Cost + g_Cost;
}


void Tile::estimateH(Tile  Dest) {//stole this
	static int xd, yd, d;


	xd = Dest.GetX() - m_x;

	yd = Dest.GetY() - m_y;

	// Euclidian Distance
	d = static_cast<int>(sqrt(xd*xd + yd*yd));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//d=max(abs(xd), abs(yd));

	h_Cost = d;
}



void Tile::estimateG(Tile  orig) {//stole this
	int xd, yd, d;

	xd = orig.GetX() - m_x;

	yd = orig.GetY() - m_y;

	// Euclidian Distance
	d = static_cast<int>(sqrt(xd*xd + yd*yd));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//d=max(abs(xd), abs(yd));

	g_Cost = d;
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

vector<Tile> Tile::getNeighBours()
{

	if ((m_x > 0) && (m_y > 0)) {
		neighbours[0] = Tile(m_x - 1, m_y - 1);
		neighbours[1] = Tile(m_x - 1, m_y);
		neighbours[2] = Tile(m_x - 1, m_y + 1);
		neighbours[3] = Tile(m_x, m_y - 1);
		neighbours[4] = Tile(m_x, m_y + 1);
		neighbours[5] = Tile(m_x + 1, m_y - 1);
		neighbours[6] = Tile(m_x + 1, m_y);
		neighbours[7] = Tile(m_x + 1, m_y + 1);
		neighbours.shrink_to_fit();
	}
	else if ((m_x == 0) && (m_y > 0)) {
		neighbours[0] = Tile(m_x, m_y - 1);
		neighbours[1] = Tile(m_x, m_y + 1);
		neighbours[2] = Tile(m_x + 1, m_y - 1);
		neighbours[3] = Tile(m_x + 1, m_y);
		neighbours[4] = Tile(m_x + 1, m_y + 1);
		neighbours.shrink_to_fit();
	}
	else if ((m_y == 0) && (m_x > 0)) {
		neighbours[0] = Tile(m_x - 1, m_y);
		neighbours[1] = Tile(m_x - 1, m_y + 1);
		neighbours[2] = Tile(m_x, m_y + 1);
		neighbours[3] = Tile(m_x + 1, m_y);
		neighbours[4] = Tile(m_x + 1, m_y + 1);
		neighbours.shrink_to_fit();
	}
	else {
		neighbours[0] = Tile(m_x, m_y + 1);
		neighbours[1] = Tile(m_x + 1, m_y);
		neighbours[2] = Tile(m_x + 1, m_y + 1);
		neighbours.shrink_to_fit();
	}
	return neighbours;
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

void Tile::setParent(Vector2D v) {
	parentTile = v;
}



Tile Tile::getParent() {
	return Tile(parentTile.GetX(), parentTile.GetY());
}