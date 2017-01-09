#include "Tile.h"





Tile::Tile()
{
}

Tile::Tile(int x, int y, int nc) {
	m_V = Vector2D(x, y);
	isOpen = false;
	isClosed = false;
	numcolumns = nc;
};

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


	xd = Dest->getV2D().GetX() - m_V.GetX();

	yd = Dest->getV2D().GetY() - m_V.GetY();

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



void Tile::estimateG(Tile *orig) {//stole this
	int xd, yd, d;

	xd = orig->getV2D().GetX() - m_V.GetX();

	yd = orig->getV2D().GetY() - m_V.GetY();

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

vector<Vector2D*> Tile::getNeighBours()
{
	neighbours.reserve(100);
	if ((m_V.GetX() == 0) && (m_V.GetY() == 0)) { // c1
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() + 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
		neighbours.shrink_to_fit();
	}
	else if ((m_V.GetX() == 0) && ((m_V.GetY() > 0)&& (m_V.GetY() < numcolumns))) { // c2
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() + 1));
		neighbours.shrink_to_fit();
	}
	else if ((m_V.GetX() == 0) && ((m_V.GetY() > 0) && (m_V.GetY() == numcolumns))) { // c3
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
		neighbours.shrink_to_fit();
	}
	else if ((m_V.GetX() > 0) && ((m_V.GetX() < numcolumns) && (m_V.GetY() == numcolumns))) { // c4
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
		neighbours.shrink_to_fit();
	}
	else if ((m_V.GetX() == numcolumns) && (m_V.GetY() == numcolumns)) { // c5
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() -1));
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() - 1));
		neighbours.shrink_to_fit();
	}
	else if (((m_V.GetX() > 0) && (m_V.GetY() > 0)) && ((m_V.GetX() < numcolumns) && (m_V.GetY() < numcolumns))) { // c6
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() + 1));
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() + 1));
		neighbours.shrink_to_fit();
	}
	else if ((m_V.GetY() == 0) && (m_V.GetX() > 0) && (m_V.GetX() < numcolumns)) { //c7
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() + 1));
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY()));
		neighbours.push_back(new Vector2D(m_V.GetX() + 1, m_V.GetY() + 1));
		neighbours.shrink_to_fit();
	}
	else if ((m_V.GetY() == 0) && (m_V.GetX() > 0) && (m_V.GetX() == numcolumns)) { //c8
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() + 1));
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
		neighbours.shrink_to_fit();
	}
	else { //c9
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY()));
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() + 1));
		neighbours.push_back(new Vector2D(m_V.GetX() - 1, m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX() , m_V.GetY() - 1));
		neighbours.push_back(new Vector2D(m_V.GetX(), m_V.GetY() + 1));
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
