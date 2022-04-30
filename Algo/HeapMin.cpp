#include "HeapMin.h"

HeapMin::HeapMin() {
	HeapArray = new Pair[maxSize];
	heapSize = 0;
}

void HeapMin::FixHeap(int node) {
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (HeapArray[left].key < HeapArray[node].key)) {
		min = left;
	}
	else {
		min = node;
	}
	if ((right < heapSize) && (HeapArray[right].key < HeapArray[min].key)) {
		min = right;
	}
	if (min != node) {
		FixHeap(min);
	}

}

Pair HeapMin::DeleteMin()
{
	if (heapSize < 1) {
		cout << "Error";
	}
	Pair min = HeapArray[0];
	heapSize--;
	HeapArray[0] = HeapArray[heapSize];
	FixHeap(0);
	return min;
}

int HeapMin::Insert(Pair item) {
	if (heapSize == maxSize) {
		cout << "Wrong Input" << endl;
		exit(1);
	}
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (HeapArray[Parent(i)]).key > item.key) {
		HeapArray[i] = HeapArray[Parent(i)];
		i = Parent(i);
	}

	HeapArray[i] = item;
	return i;
}

int HeapMin::Left(int node) {
	return (2 * node + 1);
}
int HeapMin::Right(int node) {
	return (2 * node + 2);
}
int HeapMin::Parent(int node) {
	return (node - 1) / 2;
}

