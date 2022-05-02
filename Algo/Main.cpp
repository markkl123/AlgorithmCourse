#include "InputChecker.h"

int main(int argc, const char* argv[])
{
	Graph* g;
	int u_To_Remove, v_To_Remove;
	g = Text_to_Graph(argv[1], u_To_Remove, v_To_Remove);
	if (!g->DFS()) {
		cout << "Kruskal NO MST\nPrim NO MST\nKruskal2 NO MST\n";
	}
	else {
		cout << "Prim " << g->Prim() << "\n";
		cout << "Kruskal " << g->Kruskal() << "\n";
		g->RemoveEdge(u_To_Remove, v_To_Remove);
		if (!g->DFS()) {
			cout << "Kruskal2 NO MST";
		}
		else
			cout << "Kruskal2 " << g->Kruskal();
	}
}