#pragma once
using namespace std;
#include <iostream>
#include <string>
struct Pair
{
	string data;
	int key;
	int other_index;
};

class HeapMin
{
private:
	Pair* HeapArray;
	int heapSize;
	int maxSize;
public:
	HeapMin();
	void FixHeap(int node);
	Pair DeleteMin();
	int Insert(Pair item);
	int Left(int node);
	int Right(int node);
	int Parent(int node);
};

