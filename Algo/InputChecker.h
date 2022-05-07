#pragma once
#include "Graph.h"
#include <fstream>
#include <sstream>
class Graph;

void Exit(ofstream& myfile);
bool is_number(const string& s);
Graph* Text_to_Graph(const char* filename, int& u_to_Remove, int& v_to_Remove, ofstream& myfile);
void CheckEdge(int n, string u, string v, string c, int& u_out, int& v_out, int& c_out, ofstream& myfile);
int checkAmountOfEdges(string n, ofstream& myfile);