#ifndef POLYMORPH_H
# define POLYMORPH_H

# include "iostream"
# include "ASpell.hpp"

class Polymorph:public ASpell{
public:
	Polymorph();
	virtual ~Polymorph();

	virtual Polymorph* clone() const;
};


#endif
