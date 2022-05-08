#include "Graph.h"
int currentRoot = 0;
//Create a empty graph
void Graph::MakeEmptyGraph(int n) {
    this->n = n;
    for (int i = 0; i < n; i++)
        Adjacency.push_back(List());
}
//Check if there is a edge between two vertex
bool Graph::IsAdjacent(int u, int v) {
    return (GetAdjList(u).Find(v) != nullptr);
}
//Return the adjacency list
List& Graph::GetAdjList(int u) {
    return Adjacency[u - 1];
}
//Add edge to the graph
void Graph::AddEdge(int u, int v, int c) {
    Edge u_v = { v,c }, v_u = { u,c };
    arrOfEdges.push_back({ u, v, c });
    GetAdjList(u).InsertFront(u_v);
    GetAdjList(v).InsertFront(v_u);
}
//Remove edge to the graph
void Graph::RemoveEdge(int u, int v) {
    FullEdge fe;
    for (int i = 0; i < arrOfEdges.size(); i++)
    {
        fe = arrOfEdges[i];
        if ((fe.source == u && fe.dest == v) || (fe.source == v && fe.dest == u))
            arrOfEdges.erase(arrOfEdges.begin() + i);
    }
    m--;
    GetAdjList(u).DeleteNode(v);
    GetAdjList(v).DeleteNode(u);
}
//The algorithm DFS
bool Graph::DFS() {
    vector<char> visited;
    int i = 0;
    vector<FullEdge> arrOfEdges(m);

    for (i = 0;i < n;i++) {
        visited.push_back('w');
    }
    i = 0;
    Visit(0, visited, i);
    for (i = 0;i < n;i++) {
        if (visited[i] == 'w') {
            return false;
        }
    }
    return true;
}

void Graph::Visit(int vertex, vector<char> &visited, int& i) {
    visited[vertex] = 'g';
    
    Node* curr = Adjacency[vertex].GetHead();

    while (curr != nullptr) {
        
        if (visited[curr->Get_Edge().dest - 1] == 'w') {
            i += 1;
            Visit(curr->Get_Edge().dest - 1, visited, i);
        }
        curr = curr->Get_Next();
    }
    visited[vertex] = 'b';

}
//The algorithm Kruskal
int Graph::Kruskal() {
    int i, uRep, vRep, MSTWeight = 0;
    DisjointSets s(n);
    FullEdge curr;

    for (i = 0; i < n; i++) {
        s.MakeSet(i);
    }

    quickSort(arrOfEdges, 0, m - 1);
    for (i = 0; i < m; i++) {
        curr = arrOfEdges[i];

        vRep = s.Find(curr.source - 1);
        uRep = s.Find(curr.dest - 1);

        if (uRep != vRep) {
            MSTWeight += curr.weight;
            s.Union(uRep, vRep);
        }
    }
    return MSTWeight;
}

int Graph::partition(vector<FullEdge>& arr, int start, int end)
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

void Graph::quickSort(vector<FullEdge> &arr, int start, int end)
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
//The algorithm Prim
int Graph::Prim() {
    HeapMin Q(n);
    int MST_Weight, i;
    Pair u;
    bool* InT = new bool[n];
    for (i = 0; i < n; i++)
        InT[i] = false;

    Pair* min = new Pair[n];
    min[0] = { 0 ,0};

    for (i = 1; i < n; i++) {
        min[i] = { i,INT32_MAX };
    }

    Q.Build(min);
    while (!Q.isEmpty())
    {
        u = Q.DeleteMin();
        InT[u.data] = true;
        Node* curr = Adjacency[u.data].GetHead();
        Edge edge;
        while (curr != nullptr)
        {
            edge = curr->Get_Edge();
            if (!InT[edge.dest - 1] && edge.weight < min[edge.dest - 1].key)
            {
                min[edge.dest - 1].key = edge.weight;
                Q.DecreaseKey(edge.dest - 1, min[edge.dest - 1].key);
            }
            curr = curr->Get_Next();
        }
    }

    MST_Weight = 0;

    for (i = 0; i < n; i++)
        MST_Weight += min[i].key;

    return MST_Weight;
}


