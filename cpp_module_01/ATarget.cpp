#include "ATarget.hpp"

ATarget::ATarget(){}

ATarget::ATarget(ATarget const & src){*this = src;}

ATarget::ATarget(std::string const & T){
	this->_type = T;
}

ATarget::~ATarget(){}

ATarget &	ATarget::operator=(ATarget const &src){
	this->_type = src._type;
	return (*this);
}

std::string	const & ATarget::getType() const{
	return (this->_type);
}

void	ATarget::getHitBySpell(ASpell const & spell) const {
	std::cout << this->_type << " has been " << spell.getEffects() << std::endl;
}

