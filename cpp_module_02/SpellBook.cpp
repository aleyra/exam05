#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
	for (std::map<std::string, ASpell*>::iterator it = spell_map.begin(); it != spell_map.end(); ++it){
		delete it->second;
	}
	spell_map.clear();
}

SpellBook::SpellBook(SpellBook const & src){
	*this = src;
}

SpellBook &	SpellBook::operator=(SpellBook const & src){
	for (std::map<std::string, ASpell*>::iterator it = spell_map.begin(); it != spell_map.end(); ++it){
		delete it->second;
	}
	spell_map.clear();
	for (std::map<std::string, ASpell*>::const_iterator it = src.spell_map.begin(); it != src.spell_map.end(); ++it){
		spell_map[it->first] = it->second->clone();
	}
	return (*this);
}

void SpellBook::learnSpell(ASpell* as){
	if (as == NULL)//une condition de if a la fois pour eviter des erreurs bete
		return ;
	if (spell_map.find(as->getName()) == spell_map.end()){//attention, ici c'est ==
		spell_map[as->getName()] = as->clone();
	}

}

void SpellBook::forgetSpell(std::string const & sn){
	if (!sn.empty() && spell_map.find(sn) != spell_map.end()){
		delete spell_map[sn];
		spell_map.erase(sn);
	}
}

ASpell* SpellBook::createSpell(std::string const & sn){
	if (!sn.empty() && spell_map.find(sn) != spell_map.end()){
		return (spell_map[sn]->clone());
	}
	return NULL;
}