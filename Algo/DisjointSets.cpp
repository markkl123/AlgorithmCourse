#include "DisjointSets.h"

DisjointSets::DisjointSets(int n):A(n) {
	for (int i = 0;i < n;i++) {
		A[i].parent = -1;
		A[i].size = 0;
	}
}

void DisjointSets::MakeSet(int x) {
	A[x].parent = x;
	A[x].size = 1;
}

int DisjointSets::Find(int x) {
	if (A[x].parent == x)
		return x;
	else {
		int parent = Find(A[x].parent);
		A[x].parent = parent;
		return parent;
	}
}

void DisjointSets::Union(int repx, int repy) {
	if (A[repx].size > A[repy].size) {
		A[repy].parent = repx;
		A[repx].size += A[repy].size;
	}
	else {
		A[repx].parent = repy;
		A[repy].size += A[repx].size;
	}
}