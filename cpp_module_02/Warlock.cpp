#include "Warlock.hpp"

Warlock::Warlock(){
	this->spellbook = new SpellBook();
}

Warlock::Warlock(const Warlock & src){*this = src;}

Warlock::Warlock(std::string const & N, std::string const & T){
	this->name = N;
	this->title = T;
	this->spellbook = new SpellBook();
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(){
	if (this->spellbook != NULL){
		delete this->spellbook;
		this->spellbook = NULL;
	}
	std::cout << this->name << ": My job here is done!\n";
}

Warlock &	Warlock::operator=(Warlock const & src){
	this->name = src.name;
	this->title = src.title;
	if (this->spellbook != NULL){
		delete this->spellbook;
		this->spellbook = NULL;
	}
	this->spellbook = new SpellBook();
	for (std::map<std::string, ASpell*>::const_iterator it = src.spellbook->spell_map.begin(); it !=src.spellbook->spell_map.end(); ++it)
		this->spellbook->learnSpell(it->second);
	return (*this);
}

std::string const &	Warlock::getName() const{
	return (this->name);
}

std::string const &	Warlock::getTitle() const {
	return (this->title);
}

void	Warlock::setTitle(std::string const & T){
	this->title = T;
}

void	Warlock::introduce() const{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void	Warlock::learnSpell(ASpell* as){
	this->spellbook->learnSpell(as);
}

void	Warlock::forgetSpell(std::string sn){
	this->spellbook->forgetSpell(sn);
}

void	Warlock::launchSpell(std::string sn, ATarget const & t){
	if (sn.empty())//une condition de if a la fois pour eviter des erreurs bete
		return ;
	if (this->spellbook->spell_map.find(sn) != this->spellbook->spell_map.end()){//attention ici c'est != 
		ASpell*	ns = this->spellbook->createSpell(sn);
		ns->launch(t);
		if (ns != NULL)
			delete (ns);
	}
}
