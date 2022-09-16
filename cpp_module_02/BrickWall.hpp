#ifndef BRICKWALL_H
# define BRICKWALL_H

# include "iostream"
# include "ATarget.hpp"

class BrickWall:public ATarget{
public:
	BrickWall();
	virtual ~BrickWall();

	virtual BrickWall* clone() const;
};


#endif
