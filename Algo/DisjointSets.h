#pragma once

typedef struct {
	int parent;
	int size;
}Element;

const int MAX_SIZE = 100;

class DisjointSets
{
private:
	Element A[MAX_SIZE];
public:
	DisjointSets();
	void MakeSet(int x);
	int Find(int x);
	void Union(int repx, int repy);
};

