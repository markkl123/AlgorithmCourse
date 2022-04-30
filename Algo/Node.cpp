#include "Node.h"

Edge Node::Get_Edge() {
    return edge;
}

Node* Node::Get_Next() {
    return Next;
}

Node* Node::Get_Prev() {
    return Prev;
}
void Node::Set_Next(Node* Next) {
    Next = Next;
}

void Node::Set_Prev(Node* Prev) {
    Prev = Prev;
}

Node::~Node() {
    if (this->Get_Prev() != nullptr)
        this->Get_Prev()->Set_Next(this->Get_Next());

    this->Get_Next()->Set_Prev(this->Get_Prev());
}