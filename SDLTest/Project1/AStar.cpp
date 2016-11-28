#include "AStar.h"

AStar::AStar()
{

}

AStar::~AStar()
{

}

void AStar::Update(Tile start, Tile goal) {
	std::priority_queue<Tile> open;
	vector<Tile> closed;
	vector<Tile> route;

	Tile& currentNode = Tile();
	open.push(goal);

	bool routeFound = false;


	while (!open.empty())
	{
		currentNode = open.top();
		if (currentNode.GetX() == goal.GetX()) {
			if (currentNode.GetY() == goal.GetY())
			{
				routeFound = true;
				//traceBack
			}
		}
		open.pop();
		closed.push_back(currentNode);
		for each (Tile varOuter in currentNode.getNeighBours())
		{
			for each (Tile varInner in closed)
			{
				if (varOuter.GetX() == varInner.GetX()) {
					if (varOuter.GetY() == varInner.GetY()) {
						//
						int tentative_g_score = currentNode.getG() + 
					}
				}
			}
		}

	}
}


//function A*(start, goal)
//closedset : = the empty set    // The set of nodes already evaluated.
//	openset : = { start }    // The set of tentative nodes to be evaluated, initially containing the start node
//came_from: = the empty map    // The map of navigated nodes.
//
//	g_score[start] : = 0    // Cost from start along best known path.
//							// Estimated total cost from start to goal through y.
//	f_score[start] : = g_score[start] + heuristic_cost_estimate(start, goal)
//
//	while openset is not empty
//		current : = the node in openset having the lowest f_score[] value
//		if current = goal
//			return reconstruct_path(came_from, goal)
//
//			remove current from openset
//			add current to closedset
//			for each neighbor in neighbor_nodes(current)
//				if neighbor in closedset
//					continue
//					tentative_g_score : = g_score[current] + dist_between(current, neighbor)
//
//					if neighbor not in openset or tentative_g_score < g_score[neighbor]
//						came_from[neighbor] : = current
//						g_score[neighbor] : = tentative_g_score
//						f_score[neighbor] : = g_score[neighbor] + heuristic_cost_estimate(neighbor, goal)
//						if neighbor not in openset
//							add neighbor to openset
//
//							return failure
//
//function reconstruct_path(came_from, current)
//	total_path : = [current]
//		while current in came_from :
//current: = came_from[current]
//	total_path.append(current)
//	return total_path






















//	currentLowestF = currentNode.getF();
//
//
//	closed.push_back(currentNode);
//	if ((currentNode.GetX() == et.GetX()) && (currentNode.GetY() == et.GetY())) {
//		routeFound = true;
//	}
//	else
//	{
//		priorityQue = currentNode.getNeighBours();
//		for each (Tile var in priorityQue)
//		{
//			if (var.getOpen()) {
//				var.setFValue(et, ot);
//				var.setParent(Vector2D(currentNode.GetX(), currentNode.GetY()));
//				it = std::find(open.begin(), open.end(), var);
//				if (it != open.end()) {
//					open.push_back(var);
//				}
//			}
//		}
//	}
//	for each (Tile t in open)
//	{
//		if (t.getF() < currentLowestF) {
//			currentNode = t;
//		}
//	}
//}