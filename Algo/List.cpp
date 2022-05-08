#include "List.h"

Node* List::GetHead() {
	return Head;
}
//Check if the list is empty
bool List::isEmpty() {
	return Head == nullptr;
}
//Find a given key in the list 
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
//Insert the node to the front of the list
Node* List::InsertFront(Edge edge) {
	Node* newEdge = new Node(edge);
	newEdge->Set_Next(Head);
	if (Head != nullptr)
		Head->Set_Prev(newEdge);
	Head = newEdge;
	return newEdge;
}
//Delete the node from the list
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