#include "Graph.h"
#include <fstream>

void Exit()
{
	cout << "invalid input";
	exit(1);
}

bool is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

void Validfile(int argc,const char* argv[])
{
	ifstream infile(argv[1]);

	if (!(argc == 3 && infile.good()))
		Exit();
}

Graph& Text_to_Graph(char* filename, Edge& edge_to_Remove)
{
	std::ifstream infile(filename);
	string line;
	while (infile >> line)
	{
		//sunday
	}
}

void CheckEdge(int n, string u, string v, string c)
{
	if (!(is_number(u) && is_number(v) && is_number(c)))
		Exit();

	int iu = stoi(u), iv = stoi(v);

	if (n < 0 || iu > n || iv > n || iu < 1 || iv < 1)
		Exit();
}

int checkAmountOfEdges(string n)
{
	if (!is_number(n))
		Exit();
	int in = stoi(n);
	if (in < 0)
		Exit();
	return in;
}






