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
	Tile& s = theTiles[x1][y1];
	Tile& e = theTiles[x2][y2];
	vector<Vector2D> route;
	route = sort(s, e);
	return route;
}


vector<Vector2D> AStar::sort(Tile& start, Tile& goal) {
	auto compareFunc = [](Tile* a, Tile* b) { return a->getF() > b->getF(); };
	typedef priority_queue<Tile*, vector<Tile*>, decltype(compareFunc)> q2;
	Tile* current = &start;
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
		current->setFValue(&goal, &start);
		if (current->getEqual(&goal)) {
			routefound = true;
			route = reconstruct_path(current, &start);
			break;
		}
		else {
			for each (Vector2D* t in current->getNeighBours())
			{
				if (!theTiles[t->GetX()][t->GetY()].getClosed()) {

					if(theTiles[t->GetX()][t->GetY()].estimateDist(&start) >= 
						(theTiles[t->GetX()][t->GetY()].estimateDist(current) + current->getG()))
					{

						int tentativeG = current->getG() +
							theTiles[t->GetX()][t->GetY()].estimateDist(current);
				

						if ((theTiles[t->GetX()][t->GetY()].getG() > tentativeG) ||
							(!theTiles[t->GetX()][t->GetY()].getOpen()))
						{

							theTiles[t->GetX()][t->GetY()].setG(tentativeG);

							theTiles[t->GetX()][t->GetY()].
							setH(theTiles[t->GetX()][t->GetY()].estimateDist(&goal));

							theTiles[t->GetX()][t->GetY()].
							setF(theTiles[t->GetX()][t->GetY()].getG() + 
								theTiles[t->GetX()][t->GetY()].getH());

							theTiles[t->GetX()][t->GetY()].setParent(current);

							if (!theTiles[t->GetX()][t->GetY()].getOpen()) {
								theTiles[t->GetX()][t->GetY()].setOpen(true);
								openQue.push(&theTiles[t->GetX()][t->GetY()]);
							}
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
	Vector2D beiningofend = Vector2D(end->getV2D().GetX(), end->getV2D().GetY());
	Vector2D current = Vector2D(cameFrom->getV2D().GetX(), cameFrom->getV2D().GetY());
	while (!(current.GetX() == beiningofend.GetX() && current.GetY() == beiningofend.GetY()))
	{
		Vector2D parent = Vector2D(theTiles[current.GetX()][current.GetY()].getParent()->getV2D().GetX(),
			theTiles[current.GetX()][current.GetY()].getParent()->getV2D().GetY());
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