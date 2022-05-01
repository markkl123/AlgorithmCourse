#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include "List.h"
#include "InputChecker.h"

class Graph
{
private:
	int n;
	vector<List> Adjacency;
public:
	Graph(int n) { MakeEmptyGraph(n);};
	int GetVertexAmount() { return n; }
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	List& GetAdjList(int u);
	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);
	void DFS(Graph G);
	void Visit(int vertex, vector<char> visited, vector<FullEdge> arrOfEdges);
};

