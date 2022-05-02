#pragma once
using namespace std;
#include "Node.h"
#include <iostream>
#include <string>

class HeapMin
{
private:
	int* HeapArray;
	int heapSize = 0;
public:
	HeapMin(int n);
	void Build(int* A);
	bool isEmpty();
	void DecreaseKey(int place, int newKey);
	void FixHeap(int node);
	int DeleteMin();
	int Left(int node);
	int Right(int node);
	int Parent(int node);
	void Swap(int& pair1, int& pair2);
};

