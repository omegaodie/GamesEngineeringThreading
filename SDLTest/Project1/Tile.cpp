#include "Tile.h"





Tile::Tile()
{
}

Tile::~Tile() {



}

void Tile::setFValue(Tile *Dest, Tile *orig) {
	estimateH(Dest);
	estimateG(orig);
	f_Cost = h_Cost + g_Cost;
}

void Tile::setOpen(bool b) {
	isOpen = b;
}


void Tile::setClosed(bool b) {
	isClosed = b;
}



void Tile::estimateH(Tile *Dest) {//stole this
	static int xd, yd, d;


	xd = Dest->GetX() - m_x;

	yd = Dest->GetY() - m_y;

	// Euclidian Distance
	d = static_cast<int>(sqrt(xd*xd + yd*yd));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//d=max(abs(xd), abs(yd));

	h_Cost = d;
}

int Tile::estimateDist(Tile *tile) {//stole this
	static int xd, yd, d;


	xd = tile->GetX() - m_x;

	yd = tile->GetY() - m_y;

	// Euclidian Distance
	d = static_cast<int>(sqrt(xd*xd + yd*yd));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//d=max(abs(xd), abs(yd));

	return d;
}

bool Tile::getEqual(Tile* t) {
	if ((m_x == t->GetX()) && (m_y == t->GetY())) {
		return true;
	}
	else
	{
		return false;
	}
}

void Tile::estimateG(Tile *orig) {//stole this
	int xd, yd, d;

	xd = orig->GetX() - m_x;

	yd = orig->GetY() - m_y;

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

int Tile::getF() const {
	return f_Cost;
}

Vector2D Tile::getV2D()
{
	return Vector2D(GetX(), GetY());
}
bool Tile::getClosed() {
	return isClosed;
}

bool Tile::getOpen() {
	return isOpen;
}

vector<Tile*> Tile::getNeighBours()
{
	neighbours.reserve(100);
	if ((m_x > 0) && (m_y > 0)) {
		neighbours.push_back( new Tile(m_x - 1, m_y - 1));
		neighbours.push_back(new Tile(m_x - 1, m_y));
		neighbours.push_back(new Tile(m_x - 1, m_y + 1));
		neighbours.push_back(new Tile(m_x, m_y - 1));
		neighbours.push_back(new Tile(m_x, m_y + 1)); 
		neighbours.push_back(new Tile(m_x + 1, m_y - 1));
		neighbours.push_back(new Tile(m_x + 1, m_y));
		neighbours.push_back(new Tile(m_x + 1, m_y + 1));
		neighbours.shrink_to_fit();
	}
	else if ((m_x == 0) && (m_y > 0)) {
		neighbours.push_back(new Tile(m_x, m_y - 1));
		neighbours.push_back(new Tile(m_x, m_y + 1));
		neighbours.push_back(new Tile(m_x + 1, m_y - 1));
		neighbours.push_back(new Tile(m_x + 1, m_y));
		neighbours.push_back(new Tile(m_x + 1, m_y + 1));
		neighbours.shrink_to_fit();
	}
	else if ((m_y == 0) && (m_x > 0)) {
		neighbours.push_back(new Tile(m_x - 1, m_y));
		neighbours.push_back(new Tile(m_x - 1, m_y + 1));
		neighbours.push_back(new Tile(m_x, m_y + 1));
		neighbours.push_back(new Tile(m_x + 1, m_y));
		neighbours.push_back(new Tile(m_x + 1, m_y + 1));
		neighbours.shrink_to_fit();
	}
	else {
		neighbours.push_back(new Tile(m_x, m_y + 1));
		neighbours.push_back(new Tile(m_x + 1, m_y));
		neighbours.push_back(new Tile(m_x + 1, m_y + 1));
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

void Tile::setParent(Tile* v) {
	parentTile = v;
}



Tile* Tile::getParent() {
	return parentTile;
}

bool Tile::operator<(const Tile & t) const
{
	return f_Cost < t.getF();
}
