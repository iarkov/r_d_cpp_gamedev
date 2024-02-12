#include "Graph.h"
#include <map>
#include <set>

GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
	: Graph(Vertixes, type)
{
	m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{
	m_list[v].push_back(w);
	if (m_connectionType == ConnectionType::undirected)
	{
		m_list[w].push_back(v);
	}
}

void GraphAdjList::BFS(int vertex)
{
	// Mark all the vertices as not visited
	std::vector<bool> visited;
	visited.resize(m_vertixes, false);

	std::list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[vertex] = true;
	queue.push_back(vertex);

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		int currentVertex = queue.front();

		//or make anything else with it: push to vector, string, pass to another object, whatever
		std::cout << currentVertex << " ";

		queue.pop_front();

		// Get all adjacent vertices
		for (int adjacent : m_list[currentVertex])
		{
			if (!visited[adjacent])
			{
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}

int GraphAdjList::numberOfNodesInLevel(int level) {
	std::vector<bool> visited;
	visited.resize(m_vertixes, false);

	std::list<int> queue;

	visited[0] = true;
	queue.push_back(0);

	int currentLevel = 1;

	while (currentLevel < level) {
		int currentQueueSize = queue.size();
		std::map<int, bool> inQueue;

		for (int element : queue) {
			inQueue[element] = true;
		}

		for (int i = 0; i < currentQueueSize; i++) {
			int vertex = queue.front();
			for (int element : m_list[vertex]) {
				if (!visited[element] && !inQueue[element]) {
					queue.push_back(element);
				}
			}
			visited[vertex] = true;
			queue.pop_front();
		}

		inQueue.clear();

		currentLevel += 1;
	}

	return queue.size();
}

bool GraphAdjList::GraphIsStronglyConnected() {
	for (int i = 0; i < m_vertixes; i++) {
		std::list<int> queue;
		std::set<int> visited;

		std::map<int, bool> inQueue;

		queue.push_back(i);
		inQueue[i] = true;

		while (queue.size()) {
			int vertex = queue.front();

			for (int element : m_list[vertex]) {
				if ((visited.find(element) == visited.end()) && !inQueue[element]) {
					queue.push_back(element);
					inQueue[element] = true;
				}
			}

			visited.insert(vertex);
			queue.pop_front();
			inQueue[vertex] = false;
		}

		if (visited.size() != m_vertixes) {
			return false;
		}
	}

	return true;
}