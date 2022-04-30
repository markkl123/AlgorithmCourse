#include "Graph.h"

void Graph::MakeEmptyGraph(int n) {
    for (int i = 0; i < n; i++)
        Adjacency.push_back(List());
}

bool Graph::IsAdjacent(int u, int v) {
    return (GetAdjList(u).Find(v) != nullptr);
}

List& Graph::GetAdjList(int u) {
    return Adjacency[u - 1];
}

void Graph::AddEdge(int u, int v, int c) {
    GetAdjList(u).InsertFront({v,c});
    GetAdjList(u).InsertFront({u,c});
}

void Graph::RemoveEdge(int u, int v) {
    GetAdjList(u).DeleteNode(v);
    GetAdjList(v).DeleteNode(u);
}



