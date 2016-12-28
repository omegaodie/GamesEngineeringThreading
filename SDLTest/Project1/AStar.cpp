#include "AStar.h"

AStar::AStar()
{
	theTiles = new Tile*[100];
	for (int i = 0; i < 100; i++) {
			theTiles[i] = new Tile[100];
			for(int k = 0; k < 100; k++){
				theTiles[i][k] = Tile(i, k, 100);
			}
	}
}

AStar::~AStar()
{

}

vector<Vector2D> AStar::getValue(int x1, int y1, int x2, int y2) {
	Tile* s = new Tile(x1, y1, 100);
	Tile* e = new Tile(x2, y2, 100);
	vector<Vector2D> route;
	route = sort(s, e);
	return route;
}


vector<Vector2D> AStar::sort(Tile* start, Tile* goal) {
	auto compareFunc = [](Tile* a, Tile* b) { return a->getF() > b->getF(); };
	typedef priority_queue<Tile*, vector<Tile*>, decltype(compareFunc)> q2;
	Tile* current = start;
	bool routefound = false;
	q2 openQue(compareFunc);
	//openQue
	vector<Vector2D> route;
	openQue.push(current);
	while (!openQue.empty()) {
		current = openQue.top();
		current->setOpen(false);
		openQue.pop();
		current->setClosed(true);
		current->setFValue(goal, start);
		if (current->getEqual(goal)) {
			routefound = true;
			route = reconstruct_path(current, start);
			break;
		}
		else {
			for each (Vector2D* t in current->getNeighBours())
			{
				if (!theTiles[(int)t->GetX()][(int)t->GetY()].getClosed()) {

					if(theTiles[(int)t->GetX()][(int)t->GetY()].estimateDist(start) >= 
						(theTiles[(int)t->GetX()][(int)t->GetY()].estimateDist(current) + current->getG()))
					{
						theTiles[(int)t->GetX()][(int)t->GetY()].setG(current->getG() + theTiles[(int)t->GetX()][(int)t->GetY()].estimateDist(current));
						theTiles[(int)t->GetX()][(int)t->GetY()].setParent(current);
						theTiles[(int)t->GetX()][(int)t->GetY()].setH(theTiles[(int)t->GetX()][(int)t->GetY()].estimateDist(goal));
						theTiles[(int)t->GetX()][(int)t->GetY()].setF(theTiles[(int)t->GetX()][(int)t->GetY()].getG() + theTiles[(int)t->GetX()][(int)t->GetY()].getH());
						if (!theTiles[(int)t->GetX()][(int)t->GetY()].getOpen()) {
							theTiles[(int)t->GetX()][(int)t->GetY()].setOpen(true);
							openQue.push(&theTiles[(int)t->GetX()][(int)t->GetY()]);
						}
					}
				}
			}
		}
	}
	return route;
}

vector<Vector2D> AStar::reconstruct_path(Tile*cameFrom, Tile*end) {
	vector<Vector2D> myroute;
	Vector2D beiningofend = Vector2D(end->GetX(), end->GetY());
	Vector2D current = Vector2D(cameFrom->GetX(), cameFrom->GetY());
	while (current.GetX() != beiningofend.GetX() && current.GetY() != beiningofend.GetY())
	{
		Vector2D parent = Vector2D(theTiles[(int)current.GetX()][(int)current.GetY()].getParent()->GetX(), 
			theTiles[(int)current.GetX()][(int)current.GetY()].getParent()->GetY());
		myroute.push_back(Vector2D(current));
		current = parent;
	}
	myroute.push_back(beiningofend);
	return myroute;
}
//total_path : = [current]
//	while current in cameFrom.Keys :
//		current : = cameFrom[current]
//		total_path.append(current)
//		return total_path