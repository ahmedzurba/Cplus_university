//Ahmed Al Zurba          Ahmed Douhan
//11.1
//the solving methodes using stl stack and queue impletation

#include"StlRouting.h"
#include<iostream>



int getEast1(char ** maze, const int& size, const Position& cur, const Position& goal){
	if (cur.east().getx() < size&&cur.east().getx() >= 0 && maze[cur.east().getx()][cur.east().gety()] != 'X'&&cur.east().gety() < size&&cur.east().gety() >= 0 && maze[cur.east().getx()][cur.east().gety()] != '*'&& maze[cur.east().getx()][cur.east().gety()] != 'R')
		if (maze[cur.east().getx()][cur.east().gety()] == 'G')
			return 2;
		else
			return 1;
	else
		return 0;
}
int getWest1(char ** maze, const int& size, const Position& cur, const Position& goal){
	if (cur.west().getx() < size&&cur.west().getx() >= 0 && maze[cur.west().getx()][cur.west().gety()] != 'X'&&cur.west().gety() < size&&cur.west().gety() >= 0 && maze[cur.west().getx()][cur.west().gety()] != '*'&& maze[cur.west().getx()][cur.west().gety()] != 'R')
		if (maze[cur.west().getx()][cur.west().gety()] == 'G')
			return 2;
		else
			return 1;
	else
		return 0;
}
int getNorth1(char ** maze, const int& size, const Position& cur, const Position& goal){
	if (cur.north().getx() < size&&cur.north().getx() >= 0 && maze[cur.north().getx()][cur.north().gety()] != 'X'&&cur.north().gety() < size&&cur.north().gety() >= 0 && maze[cur.north().getx()][cur.north().gety()] != '*'&& maze[cur.north().getx()][cur.north().gety()] != 'R')
		if (maze[cur.north().getx()][cur.north().gety()] == 'G')
			return 2;
		else
			return 1;
	else
		return 0;
}
int getSouth1(char ** maze, const int& size, const Position& cur, const Position& goal){
	if (cur.south().getx() < size&&cur.south().getx() >= 0 && maze[cur.south().getx()][cur.south().gety()] != 'X'&&cur.south().gety() < size&&cur.south().gety() >= 0 && maze[cur.south().getx()][cur.south().gety()] != '*'&& maze[cur.south().getx()][cur.south().gety()] != 'R')
		if (maze[cur.south().getx()][cur.south().gety()] == 'G')
			return 2;
		else
			return 1;
	else
		return 0;
}





