#include "Warlock.hpp"

Warlock::Warlock(){
	spellbook = new SpellBook();
}

Warlock::Warlock(const Warlock & src){*this = src;}

Warlock::Warlock(std::string const & N, std::string const & T){
	name = N;
	title = T;
	spellbook = new SpellBook();
	std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(){
	if (spellbook != NULL){
		delete spellbook;
		spellbook = NULL;
	}
	std::cout << name << ": My job here is done!\n";
}

Warlock &	Warlock::operator=(Warlock const & src){
	name = src.name;
	title = src.title;
	if (spellbook != NULL){
		delete spellbook;
		spellbook = NULL;
	}
	spellbook = new SpellBook();
	for (std::map<std::string, ASpell*>::const_iterator it = src.spellbook->spell_map.begin(); it !=src.spellbook->spell_map.end(); ++it)
		spellbook->learnSpell(it->second);
	return (*this);
}

std::string const &	Warlock::getName() const{
	return (name);
}

std::string const &	Warlock::getTitle() const {
	return (title);
}

void	Warlock::setTitle(std::string const & T){
	title = T;
}

void	Warlock::introduce() const{
	std::cout << name << ": I am " << name << ", " << title << "!\n";
}

void	Warlock::learnSpell(ASpell* as){
	spellbook->learnSpell(as);
}

void	Warlock::forgetSpell(std::string sn){
	spellbook->forgetSpell(sn);
}

void	Warlock::launchSpell(std::string sn, ATarget const & t){
	if (sn.empty())//une condition de if a la fois pour eviter des erreurs bete
		return ;
	if (spellbook->spell_map.find(sn) != spellbook->spell_map.end()){//attention ici c'est != 
		ASpell*	ns = spellbook->createSpell(sn);
		ns->launch(t);
		if (ns != NULL)
			delete (ns);
	}
}
