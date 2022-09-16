#include "ASpell.hpp"

ASpell::ASpell(){}

ASpell::ASpell(ASpell const & src){*this = src;}

ASpell::ASpell(std::string const & N, std::string const & E){
	name = N;
	effects = E;
}

ASpell::~ASpell(){}

ASpell &	ASpell::operator=(ASpell const &src){
	name = src.name;
	effects = src.effects;
	return (*this);
}

std::string	const & ASpell::getName() const{
	return (name);
}

std::string	const & ASpell::getEffects() const{
	return (effects);
}

void	ASpell::launch(ATarget const & target) const{//penser au const ici
	target.getHitBySpell(*this);
}