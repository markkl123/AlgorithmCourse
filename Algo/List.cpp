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

