#include "ASpell.hpp"

ASpell::ASpell(){}

ASpell::ASpell(ASpell const & src){*this = src;}

ASpell::ASpell(std::string const & N, std::string const & E){
	this->_name = N;
	this->_effects = E;
}

ASpell::~ASpell(){}

ASpell &	ASpell::operator=(ASpell const &src){
	this->_name = src._name;
	this->_effects = src._effects;
	return (*this);
}

std::string	const & ASpell::getName() const{
	return (this->_name);
}

std::string	const & ASpell::getEffects() const{
	return (this->_effects);
}

void	ASpell::launch(ATarget const & target) const{//penser au const ici
	target.getHitBySpell(*this);
}