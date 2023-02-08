#include "Graph.h"
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>

struct qu{
	int wei;
	Vertix* qv;
};


bool contans(vector<Vertix*> ver,Vertix *a){
	bool contan = false;
	for (int i = 0; i < (int)ver.size(); i++)
		if (ver[i]->value == a->value)
			contan = true;
	return contan;
}

int Graph::findv(Vertix v)const{
	int index = -1;
	if (verticesnum != 0)
	for (int i = 0; i < verticesnum; i++){
		if (v.value == vertices[i]->value)
			index = i;
	}
	return index;
}
/*Graph::Graph(){
	verticesnum = 0;
	edgesnum = 0;
}*/
Graph::~Graph(){

}
Graph::Graph(int arraysize){
	vertices = new Vertix*[arraysize];
	verticesnum = 0;
	edgesnum = 0;
}
int Graph::getNumVerticts()const{
	return verticesnum;
}
int Graph::getNumEdges()const{
	return edgesnum;
}
bool Graph::add( Vertix& start, Vertix& end, int edgeWeight){
	int startindex = findv(start), endindex = findv(end);
	if (startindex == -1){ vertices[verticesnum] = &start;startindex=verticesnum; verticesnum++; }
	if (endindex == -1){ vertices[verticesnum] = &end; endindex = verticesnum; verticesnum++; }
	vertices[startindex]->addEdge(new Edge(*vertices[endindex],edgeWeight));
	vertices[endindex]->addEdge(new Edge(*vertices[startindex], edgeWeight));
	edgesnum++;
	return 1;
}
bool Graph::remove(Vertix &start, Vertix &end){//// if no edge delete vertix.....
	int startindex = findv(start), endindex = findv(end);
	bool startedg = false, endedg = false;

	if (startindex == -1 || endindex == -1)return startedg&&endedg;
	else{
		
		Edge* temp = nullptr;
		///chain of start vertix
		if (vertices[startindex]->edge->v->value == end.value){//if its the first chain(in the start vertix)
			temp = vertices[startindex]->edge;
			vertices[startindex]->edge = vertices[startindex]->edge->next;
			temp->next = nullptr;
			delete temp;
			temp = nullptr;
			startedg=true;
		}
		else{
			Edge* prev = vertices[startindex]->edge, *curr = vertices[startindex]->edge->next;
			while (curr != nullptr&&curr->v->value != end.value){
				prev = curr;
				curr = curr->next;
			}
			if (curr == nullptr)
				startedg=false;
			else{
				prev->next = curr->next;
				curr->next = nullptr;
				delete curr;
				curr = nullptr;
				startedg=true;
			}
		
		}////// the chain of end vertix
		if (vertices[endindex]->edge->v->value == start.value){//if its the first chain(in the end vertix)
			temp = vertices[endindex]->edge;
			vertices[endindex]->edge = vertices[endindex]->edge->next;
			temp->next = nullptr;
			delete temp;
			temp = nullptr;
			endedg = true;
		}
		else{
			Edge* prev = vertices[endindex]->edge, *curr = vertices[endindex]->edge->next;
			while (curr != nullptr&&curr->v->value != start.value){
				prev = curr;
				curr = curr->next;
			}
			if (curr == nullptr){
				endedg = false;
			}
			else{
				prev->next = curr->next;
				curr->next = nullptr;
				delete curr;
				curr = nullptr;
				endedg = true;
			}
		}

		if (startedg&&endedg)edgesnum--;
		return startedg&&endedg;
	}//just for first......
	cout<<(startedg&&endedg);
}
int Graph::getEdgeWeight(Vertix &start, Vertix &end)const{
	int startindex = findv(start),endindex = findv(end);
	int weight = -1;
	if (startindex != -1 && endindex != -1){
			Edge *curr = vertices[startindex]->edge;
			while (curr != nullptr&&curr->v->value != end.value){
				curr = curr->next;
			}
			if (curr != nullptr)
				weight= curr->weight;
		}
	return weight;
}
void Graph::depthFirstSearch(Vertix &start, Vertix &end){
	int sum = 0;
	for (int i = 0; i < verticesnum; i++){
		vertices[i]->visited = 0;
	}
	int startindex = findv(start),endindex=findv(end);
	std::stack<Vertix*> mystack;
	mystack.push(vertices[startindex]);
	vertices[startindex]->visited = 1;
	while (!mystack.empty()&&mystack.top()->value!=end.value){
		Edge* curr = mystack.top()->edge, *min = nullptr;
		while (curr != nullptr&&curr->v->visited){//check if there still unvisited vertices
			curr = curr->next;
		}
		if (curr != nullptr){//if there make it as min an compare it with the unvisited vertices
			min = curr;
			while (curr != nullptr){
				if (!(curr->v->visited) && curr->weight < min->weight)
					min = curr;
				curr = curr->next;
			}
			sum += min->weight;
			mystack.push(min->v);
			min->v->visited = 1;
		}
		else{
				//cout << mystack.top()->value;
			Vertix* temp = mystack.top();
				mystack.pop();
				Edge* tempe = temp->edge;
				while (tempe != nullptr&&tempe->v->value != mystack.top()->value)
					tempe = tempe->next;
				sum -= tempe->weight;
			}	
	}
	if (mystack.empty())
		cout << -1;
	else
		cout << sum;
}
void Graph::breadthFirstSearch(Vertix &start, Vertix &end){
	for (int i = 0; i < verticesnum; i++){
		vertices[i]->visited = 0;
	}
	int startindex = findv(start), endindex = findv(end);
	queue<qu> myQueue;
	qu newa; newa.qv = vertices[startindex]; newa.wei = 0;
	myQueue.push(newa);
	vertices[startindex]->visited = 1;
	int distance = -1;
	bool found = false;
	while (!myQueue.empty()&&!found){
		Edge* curr = myQueue.front().qv->edge;
		Edge* min = nullptr;
		Edge* star = myQueue.front().qv->edge;
		int parentwieght = myQueue.front().wei;
		//cout << myQueue.front()->value;
		myQueue.pop();
		bool still = true;
		while (still){
			min = nullptr;
			while (curr != nullptr&&min==nullptr){
				if (!(curr->v->visited)){
					min = curr;
				}
				
				if (min==nullptr)
				curr = curr->next;
				
			}
			if (min == nullptr)
				still = false;
			else{
				curr = min;//myQueue.front()->edge;
				while (curr != nullptr){
					if (!(curr->v->visited)&& min->weight > curr->weight)
						min = curr;
					curr = curr->next;
				}
				if (min->v->value == end.value)
					found = true;
				min->v->visited = 1;
				qu mnim; mnim.qv = min->v; mnim.wei = (min->weight + parentwieght);
				distance = mnim.wei;
				myQueue.push(mnim);
				curr = star;
			}
		}
	}
	if (myQueue.empty())
		cout << -1;
	else
		cout << distance;
}
void Graph::ShortestPathDistance(Vertix &start, Vertix &end,int *weight){
	int startindex = findv(start), endindex = findv(end);
	vector<Vertix*> v;
	for (int i = 0; i < verticesnum; i++)
		weight[i] = -1;
	////////////////////////////
	v.push_back(vertices[startindex]);
	Edge* curr = vertices[startindex]->edge;
	Edge* min = nullptr;
	min = vertices[1]->edge;
	while (curr != nullptr){
		weight[findv(*(curr->v))] = curr->weight;
		curr = curr->next;
	}
	while (v.size()<verticesnum){
		////////find min
		int m =INT_MAX,index=-1;
		for (int i = 0; i<verticesnum; i++){
			if (weight[i] != -1 && weight[i] < m&&!contans(v,vertices[i])){
				m = weight[i];
				index = i;
			}
		}
		v.push_back(vertices[index]);
		curr =vertices[index]->edge;
		while (curr != nullptr){       		
			if (!contans(v, curr->v))
				if (weight[findv(*curr->v)]>weight[findv(*v[v.size() - 1])] + curr->weight||weight[findv(*curr->v)] == -1)
				weight[findv(*curr->v)] = weight[findv(*v[v.size() - 1])] + curr->weight;
			curr = curr->next;
		}

		
	}
	cout << weight[findv(end)];
}