#pragma once
#include "HeapMax.h"

struct Pair
{
	string data;
	int key;
	int other_index;
};

class HeapMin: public Heap
{
	void FixHeap(int node);
public:
	HeapMin();
	const Pair& Min();
	Pair DeleteMin(int i);
	int Insert(Pair item, HeapMax &hm);
	int HeapMin::Left(int node);
	int HeapMin::Right(int node);
	int HeapMin::Parent(int node);
};

