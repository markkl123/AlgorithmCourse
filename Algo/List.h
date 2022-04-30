#pragma once
#include "Node.h"

class List
{
private:
    Node* Head = nullptr;
public:
    bool isEmpty();
    Node* Find(int key);
    Node* InsertFront(Edge edge);
    void DeleteNode(int v);
};

