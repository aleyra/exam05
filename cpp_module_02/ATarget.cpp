#include "ATarget.hpp"

ATarget::ATarget(){}

ATarget::ATarget(ATarget const & src){*this = src;}

ATarget::ATarget(std::string const & T){
	type = T;
}

ATarget::~ATarget(){}

ATarget &	ATarget::operator=(ATarget const &src){
	type = src.type;
	return (*this);
}

std::string	const & ATarget::getType() const{
	return (type);
}

void	ATarget::getHitBySpell(ASpell const & spell) const {
	std::cout << type << " has been " << spell.getEffects() << std::endl;
}

