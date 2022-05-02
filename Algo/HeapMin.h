#pragma once
using namespace std;
#include "Node.h"
#include <iostream>
#include <string>

struct Pair {
	int data, key;
};

class HeapMin
{
private:
	Pair* HeapArray;
	int heapSize = 0;
public:
	HeapMin(int n) : heapSize(n), HeapArray(nullptr) {}
	void Build(Pair* A);
	bool isEmpty();
	void DecreaseKey(int place, int newKey);
	void FixHeap(int node);
	Pair DeleteMin();
	int Left(int node);
	int Right(int node);
	int Parent(int node);
	void Swap(Pair& pair1, Pair& pair2);
	void FixHeapUp(int node);
};

