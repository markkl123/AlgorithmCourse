#include "HeapMin.h"

HeapMin::HeapMin(int n =0) {
	heapSize = n;
}

void HeapMin::Build(vector <FullEdge> A) {
	Pair* pairArr = new Pair[heapSize];
	for (int i = 0; i < heapSize; i++)
	{
		pairArr[i].data = A[i];
		pairArr[i].key = A[i].weight;
	}
	HeapArray = pairArr;
	for (int i = heapSize / 2 - 1;i >= 0;i--) {
		FixHeap(i);
	}
}

bool HeapMin::isEmpty() {
	return heapSize == 0;
}

void HeapMin::DecreaseKey(int place, Pair newKey) {
	HeapArray[place] = newKey;
	FixHeap(place);
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
		Swap(HeapArray[node], HeapArray[min]);
		FixHeap(min);
	}

}

void HeapMin::Swap(Pair& pair1, Pair& pair2) {

	Pair temp = pair1;
	pair1 = pair2;
	pair2 = temp;
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

int HeapMin::Left(int node) {
	return (2 * node + 1);
}
int HeapMin::Right(int node) {
	return (2 * node + 2);
}
int HeapMin::Parent(int node) {
	return (node - 1) / 2;
}

