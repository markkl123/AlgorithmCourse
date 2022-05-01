#include "InputChecker.h"

int main(int argc,const char* argv[])
{
	Graph g = 8;
	g.AddEdge(1, 2,1);
	g.AddEdge(3, 4,2);
	g.AddEdge(1,5, 2);
	g.AddEdge(3, 1, 2);
	g.AddEdge(1, 4, 2);
	cout << g.GetVertexAmount();

}