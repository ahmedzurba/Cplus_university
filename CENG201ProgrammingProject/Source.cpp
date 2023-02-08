//11.1
//Ahmed Al Zurba    Ahmed Douhan
//this file is the driver file where we are taking the arguments from the command line and using them to run the program   
#include"Maze.h"
#include<string>
#include <fstream>
#include "Routing.h"
#include"StlRouting.h"
#include"Timer.h"

using namespace std;

#ifdef STLon
typedef StlRouting solver;
#else
typedef Routing solver;
#endif


int main(int argc,char* argv[]){
	
	
	string infile="",outfile="";
	//this comand arry is represent the existence of:
	// 0.Stack solution 1.Queue solution 2.Opt solution 3.Infile 4.Outfile 5.Time 6.Incoordinate 7.Outcoordinate 8.Help 
	bool comand[9] = { false, false, false, false, false, false, false ,false ,false};

	

	
	// read the command line from a array and save the existance in a boolean array
	for (int n = 1; n < argc; n++){
		if (((string)argv[n]) == "-Stack"){
				comand[0] = true;
		}
		else if (((string)argv[n]) == "-Queue"){
				comand[1] = true;
		}
		else if (((string)argv[n]) == "-Opt"){
				comand[2] = true;
		}
		else if (((string)argv[n]).substr(0, ((string)argv[n]).find('(')) == "-Infile"){
			comand[3] = true;
			infile = ((string)argv[n]).substr(((string)argv[n]).find('(') + 1, ((string)argv[n]).find(')') - ((string)argv[n]).find('(') - 1);
		}
		else if (((string)argv[n]).substr(0, ((string)argv[n]).find('(')) == "-Outfile"){
			comand[4] = true;
			outfile = ((string)argv[n]).substr(((string)argv[n]).find('(') + 1, ((string)argv[n]).find(')') - ((string)argv[n]).find('(') - 1);
		}
		else if (((string)argv[n]) == "-Time"){
				comand[5] = true;
		}
		else if (((string)argv[n]) == "-Incoordinate"){
				comand[6] = true;
		}
		else if (((string)argv[n]) == "-Outcoordinate"){
				comand[7] = true;
		}
		else if (((string)argv[n]) == "-Help"){
				comand[8] = true;
		}
	}
	if (comand[8]){
		string help = "Welcome to Maze solver program \n Our program object is to take a square maze with n columns and row then ";
		help = help + "the progrom wil routes the Robot through the maze to find the Goal,the ";
		help = help + "maze formats can be in two ways map format or coordinate format by x,y";
		help = help + "-Stack: If this switch is set the program will use the stack-based routing scheme";
		help = help + "-Opt: If this switch is set the program will use the our optimal routing scheme.";
		help = help + "-Queue: If this switch is set the program will use use the queue-based routing scheme.";
		help = help + "-Infile(string): Which the string is the input filename. `maze.txt'' as default input filename.";
		help = help + "-Outfile(string):Which the string is the output file name.``mazeout.txt'' as defult output filename.";
		help = help + "-Time: If this switch is set the program will write the time it takes the program to solve the maze.";
		help = help + "-Incoordinate: If this switch is set, the input file is in the coordinate format.default map format.";
		help = help + "-Outcoordinate: If this switch is set, the output file is to be in the coordinate format.default map format.";
		cout << help;
		exit(0);
	}
	//test the pre conditions
	if ((comand[0] && comand[1]) || (comand[0] && comand[2]) || (comand[1] && comand[2])){
		cout<< "Legal command line arguments must include exactly one of -Stack -Opt or -Queue.";
		exit(1);
	}
	if (!(comand[0] || comand[1] || comand[2])){
		cout<< "Legal command line arguments must include at least one of -Stack -Opt or -Queue.";
		exit(0);
	}

	if (!comand[3]){
		infile = "maze.txt";
	}
	if (!comand[4]){
		outfile = "mazeout.txt";
	}
	
	//for time calculation...
	Timer tmr;
	double time =0;
	
	bool solved = false;
	Maze maze;
	maze.read(infile, comand[6]);
	if (comand[0]){
	tmr.reset();
		solved = solver::Stack_Solving(maze.getmaze(), maze.getDimantion(), maze.getrobot(), maze.getgoal());
	time = tmr.elapsed();
	}
	else if (comand[1]){
	tmr.reset();
		solved = solver::Queue_Solving(maze.getmaze(), maze.getDimantion(), maze.getrobot(), maze.getgoal());
	time = tmr.elapsed();
	}
	else if (comand[2]){
	tmr.reset();
		solved = solver::Opt_Solving(maze.getmaze(), maze.getDimantion(), maze.getrobot(), maze.getgoal());
	time = tmr.elapsed();
	}
	if (solved)
	maze.write(outfile,comand[7]);
	if (comand[5])
	cout << time;


	return 0;
}
