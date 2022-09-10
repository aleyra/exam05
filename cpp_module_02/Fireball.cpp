#include "Fireball.hpp"

Fireball::Fireball():ASpell("Fireball", "burn to a crisp"){
}

Fireball::~Fireball(){}

Fireball*	Fireball::clone(){
	return (new Fireball());
}
