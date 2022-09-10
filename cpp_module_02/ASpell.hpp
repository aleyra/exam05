#ifndef ASPELL_H
# define ASPELL_H

# include "iostream"
# include "ATarget.hpp"

class ATarget;

class ASpell{
private:
	std::string _name;
	std::string _effects;

public:
	ASpell();
	ASpell(ASpell const & src);
	ASpell(std::string const & N, std::string const & E);
	virtual ~ASpell();

	ASpell	&operator=(ASpell const & src);

	std::string	const & getName()const;
	std::string	const & getEffects()const;

	virtual ASpell* clone() = 0;

	void	launch(ATarget const & target);
};


#endif