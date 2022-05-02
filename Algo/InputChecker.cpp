#include "InputChecker.h"

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

void Validarg(int argc,const char* argv[])
{
	if (argc != 3)
		Exit();

	ifstream infile(argv[1]);

	if (!infile.good())
		Exit();
}

Graph* Text_to_Graph(const char* filename,int& u_to_Remove, int& v_to_Remove)
{
	int u, v, c, i;
	string su, sv, sc;
	ifstream infile(filename);
	if (!infile.good())
		Exit();
	string line;
	infile >> line;
	int n = checkAmountOfEdges(line);
	infile >> line;
	int m = checkAmountOfEdges(line);
	Graph* res = new Graph(n);
	for (i = 0; i<m && infile >> su >> sv >> sc ;i++)
	{
		CheckEdge(n, su,sv,sc, u, v, c);
		res->AddEdge(u, v, c);
	}
	if (!(infile >> su >> sv) || i != m)
		Exit();
	
	CheckEdge(n, su, sv, "0", u_to_Remove, v_to_Remove,c); //Reduction

	if (infile >> line)
		Exit();
	if (!res->IsAdjacent(u_to_Remove, v_to_Remove))
		Exit();

	return res;
}

void CheckEdge(int n, string u,string v,string c,int &u_out,int &v_out,int &c_out)
{
	if (!(is_number(u) && is_number(v) && is_number(c)))
		Exit();

	int iu = stoi(u), iv = stoi(v),ic = stoi(c);

	if (n < 0 || iu > n || iv > n || iu < 1 || iv < 1)
		Exit();

	u_out = iu;
	v_out = iv;
	c_out = ic;
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






