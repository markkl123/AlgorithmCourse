#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include "List.h"
#include "DisjointSets.h"
#include "HeapMin.h"

class Graph
{
private:
	int n;
	int m;
	vector<List> Adjacency;
public:
	Graph(int n, int m):m(m), n(n) { MakeEmptyGraph(n);};
	int GetVertexAmount() { return n; }
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	List& GetAdjList(int u);
	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);
	FullEdge* DFS();
	void Visit(int vertex, vector<char> visited, FullEdge* arrOfEdges, int& i);
	int Kruskal();
	int partition(FullEdge arr[], int start, int end);
	void quickSort(FullEdge arr[], int start = 0, int end = -1);
	int Prim();
};

