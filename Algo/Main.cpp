#include "InputChecker.h"

int main(int argc, const char* argv[])
{
	vector<FullEdge> e = { {1,2,3},{1,3,1},{2,3,4},{5,6,2}};
	FullEdge f;
	HeapMin heap = e;
	for (int i = 0; i < 4; i++)
	{
		f = heap.DeleteMin().data;
		cout << "(" << f.source << ", " << f.dest << ", " << f.weight << ")" << endl;
	}
}