#include <iostream>
#include "Graph.h"

//#define TIME_LOG_ENABLED
int getTime() { return 1; }

int main()
{
	GraphAdjList graph(10);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	
	graph.addEdge(1, 4);
	graph.addEdge(2, 5);
	graph.addEdge(2, 6);
	graph.addEdge(3, 7);

	graph.addEdge(4, 8);
	graph.addEdge(5, 9);
	graph.addEdge(7, 9);
	graph.addEdge(6, 9);
	graph.addEdge(1, 9);
	graph.addEdge(1, 3);
	
#ifdef TIME_LOG_ENABLED
	int startTime = getTime();
#endif

	graph.BFS();

#ifdef TIME_LOG_ENABLED
	int endTime = getTime();
	int diff = endTime - startTime;
	std::cout << "Time used for BFS: " << diff << std::endl;
#endif
	std::cout << std::endl << std::endl;
	int level = 5;
	std::cout << "Number of nodes ont level " << level << " : " << graph.numberOfNodesInLevel(level) << std::endl << std::endl;

	GraphAdjList graphUndirected(4, Graph::ConnectionType::undirected);

	graphUndirected.addEdge(0, 1);
	graphUndirected.addEdge(0, 2);
	graphUndirected.addEdge(1, 3);
	graphUndirected.addEdge(2, 3);
	
	std::cout << "Graph is " << ((!graphUndirected.GraphIsStronglyConnected()) ? "not " : "") << "strongly connected" << std::endl;

	GraphAdjList graphDirected(4, Graph::ConnectionType::directed);

	graphDirected.addEdge(0, 1);
	graphDirected.addEdge(0, 2);
	graphDirected.addEdge(1, 3);
	graphDirected.addEdge(2, 3);

	std::cout << "Graph is " << ((!graphDirected.GraphIsStronglyConnected()) ? "not " : "") << "strongly connected" << std::endl;

	graphDirected.addEdge(3, 1);
	graphDirected.addEdge(3, 2);
	graphDirected.addEdge(1, 0);
	graphDirected.addEdge(2, 0);

	std::cout << "Graph is " << ((!graphDirected.GraphIsStronglyConnected()) ? "not " : "") << "strongly connected" << std::endl;
}