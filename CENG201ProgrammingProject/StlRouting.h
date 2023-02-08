#ifndef _Stl_Routing
#define _Stl_Routing

#include"Position.h"
#include<stack>
#include<queue>


using namespace std;

class StlRouting{

public:
	static bool Stack_Solving(char ** maze, const int& size, const Position& robot, const Position& goal);
	static bool Queue_Solving(char ** maze, const int& size, const Position& robot, const Position& goal);
	static bool Opt_Solving(char ** maze, const int& size, const Position& robot, const Position& goal);


};
#endif