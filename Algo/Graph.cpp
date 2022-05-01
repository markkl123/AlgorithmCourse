#include "Graph.h"
int currentRoot = 0;

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
    Edge u_v = { v,c }, v_u = { u,c };
    GetAdjList(u).InsertFront(u_v);
    GetAdjList(u).InsertFront(v_u);
}

void Graph::RemoveEdge(int u, int v) {
    GetAdjList(u).DeleteNode(v);
    GetAdjList(v).DeleteNode(u);
}

void Graph::DFS(Graph G) {
    vector<char> visited;
    FullEdge* arrOfEdges;
    //רשימת קשתות של full edge 
    int i;
    for (i = 0;i < n;i++) {
        visited.push_back('w');
    }
    Visit(0, visited, arrOfEdges);
    for (i = 0;i < n;i++) {
        if (visited[i] == 'w') {
            Exit();
        }
    }
}
//change dfs not done
void Graph::Visit(int vertex, vector<char> visited, FullEdge* arrOfEdges) {
    visited[vertex] = 'g';

    Node* curr = Adjacency[vertex].GetHead();

    while (curr != nullptr) {
        if (visited[curr->Get_Edge().dest] == 'w') {
            arrOfEdge
            Visit(curr->Get_Edge().dest, visited, arrOfEdges);
        }
        curr = curr->Get_Next();
    }
    visited[vertex] = 'b';
}

void Kruskal() {

}