bool StlRouting::Stack_Solving(char ** maze, const int& size, const Position& robot, const Position& goal){
	stack<Position> solution;
	stack<Position> storage;
	int solCount = 0;
	int poCount = 0;
	bool found = false;
	bool empty_space = false;

	if (getWest1(maze, size, robot, goal) == 2)
		found = true;
	else if (getWest1(maze, size, robot, goal)){
		storage.push(robot.west()); poCount++;
		empty_space = true;
	}

	if (getNorth1(maze, size, robot, goal) == 2)
		found = true;
	else if (getNorth1(maze, size, robot, goal)){
		storage.push(robot.north()); poCount++;
		empty_space = true;
	}

	if (getSouth1(maze, size, robot, goal) == 2)
		found = true;
	else if (getSouth1(maze, size, robot, goal)){
		storage.push(robot.south()); poCount++;
		empty_space = true;
	}

	if (getEast1(maze, size, robot, goal) == 2)
		found = true;
	else if (getEast1(maze, size, robot, goal)){
		storage.push(robot.east()); poCount++;
		empty_space = true;
	}


	while (!found&&!storage.empty()){
		if (empty_space){
			empty_space = false;
			solution.push(storage.top()); solCount++;
			storage.pop();
			maze[solution.top().getx()][solution.top().gety()] = '*';


			if (getWest1(maze, size, solution.top(), goal) == 2)
				found = true;
			else if (getWest1(maze, size, solution.top(), goal)){
				storage.push(solution.top().west()); poCount++;
				empty_space = true;
			}


			if (getNorth1(maze, size, solution.top(), goal) == 2)
				found = true;
			else if (getNorth1(maze, size, solution.top(), goal)){
				storage.push(solution.top().north()); poCount++;
				empty_space = true;
			}

			if (getSouth1(maze, size, solution.top(), goal) == 2)
				found = true;
			else if (getSouth1(maze, size, solution.top(), goal)){
				storage.push(solution.top().south()); poCount++;
				empty_space = true;
			}

			if (getEast1(maze, size, solution.top(), goal) == 2)
				found = true;
			else if (getEast1(maze, size, solution.top(), goal)){
				storage.push(solution.top().east()); poCount++;
				empty_space = true;
			}
		}
		else{
			while (!(storage.top().isEquale(solution.top().east()) || storage.top().isEquale(solution.top().west()) || storage.top().isEquale(solution.top().north()) || storage.top().isEquale(solution.top().south()))){
				maze[solution.top().getx()][solution.top().gety()] = ' ';
				solution.pop();
			}
			empty_space = true;
		}
	}
	if (found)
		cout << "Goal found! " << solCount << " positions explored, unexplored list contains " << poCount-solCount << " positions." << endl;
	else
		cout << "Goal not found! " << solCount << " positions explored." << endl;
	return found;
}
bool StlRouting::Queue_Solving(char ** maze, const int& size, const Position& robot, const Position& goal){
	queue<Position> storage;
	Position temp;
	int solCount = 0;
	int poCount = 0;
	bool found = false;
	bool empty_space = false;

	if (getWest1(maze, size, robot, goal) == 2)
		found = true;
	else if (getWest1(maze, size, robot, goal)){
		storage.push(robot.west());
		maze[robot.west().getx()][robot.west().gety()] = '*';
		empty_space = true;
	}

	if (getNorth1(maze, size, robot, goal) == 2)
		found = true;
	else if (getNorth1(maze, size, robot, goal)){
		storage.push(robot.north()); poCount++;
		maze[robot.north().getx()][robot.north().gety()] = '*';
		empty_space = true;
	}

	if (getSouth1(maze, size, robot, goal) == 2)
		found = true;
	else if (getSouth1(maze, size, robot, goal)){
		storage.push(robot.south()); poCount++;
		maze[robot.south().getx()][robot.south().gety()] = '*';
		empty_space = true;
	}

	if (getEast1(maze, size, robot, goal) == 2)
		found = true;
	else if (getEast1(maze, size, robot, goal)){
		storage.push(robot.east()); poCount++;
		maze[robot.east().getx()][robot.east().gety()] = '*';
		empty_space = true;
	}


	while (!found&&!storage.empty()){

		empty_space = false;
		temp = storage.front();
		storage.pop(); solCount++;
		maze[temp.getx()][temp.gety()] = '*';


		if (getWest1(maze, size, temp, goal) == 2)
			found = true;
		else if (getWest1(maze, size, temp, goal)){
			storage.push(temp.west()); poCount++;
			maze[temp.west().getx()][temp.west().gety()] = '*';
			empty_space = true;
		}


		if (getNorth1(maze, size, temp, goal) == 2)
			found = true;
		else if (getNorth1(maze, size, temp, goal)){
			storage.push(temp.north()); poCount++;
			maze[temp.north().getx()][temp.north().gety()] = '*';
			empty_space = true;
		}

		if (getSouth1(maze, size, temp, goal) == 2)
			found = true;
		else if (getSouth1(maze, size, temp, goal)){
			storage.push(temp.south()); poCount++;
			maze[temp.south().getx()][temp.south().gety()] = '*';
			empty_space = true;
		}

		if (getEast1(maze, size, temp, goal) == 2)
			found = true;
		else if (getEast1(maze, size, temp, goal)){
			storage.push(temp.east());	poCount++;
			maze[temp.east().getx()][temp.east().gety()] = '*';
			empty_space = true;
		}
	}
	if (found)
		cout << "Goal found! " << solCount << " positions explored, unexplored list contains " << poCount-solCount << " positions." << endl;
	else
		cout << "Goal not found! " << solCount << " positions explored." << endl;
	return found;

}
bool StlRouting::Opt_Solving(char ** maze, const int& size, const Position& robot, const Position& goal){
	
	stack<Position> solution;
	stack<Position> storage;
	int solCount = 0;
	int poCount = 0;
	bool found = false;
	bool empty_space = false;




	/////At First scaning the empty space near the robot and insert them in my stack
	if (robot.getx() > goal.getx() && robot.gety() < goal.gety()){

		if (getEast1(maze, size, robot, goal) == 2)
			found = true;
		else if (getEast1(maze, size, robot, goal)){
			storage.push(robot.east()); poCount++;
			empty_space = true;
		}
		if (getNorth1(maze, size, robot, goal) == 2)
			found = true;
		else if (getNorth1(maze, size, robot, goal)){
			storage.push(robot.north()); poCount++;
			empty_space = true;
		}
		if (getSouth1(maze, size, robot, goal) == 2)
			found = true;
		else if (getSouth1(maze, size, robot, goal)){
			storage.push(robot.south()); poCount++;
			empty_space = true;
		}
		if (getWest1(maze, size, robot, goal) == 2)
			found = true;
		else if (getWest1(maze, size, robot, goal)){
			storage.push(robot.west()); poCount++;
			empty_space = true;
		}
	}
	else if (robot.getx() < goal.getx() && robot.gety() > goal.gety()){
		if (getWest1(maze, size, robot, goal) == 2)
			found = true;
		else if (getWest1(maze, size, robot, goal)){
			storage.push(robot.west()); poCount++;
			empty_space = true;
		}
		if (getSouth1(maze, size, robot, goal) == 2)
			found = true;
		else if (getSouth1(maze, size, robot, goal)){
			storage.push(robot.south()); poCount++;
			empty_space = true;
		}
		if (getNorth1(maze, size, robot, goal) == 2)
			found = true;
		else if (getNorth1(maze, size, robot, goal)){
			storage.push(robot.north()); poCount++;
			empty_space = true;
		}
		if (getEast1(maze, size, robot, goal) == 2)
			found = true;
		else if (getEast1(maze, size, robot, goal)){
			storage.push(robot.east()); poCount++;
			empty_space = true;
		}
	}
	else if (robot.getx() > goal.getx() && robot.gety() > goal.gety()){
		if (getEast1(maze, size, robot, goal) == 2)
			found = true;
		else if (getEast1(maze, size, robot, goal)){
			storage.push(robot.east()); poCount++;
			empty_space = true;
		}
		if (getSouth1(maze, size, robot, goal) == 2)
			found = true;
		else if (getSouth1(maze, size, robot, goal)){
			storage.push(robot.south()); poCount++;
			empty_space = true;
		}
		if (getNorth1(maze, size, robot, goal) == 2)
			found = true;
		else if (getNorth1(maze, size, robot, goal)){
			storage.push(robot.north()); poCount++;
			empty_space = true;
		}
		if (getWest1(maze, size, robot, goal) == 2)
			found = true;
		else if (getWest1(maze, size, robot, goal)){
			storage.push(robot.west()); poCount++;
			empty_space = true;
		}
	}
	else
	{
		if (getWest1(maze, size, robot, goal) == 2)
			found = true;
		else if (getWest1(maze, size, robot, goal)){
			storage.push(robot.west()); poCount++;
			empty_space = true;
		}

		if (getNorth1(maze, size, robot, goal) == 2)
			found = true;
		else if (getNorth1(maze, size, robot, goal)){
			storage.push(robot.north()); poCount++;
			empty_space = true;
		}

		if (getSouth1(maze, size, robot, goal) == 2)
			found = true;
		else if (getSouth1(maze, size, robot, goal)){
			storage.push(robot.south()); poCount++;
			empty_space = true;
		}

		if (getEast1(maze, size, robot, goal) == 2)
			found = true;
		else if (getEast1(maze, size, robot, goal)){
			storage.push(robot.east()); poCount++;
			empty_space = true;
		}
	}
	/////here scaning the empty spaces near the position that I reach,then insert them in my stack.
	//// in that point i will throw the checked position to another stack so the loop will access the next position and 
	///the loop will stop if it find 'G' or if the stack is empty 
	while (!found&&!storage.empty()){
		if (empty_space){
			empty_space = false;
			solution.push(storage.top()); solCount++;
			storage.pop();
			maze[solution.top().getx()][solution.top().gety()] = '*';


			if (solution.top().getx() > goal.getx() && solution.top().gety() < goal.gety()){

				if (getEast1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getEast1(maze, size, solution.top(), goal)){
					storage.push(solution.top().east()); poCount++;
					empty_space = true;
				}
				if (getNorth1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getNorth1(maze, size, solution.top(), goal)){
					storage.push(solution.top().north()); poCount++;
					empty_space = true;
				}
				if (getSouth1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getSouth1(maze, size, solution.top(), goal)){
					storage.push(solution.top().south()); poCount++;
					empty_space = true;
				}
				if (getWest1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getWest1(maze, size, solution.top(), goal)){
					storage.push(solution.top().west()); poCount++;
					empty_space = true;
				}
			}
			else if (solution.top().getx() < goal.getx() && solution.top().gety() > goal.gety()){
				if (getWest1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getWest1(maze, size, solution.top(), goal)){
					storage.push(solution.top().west()); poCount++;
					empty_space = true;
				}
				if (getSouth1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getSouth1(maze, size, solution.top(), goal)){
					storage.push(solution.top().south()); poCount++;
					empty_space = true;
				}
				if (getNorth1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getNorth1(maze, size, solution.top(), goal)){
					storage.push(solution.top().north()); poCount++;
					empty_space = true;
				}
				if (getEast1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getEast1(maze, size, solution.top(), goal)){
					storage.push(solution.top().east()); poCount++;
					empty_space = true;
				}
			}
			else if (solution.top().getx() > goal.getx() && solution.top().gety() > goal.gety()){
				if (getEast1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getEast1(maze, size, solution.top(), goal)){
					storage.push(solution.top().east()); poCount++;
					empty_space = true;
				}
				if (getSouth1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getSouth1(maze, size, solution.top(), goal)){
					storage.push(solution.top().south()); poCount++;
					empty_space = true;
				}
				if (getNorth1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getNorth1(maze, size, solution.top(), goal)){
					storage.push(solution.top().north()); poCount++;
					empty_space = true;
				}
				if (getWest1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getWest1(maze, size, solution.top(), goal)){
					storage.push(solution.top().west()); poCount++;
					empty_space = true;
				}
			}
			else
			{
				if (getWest1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getWest1(maze, size, solution.top(), goal)){
					storage.push(solution.top().west()); poCount++;
					empty_space = true;
				}

				if (getNorth1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getNorth1(maze, size, solution.top(), goal)){
					storage.push(solution.top().north()); poCount++;
					empty_space = true;
				}

				if (getSouth1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getSouth1(maze, size, solution.top(), goal)){
					storage.push(solution.top().south()); poCount++;
					empty_space = true;
				}

				if (getEast1(maze, size, solution.top(), goal) == 2)
					found = true;
				else if (getEast1(maze, size, solution.top(), goal)){
					storage.push(solution.top().east()); poCount++;
					empty_space = true;
				}
			}
		}
		else{///erase the extra stars that we do not need them 
			while (!(storage.top().isEquale(solution.top().east()) || storage.top().isEquale(solution.top().west()) || storage.top().isEquale(solution.top().north()) || storage.top().isEquale(solution.top().south()))){
				maze[solution.top().getx()][solution.top().gety()] = ' ';
				solution.pop();
			}
			empty_space = true;
		}
	}
	if (found)
		cout << "Goal found! " << solCount << " positions explored, unexplored list contains " << poCount-solCount << " positions." << endl;
	else
		cout << "Goal not found! " << solCount << " positions explored." << endl;
	return found;

}