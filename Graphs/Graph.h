#ifndef GRAPH_
#define GRAPH_


using namespace std;

class Vertix;
class Edge{
public:
	int weight;
	Edge* next = nullptr;
	Vertix* v;
	Edge( Vertix &newv, int newweight){ v = &newv; weight = newweight; }
};
class Vertix{
public:
	int value;
	bool visited = 0;
	Edge* edge=nullptr;
	Vertix(int newvalue):value (newvalue){}
	
	bool addEdge(Edge *newEdge ){
		if (edge == nullptr)
			edge = newEdge;
		else {
			Edge* nextedge = edge;
			while (nextedge->next != nullptr){
				nextedge = nextedge->next;
			}
			nextedge->next = newEdge;
		}
		return true;
	}

};


class Graph{
private:
	Vertix **vertices;
	int edgesnum;
	int verticesnum;
	int findv(Vertix v)const;
	

public:
	//Graph();
	Graph(int arrysize);
	~Graph();
	int getNumVerticts()const;
	int getNumEdges()const;
	bool add(Vertix &start, Vertix &end, int edgeWeight);
	bool remove(Vertix &start, Vertix &end);
	int getEdgeWeight(Vertix &start, Vertix &end)const;
	void depthFirstSearch(Vertix &start, Vertix &end);
	void breadthFirstSearch(Vertix &start, Vertix &end);
	void ShortestPathDistance(Vertix &start, Vertix &end,int *weight);
};
#endif