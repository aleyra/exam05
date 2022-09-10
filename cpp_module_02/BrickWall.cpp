#include "BrickWall.hpp"

BrickWall::BrickWall():ATarget("Inconspicuous Red-brick Wall"){
}

BrickWall::~BrickWall(){}

BrickWall*	BrickWall::clone() const{//du coup const ici aussi
	return (new BrickWall());
}
