//26.12
#include "Maze.h"


Maze::Maze(){
}
void Maze::read(const string& file, bool coordinate){
	fstream myfile(file);
	string line = "";
	if (myfile.is_open()){
		///read the first line for the dimanation
		getline(myfile, line);
		if (atoi(line.c_str()) > 1){
			dimantion = atoi(line.c_str());
		}
		else{
			cerr << "The text should start with a number in the first line.";
			exit(0);
		}
		//build the 2d array
		map = new char*[dimantion];
		for (int i = 0; i < dimantion; i++){
			map[i] = new char[dimantion];
		}
		//intiliz the array
		for (int R = 0; R < dimantion; R++){
			for (int C = 0; C < dimantion; C++)
				map[R][C] = ' ';
		}
		//fill the array with our maze
		if (coordinate){
			int row = 0;
			while (getline(myfile, line)){
				if (line.at(0) == 'X' || line.at(0) == 'R' || line.at(0) == 'G')
					if ((line.at(2) - '0') < dimantion && (line.at(4) - '0') < dimantion && (line.at(2) - '0') >= 0 && (line.at(4) - '0') >= 0)
						map[line.at(2) - '0'][line.at(4) - '0'] = line.at(0);
					else{
						cerr << "illegal characters";
						exit(1);
					}
			}
		}
		else
		{
			int row = 0;
			while (getline(myfile, line)){

				for (int column = 0; column < line.length() && column < dimantion; column++){
					if (line.at(column) == ' ' || line.at(column) == 'X' || line.at(column) == 'R' || line.at(column) == 'G')
						map[row][column] = line.at(column);
					else
					{
						cerr << "illegal characters\n";
						exit(1);
					}
				}
				row++;
			}
			if (row < dimantion){
				cerr << "Missing Line";
				exit(1);
			}
		}
		myfile.close();
		if (!search()){
			cerr << "Missing characters";
			exit(1);
		}
	}
	else{
		cerr << "Unable to open input file";
			exit(1);
	}

}
void Maze::write(const string& file, bool coordinate){
	fstream myfile(file);
	if (myfile.is_open()){
		if (!coordinate){
			for (int R = 0; R < dimantion; R++){
				for (int C = 0; C < dimantion; C++)
					myfile << map[R][C];
				myfile << endl;
			}
		}
		else{
			for (int R = 0; R < dimantion; R++){
				for (int C = 0; C < dimantion; C++)
					if (map[R][C] == '*')
						myfile << map[R][C] << R << C << endl;
			}
		}
		myfile.close();
	}
	else{
		cerr << "Unable to open output file";
		exit(1);
	}
}
bool Maze::search(){
	bool robot=false, goal=false;
	for (int R = 0; R < dimantion; R++){
		for (int C = 0; C < dimantion; C++)
			if (map[R][C] == 'R'){
				robotpos.setx(R); robotpos.sety(C);
				robot = true;
			}
			else if (map[R][C] == 'G'){
				goalpos.setx(R); goalpos.sety(C);
				goal = true;
			}
	}
	return robot&&goal;
}
Position Maze::getrobot()const{
	return robotpos;
}
Position Maze::getgoal()const{
	return goalpos;
}
char** Maze::getmaze()const{
	return map;
}
int Maze::getDimantion()const{
	return dimantion;
}

