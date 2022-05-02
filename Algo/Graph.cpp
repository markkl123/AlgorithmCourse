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

FullEdge* Graph::DFS(Graph G) {
    vector<char> visited;
    int i = 0;
    FullEdge* arrOfEdges = new FullEdge[m];
    for (i = 0;i < n;i++) {
        visited.push_back('w');
    }
    Visit(0, visited, arrOfEdges, i);
    for (i = 0;i < n;i++) {
        if (visited[i] == 'w') {
            cout << "Kruskal NO MST\n Prim NO MST\nKruskal NO MST";
            exit(1);
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

int Graph::Kruskal(FullEdge* arrOfEdges, Graph G) {
    int i, uRep, vRep, weight = 0;
    DisjointSets s;
    Node* curr;
    
    for (i = 0; i < Adjacency.size(); i++) {
        s.MakeSet(i);
    }

    quickSort(arrOfEdges, 0, n-1);
    for (i = 0; i < Adjacency.size(); i++) {
        curr = Adjacency[i].GetHead();

        while (curr != nullptr) {
            vRep = s.Find(i);
            uRep = s.Find(Adjacency[i].GetHead()->Get_Edge().dest);

            if (uRep != vRep) {
                weight += curr->Get_Edge().weight;
                s.Union(uRep, vRep);
            }
            curr = curr->Get_Next();
        }
    }
    return weight;
}

int Graph::partition(FullEdge arr[], int start, int end)
{
    int pivot = arr[start].weight;

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i].weight <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i].weight <= pivot) {
            i++;
        }

        while (arr[j].weight > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void Graph::quickSort(FullEdge arr[], int start = 0, int end = -1)
{
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int Graph::Prim(Graph G) {
    HeapMin Q;
    bool* InT = new bool[n];
   
    int* min = new int[n];
    min[0] = 0;

    //Q.Build();
}


