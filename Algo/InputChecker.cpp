#include "InputChecker.h"

void Exit(ofstream &myfile)
{
	cout << "invalid input";
	if (myfile.good())
	myfile << "invalid input";
	exit(1);
}

bool is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

Graph* Text_to_Graph(const char* filename,int& u_to_Remove, int& v_to_Remove, ofstream& myfile)
{
	int u, v, c, i;
	string su, sv, sc;
	ifstream infile(filename);
	if (!infile.good())
		Exit(myfile);
	string line;
	infile >> line;
	int n = checkAmountOfEdges(line, myfile);
	infile >> line;
	int m = checkAmountOfEdges(line, myfile);
	Graph* res = new Graph(n, m);
	for (i = 0; i<m && infile >> su >> sv >> sc ;i++)
	{
		CheckEdge(n, su,sv,sc, u, v, c, myfile);
		res->AddEdge(u, v, c);
	}
	if (!(infile >> su >> sv) || i != m)
		Exit(myfile);
	
	CheckEdge(n, su, sv, "0", u_to_Remove, v_to_Remove,c, myfile); //Reduction

	if (infile >> line)
		Exit(myfile);
	if (!res->IsAdjacent(u_to_Remove, v_to_Remove))
		Exit(myfile);

	return res;
}

void CheckEdge(int n, string u,string v,string c,int &u_out,int &v_out,int &c_out, ofstream& myfile)
{
	if (!(is_number(u) && is_number(v) && is_number(c)))
		Exit(myfile);

	int iu = stoi(u), iv = stoi(v),ic = stoi(c);

	if (n < 0 || iu > n || iv > n || iu < 1 || iv < 1)
		Exit(myfile);

	u_out = iu;
	v_out = iv;
	c_out = ic;
}

int checkAmountOfEdges(string n, ofstream& myfile)
{
	if (!is_number(n))
		Exit(myfile);
	int in = stoi(n);
	if (in < 0)
		Exit(myfile);
	return in;
}






