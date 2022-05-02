#pragma once
using namespace std;
#include "Node.h"
#include <iostream>
#include <string>
struct Pair
{
	FullEdge data;
	int key;
};

class HeapMin
{
private:
	Pair* HeapArray;
	int heapSize = 0;
public:
	HeapMin(int n);
	void Build(vector <FullEdge> A);
	bool isEmpty();
	void DecreaseKey(int place, Pair newKey);
	void FixHeap(int node);
	Pair DeleteMin();
	int Left(int node);
	int Right(int node);
	int Parent(int node);
	void Swap(Pair& pair1, Pair& pair2);
};

