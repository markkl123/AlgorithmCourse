#include "InputChecker.h"

int main(int argc, const char* argv[])
{
	Graph* g;
	int u_To_Remove, v_To_Remove, Prim ,Kruskal , Kruskal2;
	ofstream myfile;
	Validarg(argc, argv);
	myfile.open(argv[2]);
	g = Text_to_Graph(argv[1], u_To_Remove, v_To_Remove, myfile);
	if (!g->DFS()) {
		cout << "Kruskal NO MST\nPrim NO MST\nKruskal2 NO MST\n";
		myfile << "Kruskal NO MST\nPrim NO MST\nKruskal2 NO MST\n";
	}
	else {
		Prim = g->Prim();
		Kruskal = g->Kruskal();
		cout << "Prim " << Prim << "\n" << "Kruskal " << Kruskal << "\n";
		myfile << "Prim " << Prim << "\n" << "Kruskal " << Kruskal << "\n";
		g->RemoveEdge(u_To_Remove, v_To_Remove);
		if (!g->DFS()) {
			cout << "Kruskal2 NO MST";
			myfile << "Kruskal2 NO MST";
		}
		else
		{
			Kruskal2 = g->Kruskal();
			cout << "Kruskal2 " << Kruskal2;
			myfile << "Kruskal2 " << Kruskal2;
		}
	}
	myfile.close();
}