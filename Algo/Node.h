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
    void Set_Next(Node* Next);
    void Set_Prev(Node* Prev);
    ~Node();
};

