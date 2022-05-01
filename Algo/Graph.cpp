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

FullEdge* Graph::DFS(Graph G) {
    vector<char> visited;
    int i = 0;
    FullEdge* arrOfEdges = new FullEdge[m];
    int i;
    for (i = 0;i < n;i++) {
        visited.push_back('w');
    }
    Visit(0, visited, arrOfEdges, i);
    for (i = 0;i < n;i++) {
        if (visited[i] == 'w') {
            Exit();
        }
    }
    return arrOfEdges;
}

void Graph::Visit(int vertex, vector<char> visited, FullEdge* arrOfEdges, int& i) {
    visited[vertex] = 'g';

    Node* curr = Adjacency[vertex].GetHead();

    while (curr != nullptr) {
        if (visited[curr->Get_Edge().dest] == 'w') {
            arrOfEdges[i] = { vertex, curr->Get_Edge().dest, curr->Get_Edge().weight };
            i += 1;
            Visit(curr->Get_Edge().dest, visited, arrOfEdges, i);
        }
        curr = curr->Get_Next();
    }
    visited[vertex] = 'b';
}

void Graph::Kruskal(FullEdge* arrOfEdges) {
    int i, uRep, vRep;
    
    //quickSort(arrOfEdges, G.begin(), G.end());  // increasing weight
    for (i = 0; i < Adjacency.size(); i++) {
        //uRep = Find(Adjacency[i].second.first);
        //vRep = Find(Adjacency[i].second.second);
        if (uRep != vRep) {
            //T.push_back(G[i]);  // add to tree
            //Union(uRep, vRep);
        }
    }
}



