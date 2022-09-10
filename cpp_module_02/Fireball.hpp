#ifndef FIREBALL_H
# define FIREBALL_H

# include "iostream"
# include "ASpell.hpp"

class Fireball:public ASpell{
public:
	Fireball();
	virtual ~Fireball();

	virtual Fireball* clone() const;
};


#endif
