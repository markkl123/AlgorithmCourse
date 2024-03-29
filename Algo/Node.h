#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

class Node;

struct Edge {
    int dest, weight;
};
struct FullEdge {
    int source,dest, weight;
};

class Node
{
private:
    Edge edge;
    Node* Next = nullptr;
    Node* Prev = nullptr;
public:
    Node(Edge edge, Node* Next = nullptr, Node* Prev = nullptr) : edge(edge), Next(Next), Prev(Prev) {}
    Edge Get_Edge();
    Node* Get_Next();
    Node* Get_Prev();
    void Set_Next(Node* newNext);
    void Set_Prev(Node* newPrev);
    ~Node();
};

