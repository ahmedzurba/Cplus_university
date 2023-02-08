//26/12
#include"Position.h"



Position::Position(){

}
Position::Position(const int &posx, const int &posy){
	x = posx;
	y = posy;
}
void Position::setx(const int &posx){
	x = posx;
}
void Position::sety(const int& posy){
	y = posy;
}
int Position::getx()const{
	return x;
}
int Position::gety()const{
	return y;
}
Position Position::east()const{
	return  Position(x , y+1);
}
Position Position::west()const{
	return  Position(x , y-1);
}
Position Position::north()const{
	return  Position(x-1 , y);
}
Position Position::south()const{
	return  Position(x+1, y);
}
bool Position::isEquale(const Position& pos)const{
	if (x == pos.getx() && y == pos.gety()){
		return true;
	}
	else
		return false;
}
