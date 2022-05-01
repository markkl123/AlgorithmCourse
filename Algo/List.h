#pragma once
#include "Node.h"

class List
{
private:
    Node* Head = nullptr;
public:
    bool isEmpty();
    Node* GetHead();
    Node* Find(int key);
    Node* InsertFront(Edge edge);
    void DeleteNode(int v);
    int partition(FullEdge arr[], int start, int end);
    void quickSort(FullEdge arr[], int start = 0, int end = -1);
};

