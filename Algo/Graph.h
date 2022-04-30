#pragma once
using namespace std;
#include <iostream>
#include <vector>
//#include "List.h"

//Data structure to store adjacency list nodes

//Data structure to store a graph edge
struct Edge {
	int dest, weight;
};

class Graph
{
private:
	int n;
	vector< List > Adjacency;
public:
	Graph(int n) { MakeEmptyGraph(n); };
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	List& GetAdjList(int u);
	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);
};

