#include "Fwoosh.hpp"

Fwoosh::Fwoosh():ASpell("Fwoosh", "fwooshed"){
}

Fwoosh::~Fwoosh(){}

Fwoosh*	Fwoosh::clone() const{//du coup const ici aussi
	return (new Fwoosh());
}
