#ifndef FWOOSH_H
# define FWOOSH_H

# include "iostream"
# include "ASpell.hpp"

class Fwoosh:public ASpell{
public:
	Fwoosh();
	virtual ~Fwoosh();

	virtual Fwoosh* clone() const;//du coup const ici aussi
};


#endif
