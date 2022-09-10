#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
	for (std::map<std::string, ASpell*>::iterator it = this->spell_map.begin(); it != this->spell_map.end(); ++it){
		delete it->second;
	}
	this->spell_map.clear();
}

SpellBook::SpellBook(SpellBook const & src){
	*this = src;
}

SpellBook &	SpellBook::operator=(SpellBook const & src){
	for (std::map<std::string, ASpell*>::iterator it = this->spell_map.begin(); it != this->spell_map.end(); ++it){
		delete it->second;
	}
	this->spell_map.clear();
	for (std::map<std::string, ASpell*>::const_iterator it = src.spell_map.begin(); it != src.spell_map.end(); ++it){
		this->spell_map[it->first] = it->second->clone();
	}
	return (*this);
}

void SpellBook::learnSpell(ASpell* as){
	if (as != NULL && this->spell_map.find(as->getName()) != this->spell_map.end())
		this->spell_map[as->getName()] = as->clone();
}

void SpellBook::forgetSpell(std::string const & sn){
	if (!sn.empty() && this->spell_map.find(sn) != this->spell_map.end()){
		delete this->spell_map[sn];
		this->spell_map.erase(sn);
	}
}

ASpell* SpellBook::createSpell(std::string const & sn){
	if (!sn.empty() && this->spell_map.find(sn) != this->spell_map.end()){
		return (this->spell_map[sn]->clone());
	}
	return NULL;
}