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
	vector<FullEdge> arrOfEdges;
public:
	Graph(int n, int m):m(m), n(n) { MakeEmptyGraph(n); };
	int GetVertexAmount() { return n; }
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	List& GetAdjList(int u);
	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);
	bool DFS();
	void Visit(int vertex, vector<char> &visited, int& i);
	int Kruskal();
	int partition(vector<FullEdge> &arr, int start, int end);
	void quickSort(vector<FullEdge> &arr, int start, int end);
	int Prim();
};

