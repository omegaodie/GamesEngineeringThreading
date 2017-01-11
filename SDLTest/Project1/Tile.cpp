#include "Tile.h"





Tile::Tile()
{

}

Tile::Tile(int x, int y, int nc, bool travers) {
	m_V = Vector2D(x, y);
	isOpen = false;
	isClosed = false;
	traversable = travers;
	numcolumns = nc;
};

Tile::~Tile() {



}

void Tile::setFValue(Tile *Dest, Tile *orig) {
	g_Cost = estimateDist(orig);
	h_Cost = estimateDist(Dest);
	f_Cost = h_Cost + g_Cost;
}

void Tile::setOpen(bool b) {
	isOpen = b;
}


void Tile::setClosed(bool b) {
	isClosed = b;
}

void Tile::setWall(bool b)
{
	traversable = b;
}



int Tile::estimateDist(Tile *tile) {//stole this
	static int xd, yd, d;


	xd = tile->getV2D().GetX() - m_V.GetX();

	yd = tile->getV2D().GetY() - m_V.GetY();

	// Euclidian Distance
	d = static_cast<int>(sqrt(xd*xd + yd*yd));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//d=max(abs(xd), abs(yd));

	return d;
}

bool Tile::getEqual(Tile* t) {
	if ((m_V.GetX() == t->getV2D().GetX()) && (m_V.GetY() == t->getV2D().GetY())) {
		return true;
	}
	else
	{
		return false;
	}
}

void Tile::setPriorty(int p)
{
	priority = p;
}

int Tile::getPriority()
{
	return priority;
}

bool Tile::compareParent(Tile* t) {
	//if (f)
	return false;
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
	return m_V;
}
bool Tile::getClosed() {
	return isClosed;
}

bool Tile::getOpen() {
	return isOpen;
}

//vector<Vector2D*> Tile::getNeighBours()
//{
//	neighbours.reserve(100);
//	if ((m_V.GetX() == 0) && (m_V.GetY() == 0)) { // c1
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() + 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
//		neighbours.shrink_to_fit();
//	}
//	else if ((m_V.GetX() == 0) && ((m_V.GetY() > 0)&& (m_V.GetY() < numcolumns))) { // c2
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() + 1));
//		neighbours.shrink_to_fit();
//	}
//	else if ((m_V.GetX() == 0) && ((m_V.GetY() > 0) && (m_V.GetY() == (numcolumns - 1)))) { // c3
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
//		neighbours.shrink_to_fit();
//	}
//	else if ((m_V.GetX() > 0) && ((m_V.GetX() < numcolumns) && (m_V.GetY() == (numcolumns - 1)))) { // c4
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
//		neighbours.shrink_to_fit();
//	}
//	else if ((m_V.GetX() == (numcolumns - 1)) && (m_V.GetY() == (numcolumns - 1))) { // c5
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() -1));
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() - 1));
//		neighbours.shrink_to_fit();
//	}
//	else if (((m_V.GetX() > 0) && (m_V.GetY() > 0)) && ((m_V.GetX() < numcolumns) && (m_V.GetY() < numcolumns))) { // c6
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() + 1));
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() + 1));
//		neighbours.shrink_to_fit();
//	}
//	else if ((m_V.GetY() == 0) && (m_V.GetX() > 0) && (m_V.GetX() < numcolumns)) { //c7
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() + 1));
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
//		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() + 1));
//		neighbours.shrink_to_fit();
//	}
//	else if ((m_V.GetY() == 0) && (m_V.GetX() > 0) && (m_V.GetX() == (numcolumns - 1))) { //c8
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() + 1));
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
//		neighbours.shrink_to_fit();
//	}
//	else { //c9
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() + 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX() , m_V.GetY() - 1));
//		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
//		neighbours.shrink_to_fit();
//	}
//	return neighbours;
//}

void Tile::setG(int g) {
	g_Cost = g;
}

void Tile::setH(int h) {
	h_Cost = h;
}

void Tile::setF(int f) {
	f_Cost = f;
}

bool Tile::getTraversable()
{
	return traversable;
}

void Tile::setParent(Tile* v) {
	parentTile = v;
}


vector<Vector2D*> Tile::getNeighBours() {
	neighbours.reserve(100);
	// Get all current's adjacent walkable points
	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			// If it's current point then pass
			if (x == 0 && y == 0)
			{
				continue;
			}
			if (((m_V.GetX() + x) >= numcolumns) || ((m_V.GetY() + y) >= numcolumns))
			{
				continue;
			}
			if ((m_V.GetX() + x) < 0) 
			{
				continue;
			}
			if ((m_V.GetY() + y) < 0)
			{
				continue;
			}
			// Get this point
			neighbours.push_back(new Vector2D(m_V.GetX() + x, m_V.GetY() + y));
		}
	}
	neighbours.shrink_to_fit();
	return neighbours;
}




Tile* Tile::getParent() {
	return parentTile;
}

bool Tile::operator<(const Tile & t) const
{
	return f_Cost < t.getF();
}
