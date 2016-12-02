#include "AStar.h"

AStar::AStar()
{
	//theTiles = new Tile*[1000];
	//for (int i = 0; i < 1000; i++) {
	//		theTiles[i] = new Tile[1000];
	//}
}

AStar::~AStar()
{

}

void AStar::getValue(int x1, int y1, int x2, int y2) {
	Tile* s = new Tile(x1, y1);
	Tile* e = new Tile(x2, y2);
	sort(s, e);
}


void AStar::sort(Tile* start, Tile* goal) {
	auto compareFunc = [](Tile* a, Tile* b) { return a->getF() > b->getF(); };
	typedef priority_queue<Tile*, vector<Tile*>, decltype(compareFunc)> q2;
	Tile* current = start;
	bool routefound = false;
	q2 openQue(compareFunc);
	//openQue
	openQue.push(current);
	while (!openQue.empty()) {
		current = openQue.top();
		current->setOpen(false);
		openQue.pop();
		current->setClosed(true);
		current->setFValue(goal, start);
		if (current->getEqual(goal)) {
			routefound = true;
		}
		else {
			for each (Vector2D* t in current->getNeighBours())
			{
				if (!t->getClosed()) {

					if(t->estimateDist(start) >= (t->estimateDist(current) + current->getG()))
					{
						t->setG(current->getG() + t->estimateDist(current));
						t->setParent(current);
						t->setH(t->estimateDist(goal));
						t->setF(t->getG() + t->getH());
						if (!t->getOpen()) {
							t->setOpen(true);
							openQue.push(t);
						}
					}
				}
			}
		}
	}

}

//function reconstruct_path(cameFrom, current)
//total_path : = [current]
//	while current in cameFrom.Keys :
//		current : = cameFrom[current]
//		total_path.append(current)
//		return total_path