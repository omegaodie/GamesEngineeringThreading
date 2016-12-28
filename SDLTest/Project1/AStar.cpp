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

void AStar::getValue(int x1, int y1, int x2, int y2) {
	Tile* s = new Tile(x1, y1, 100);
	Tile* e = new Tile(x2, y2, 100);
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

}

//function reconstruct_path(cameFrom, current)
//total_path : = [current]
//	while current in cameFrom.Keys :
//		current : = cameFrom[current]
//		total_path.append(current)
//		return total_path