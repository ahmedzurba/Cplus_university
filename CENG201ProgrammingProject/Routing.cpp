//Ahmed Al Zurba          Ahmed Douhan
//11.1
//the solving methodes using my stack and queue impletation
#include"Routing.h"
#include<iostream>



int getEast(char ** maze, const int& size, const Position& cur, const Position& goal){
	if (cur.east().getx() < size&&cur.east().getx() >= 0 && maze[cur.east().getx()][cur.east().gety()] != 'X'&&cur.east().gety() < size&&cur.east().gety() >= 0 && maze[cur.east().getx()][cur.east().gety()] != '*'&& maze[cur.east().getx()][cur.east().gety()] != 'R')
		if (maze[cur.east().getx()][cur.east().gety()] == 'G')
			return 2;
		else
		return 1;
	else
		return 0;
}
int getWest(char ** maze, const int& size, const Position& cur, const Position& goal){
	if (cur.west().getx() < size&&cur.west().getx() >= 0 && maze[cur.west().getx()][cur.west().gety()] != 'X'&&cur.west().gety() < size&&cur.west().gety() >= 0 && maze[cur.west().getx()][cur.west().gety()] != '*'&& maze[cur.west().getx()][cur.west().gety()] != 'R')
		if (maze[cur.west().getx()][cur.west().gety()] == 'G')
			return 2;
		else
		return 1;
	else
		return 0;
}
int getNorth(char ** maze, const int& size, const Position& cur, const Position& goal){
	if (cur.north().getx() < size&&cur.north().getx() >= 0 && maze[cur.north().getx()][cur.north().gety()] != 'X'&&cur.north().gety() < size&&cur.north().gety() >= 0 && maze[cur.north().getx()][cur.north().gety()] != '*'&& maze[cur.north().getx()][cur.north().gety()] != 'R')
		if (maze[cur.north().getx()][cur.north().gety()] == 'G')
			return 2;
		else
		return 1;
	else
		return 0;
}
int getSouth(char ** maze, const int& size, const Position& cur, const Position& goal){
	if (cur.south().getx() < size&&cur.south().getx() >= 0 && maze[cur.south().getx()][cur.south().gety()] != 'X'&&cur.south().gety() < size&&cur.south().gety() >= 0 && maze[cur.south().getx()][cur.south().gety()] != '*'&& maze[cur.south().getx()][cur.south().gety()] != 'R')
		if (maze[cur.south().getx()][cur.south().gety()] == 'G')
			return 2;
		else
		return 1;
	else
		return 0;
}





