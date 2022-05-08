#include "Node.h"

Edge Node::Get_Edge() {
    return edge;
}
//Get the next node
Node* Node::Get_Next() {
    return Next;
}
//Get the prev node
Node* Node::Get_Prev() {
    return Prev;
}
//Set the next node
void Node::Set_Next(Node* newNext) {
    if (this)
        Next = newNext;
}
//Set the prev node
void Node::Set_Prev(Node* newPrev) {
    if (this)
        this->Prev = newPrev;
}

Node::~Node() {
    if (this->Get_Prev() != nullptr)
        this->Get_Prev()->Set_Next(this->Get_Next());

    this->Get_Next()->Set_Prev(this->Get_Prev());
}