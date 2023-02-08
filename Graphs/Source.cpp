///the program will print -1 if there is ni such vertix or if there is no path to distination

#include <iostream>
#include "Graph.h"
#include <fstream>
#include<string>

using namespace std;


int main(int argc, char** argv){
	
	
	
	ifstream myfile(argv[1]);
	int vernum=0, edgenum;
	myfile >> vernum >> edgenum;
	int v1, v2, w;
	
	Graph a(vernum);
	while (myfile>>v1>>v2>>w)
	a.add(*(new Vertix(v1)), *(new Vertix(v2)), w);
	
	string b,d;
	int start, end;
	cin >> b>>d;
	cin >> start >> end;
	
	
	if (d.compare("DFS")==0)
	a.depthFirstSearch(*(new Vertix(start)), *(new Vertix(end)));
	if (d.compare("BFS")==0)
	a.breadthFirstSearch(*(new Vertix(start)), *(new Vertix(end)));
	if (d.compare("DIJKSTRA")==0){
		int *weight = new int[vernum];
		a.ShortestPathDistance(*(new Vertix(start)), *(new Vertix(end)), weight);
	}
	
	
	
	return 0;
}