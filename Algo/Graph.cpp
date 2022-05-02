#include "Graph.h"
int currentRoot = 0;

void Graph::MakeEmptyGraph(int n) {
    this->n = n;
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
    Edge u_v = { v,c }, v_u = { u,c };
    GetAdjList(u).InsertFront(u_v);
    GetAdjList(v).InsertFront(v_u);
}

void Graph::RemoveEdge(int u, int v) {
    GetAdjList(u).DeleteNode(v);
    GetAdjList(v).DeleteNode(u);
}

void Graph::DFS(Graph G) {
    char* visited = new char(8);
    int i;
    for (i = 0;i < n;i++) {
        visited[i] = 'w';
    }

    for (i = 0;i < n;i++) {
        if (visited[i] = 'w') {
            currentRoot = i;
            Visit(i);
        }
    }
}
//change dfs not done
void Graph::Visit(int vertex) {
    char* visited = new char(8);
    visited[vertex] = 'g';

    Node* curr = Adjacency[vertex].GetHead();

    while (curr != nullptr) {
        if (visited[curr->Get_Edge().dest] == 'w') {

            Visit(curr->Get_Edge().dest);
        }
        curr = curr->Get_Next();
    }
    visited[vertex] = 'b';
}



