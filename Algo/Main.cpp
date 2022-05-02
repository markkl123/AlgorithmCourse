#include "InputChecker.h"

int main(int argc, const char* argv[])
{
	Graph* g;
	int u_To_Remove, v_To_Remove;
	g = Text_to_Graph(argv[1], u_To_Remove, v_To_Remove);
	g->RemoveEdge(u_To_Remove, v_To_Remove);
}