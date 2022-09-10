#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
	for (std::map<std::string, ASpell*>::iterator it = this->spell_map.begin(); it != this->spell_map.end(); ++it){
		delete it->second;
	}
	this->spell_map.clear();
}

void	SpellBook::learnSpell(ASpell* s){
	std::map<std::string, ASpell*>::iterator it = this->spell_map.find(s->getName());
	if (it != this->spell_map.end())
		delete it->second;
	this->spell_map.at(s->getName()) = s->clone();
}

void	SpellBook::forgetSpell(std::string const & sn){
	std::map<std::string, ASpell*>::iterator it = this->spell_map.find(sn);
	if (it != this->spell_map.end())
		delete it->second;
	this->spell_map.erase(sn);
}

ASpell*	SpellBook::createSpell(std::string const & sn){
	std::map<std::string, ASpell*>::iterator it = this->spell_map.find(sn);
	if (it != this->spell_map.end())
		return it->second->clone();
	return NULL;
}