bool Routing::Stack_Solving(char ** maze, const int& size, const Position& robot, const Position& goal){
	Stack<Position> solution;
	Stack<Position> storage;
	int solCount = 0;
	int poCount = 0;
	bool found=false;
	bool empty_space = false;

	/////At First scaning the empty space near the robot and insert them in my stack
	if (getWest(maze, size, robot, goal)==2)
		found =true;
	else if (getWest(maze, size, robot, goal)){
		storage.push(robot.west()); poCount++;
	empty_space = true;
	}
	
	if (getNorth(maze, size, robot, goal)==2)
		found = true;
	else if (getNorth(maze, size, robot, goal)){
		storage.push(robot.north()); poCount++;
	empty_space = true;
	}

	if (getSouth(maze, size, robot, goal) == 2)
		found = true;
	else if (getSouth(maze, size, robot, goal)){
		storage.push(robot.south()); poCount++;
		empty_space = true;
	}

	if (getEast(maze, size, robot, goal)==2)
		found = true;
	else if (getEast(maze, size, robot, goal)){
		storage.push(robot.east()); poCount++;
		empty_space = true;
	}

	/////here scaning the empty spaces near the position that I reach,then insert them in my stack.
	//// in that point i will throw the checked position to another stack so the loop will access the next position and 
	///the loop will stop if it find 'G' or if the stack is empty 
		while (!found&&!storage.isEmpty()){
			if (empty_space){
				empty_space = false;
				solution.push(storage.peek()); solCount++;
				storage.pop();
				maze[solution.peek().getx()][solution.peek().gety()] = '*';


				if (getWest(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getWest(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().west()); poCount++;
					empty_space = true;
				}


				if (getNorth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getNorth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().north()); poCount++;
					empty_space = true;
				}

				if (getSouth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getSouth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().south()); poCount++;
					empty_space = true;
				}

				if (getEast(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getEast(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().east()); poCount++;
					empty_space = true;
				}
			}
			else{///erase the extra stars that we do not need them 
			while (!(storage.peek().isEquale(solution.peek().east()) || storage.peek().isEquale(solution.peek().west()) || storage.peek().isEquale(solution.peek().north()) || storage.peek().isEquale(solution.peek().south()))){
				maze[solution.peek().getx()][solution.peek().gety()] = ' ';
				solution.pop();
				}
			empty_space = true;
			}
	}
		if (found)
			cout << "Goal found! "<<solCount<<" positions explored, unexplored list contains" << poCount-solCount<<" positions."<<endl;
		else
			cout << "Goal not found! " << solCount << " positions explored."<< endl;
	return found;
}
bool Routing::Queue_Solving(char ** maze, const int& size, const Position& robot, const Position& goal){
	Queue<Position> storage;
	Position temp;
	int solCount = 0;
	int poCount = 0;
	bool found = false;
	bool empty_space = false;

	/////At First scaning the empty space near the robot and insert them in my queue
	if (getWest(maze, size, robot, goal) == 2)
		found = true;
	else if (getWest(maze, size, robot, goal)){
		storage.enqueue(robot.west()); poCount++;
		maze[robot.west().getx()][robot.west().gety()] = '*';
		empty_space = true;
	}

	if (getNorth(maze, size, robot, goal) == 2)
		found = true;
	else if (getNorth(maze, size, robot, goal)){
		storage.enqueue(robot.north()); poCount++;
		maze[robot.north().getx()][robot.north().gety()] = '*';
		empty_space = true;
	}

	if (getSouth(maze, size, robot, goal) == 2)
		found = true;
	else if (getSouth(maze, size, robot, goal)){
		storage.enqueue(robot.south()); poCount++;
		maze[robot.south().getx()][robot.south().gety()] = '*';
		empty_space = true;
	}

	if (getEast(maze, size, robot, goal) == 2)
		found = true;
	else if (getEast(maze, size, robot, goal)){
		storage.enqueue(robot.east()); poCount++;
		maze[robot.east().getx()][robot.east().gety()] = '*';
		empty_space = true;
	}

	/////here scaning the empty spaces near the position that I reach, then insert them in my queue
	//// the the next position at the end the loop will stop if it find 'G' or if the queue is empty 
	while (!found&&!storage.isEmpty()){
		
			empty_space = false;
			temp=storage.peekFront();
			storage.dequeue(); solCount++;
			maze[temp.getx()][temp.gety()] = '*';


			if (getWest(maze, size, temp, goal) == 2)
				found = true;
			else if (getWest(maze, size, temp, goal)){
				storage.enqueue(temp.west()); poCount++;
				maze[temp.west().getx()][temp.west().gety()] = '*';
				empty_space = true;
			}


			if (getNorth(maze, size,temp, goal) == 2)
				found = true;
			else if (getNorth(maze, size, temp, goal)){
				storage.enqueue(temp.north()); poCount++;
				maze[temp.north().getx()][temp.north().gety()] = '*';
				empty_space = true;
			}

			if (getSouth(maze, size, temp, goal) == 2)
				found = true;
			else if (getSouth(maze, size, temp, goal)){
				storage.enqueue(temp.south()); poCount++;
				maze[temp.south().getx()][temp.south().gety()] = '*';
				empty_space = true;
			}

			if (getEast(maze, size, temp, goal) == 2)
				found = true;
			else if (getEast(maze, size, temp, goal)){
				storage.enqueue(temp.east()); poCount++;
				maze[temp.east().getx()][temp.east().gety()] = '*';
				empty_space = true;
			}
		}
	if (found)
		cout << "Goal found! " << solCount << " positions explored, unexplored list contains" << poCount-solCount << " positions." << endl;
	else
		cout << "Goal not found! " << solCount << " positions explored." << endl;
	return found;
	
}
bool Routing::Opt_Solving(char ** maze, const int& size, const Position& robot, const Position& goal){
	Stack<Position> solution;
	Stack<Position> storage;
	int solCount = 0;
	int poCount = 0;
	bool found = false;
	bool empty_space = false;


	
		
			
				
	/////At First scaning the empty space near the robot and insert them in my stack
	if (robot.getx() > goal.getx() && robot.gety() < goal.gety()){
		
		if (getEast(maze, size, robot, goal) == 2)
			found = true;
		else if (getEast(maze, size, robot, goal)){
			storage.push(robot.east()); poCount++;
			empty_space = true;
		}
		if (getNorth(maze, size, robot, goal) == 2)
			found = true;
		else if (getNorth(maze, size, robot, goal)){
			storage.push(robot.north()); poCount++;
			empty_space = true;
		}
		if (getSouth(maze, size, robot, goal) == 2)
			found = true;
		else if (getSouth(maze, size, robot, goal)){
			storage.push(robot.south()); poCount++;
			empty_space = true;
		}
		if (getWest(maze, size, robot, goal) == 2)
			found = true;
		else if (getWest(maze, size, robot, goal)){
			storage.push(robot.west()); poCount++;
			empty_space = true;
		}
	}
	else if (robot.getx() < goal.getx() && robot.gety() > goal.gety()){
		if (getWest(maze, size, robot, goal) == 2)
			found = true;
		else if (getWest(maze, size, robot, goal)){
			storage.push(robot.west()); poCount++;
			empty_space = true;
		}
		if (getSouth(maze, size, robot, goal) == 2)
			found = true;
		else if (getSouth(maze, size, robot, goal)){
			storage.push(robot.south()); poCount++;
			empty_space = true;
		}
		if (getNorth(maze, size, robot, goal) == 2)
			found = true;
		else if (getNorth(maze, size, robot, goal)){
			storage.push(robot.north()); poCount++;
			empty_space = true;
		}
		if (getEast(maze, size, robot, goal) == 2)
			found = true;
		else if (getEast(maze, size, robot, goal)){
			storage.push(robot.east()); poCount++;
			empty_space = true;
		}
	}
	else if (robot.getx() > goal.getx() && robot.gety() > goal.gety()){
		if (getEast(maze, size, robot, goal) == 2)
			found = true;
		else if (getEast(maze, size, robot, goal)){
			storage.push(robot.east()); poCount++;
			empty_space = true;
		}
		if (getSouth(maze, size, robot, goal) == 2)
			found = true;
		else if (getSouth(maze, size, robot, goal)){
			storage.push(robot.south()); poCount++;
			empty_space = true;
		}
		if (getNorth(maze, size, robot, goal) == 2)
			found = true;
		else if (getNorth(maze, size, robot, goal)){
			storage.push(robot.north()); poCount++;
			empty_space = true;
		}
		if (getWest(maze, size, robot, goal) == 2)
			found = true;
		else if (getWest(maze, size, robot, goal)){
			storage.push(robot.west()); poCount++;
			empty_space = true;
		}
	}
	else
	{
		if (getWest(maze, size, robot, goal) == 2)
			found = true;
		else if (getWest(maze, size, robot, goal)){
			storage.push(robot.west()); poCount++;
			empty_space = true;
		}

		if (getNorth(maze, size, robot, goal) == 2)
			found = true;
		else if (getNorth(maze, size, robot, goal)){
			storage.push(robot.north()); poCount++;
			empty_space = true;
		}

		if (getSouth(maze, size, robot, goal) == 2)
			found = true;
		else if (getSouth(maze, size, robot, goal)){
			storage.push(robot.south()); poCount++;
			empty_space = true;
		}

		if (getEast(maze, size, robot, goal) == 2)
			found = true;
		else if (getEast(maze, size, robot, goal)){
			storage.push(robot.east()); poCount++;
			empty_space = true;
		}
	}
	/////here scaning the empty spaces near the position that I reach,then insert them in my stack.
	//// in that point i will throw the checked position to another stack so the loop will access the next position and 
	///the loop will stop if it find 'G' or if the stack is empty 
	while (!found&&!storage.isEmpty()){
		if (empty_space){
			empty_space = false;
			solution.push(storage.peek()); solCount++;
			storage.pop();
			maze[solution.peek().getx()][solution.peek().gety()] = '*';


			if (solution.peek().getx() > goal.getx() && solution.peek().gety() < goal.gety()){

				if (getEast(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getEast(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().east()); poCount++;
					empty_space = true;
				}
				if (getNorth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getNorth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().north()); poCount++;
					empty_space = true;
				}
				if (getSouth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getSouth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().south()); poCount++;
					empty_space = true;
				}
				if (getWest(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getWest(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().west()); poCount++;
					empty_space = true;
				}
			}
			else if (solution.peek().getx() < goal.getx() && solution.peek().gety() > goal.gety()){
				if (getWest(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getWest(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().west()); poCount++;
					empty_space = true;
				}
				if (getSouth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getSouth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().south()); poCount++;
					empty_space = true;
				}
				if (getNorth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getNorth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().north()); poCount++;
					empty_space = true;
				}
				if (getEast(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getEast(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().east()); poCount++;
					empty_space = true;
				}
			}
			else if (solution.peek().getx() > goal.getx() && solution.peek().gety() > goal.gety()){
				if (getEast(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getEast(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().east()); poCount++;
					empty_space = true;
				}
				if (getSouth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getSouth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().south()); poCount++;
					empty_space = true;
				}
				if (getNorth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getNorth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().north()); poCount++;
					empty_space = true;
				}
				if (getWest(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getWest(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().west()); poCount++;
					empty_space = true;
				}
			}
			else
			{
				if (getWest(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getWest(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().west()); poCount++;
					empty_space = true;
				}

				if (getNorth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getNorth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().north()); poCount++;
					empty_space = true;
				}

				if (getSouth(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getSouth(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().south()); poCount++;
					empty_space = true;
				}

				if (getEast(maze, size, solution.peek(), goal) == 2)
					found = true;
				else if (getEast(maze, size, solution.peek(), goal)){
					storage.push(solution.peek().east()); poCount++;
					empty_space = true;
				}
			}
		}
		else{///erase the extra stars that we do not need them 
			while (!(storage.peek().isEquale(solution.peek().east()) || storage.peek().isEquale(solution.peek().west()) || storage.peek().isEquale(solution.peek().north()) || storage.peek().isEquale(solution.peek().south()))){
				maze[solution.peek().getx()][solution.peek().gety()] = ' ';
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