#include "List.h"

Node* List::GetHead() {
	return Head;
}

bool List::isEmpty() {
	return Head == nullptr;
}

Node* List::Find(int key) {
	Node* curr = this->Head;

	while (curr != nullptr) {
		if (curr->Get_Edge().dest == key) {
			return curr;
		}
		curr = curr->Get_Next();
	}

	return nullptr;
}

Node* List::InsertFront(Edge edge) {
	Node* newEdge = new Node(edge, Head);
	newEdge->Set_Next(Head);
	Head = newEdge;
	return newEdge;
}

void List::DeleteNode(int v) {

	for (
		Node* currNode = this->Head;
		currNode != nullptr;
		currNode = currNode->Get_Next()
		) {
		
		if (currNode->Get_Edge().dest == v) {
			if (currNode == Head)
				Head = currNode->Get_Next();

			delete currNode;
			break;
		}
	}
}

int partition(FullEdge arr[], int start, int end)
{
	int pivot = arr[start].weight;

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i].weight <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i].weight <= pivot) {
			i++;
		}

		while (arr[j].weight > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(FullEdge arr[], int start, int end)
{
	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}