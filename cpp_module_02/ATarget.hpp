#ifndef ATARGET_H
# define ATARGET_H

# include "iostream"
# include "ASpell.hpp"


class ASpell;

class ATarget{
private:
	std::string _type;

public:
	ATarget();
	ATarget(ATarget const & src);
	ATarget(std::string const & T);
	virtual ~ATarget();

	ATarget &	operator=(ATarget const & src);

	std::string	const & getType()const;

	virtual ATarget* clone() = 0;

	void	getHitBySpell(ASpell const & spell) const;
};


#endif
