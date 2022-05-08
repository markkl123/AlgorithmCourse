#pragma once
using namespace std;
#include <vector>

typedef struct {
	int parent;
	int size;
}Element;

class DisjointSets
{
private:
	vector<Element> A;

public:
	DisjointSets(int n);
	void MakeSet(int x);
	int Find(int x);
	void Union(int repx, int repy);
};

