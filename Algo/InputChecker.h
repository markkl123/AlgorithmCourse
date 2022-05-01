#pragma once
#include "Graph.h"
#include <fstream>
#include <sstream>
class Graph;

void Exit();
bool is_number(const string& s);
void Validarg(int argc, const char* argv[]);
Graph* Text_to_Graph(char* filename, int& u_to_Remove, int& v_to_Remove);
void CheckEdge(int n, string u_v_c, int& u_out, int& v_out, int& c_out);
int checkAmountOfEdges(string n);