#include "Warlock.hpp"

Warlock::Warlock(){}

Warlock::Warlock(const Warlock & src){*this = src;}

Warlock::Warlock(std::string const & N, std::string const & T){
	name = N;
	title = T;
	std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(){
	for (std::map<std::string, ASpell*>::iterator it = spell_map.begin(); it != spell_map.end(); ++it)
		delete (it->second);
	spell_map.clear();
	std::cout << name << ": My job here is done!\n";
}

Warlock &	Warlock::operator=(Warlock const & src){
	name = src.name;
	title = src.title;
	for (std::map<std::string, ASpell*>::iterator it = spell_map.begin(); it != spell_map.end(); ++it)
		delete (it->second);
	spell_map.clear();
	for (std::map<std::string, ASpell*>::const_iterator it = src.spell_map.begin(); it != src.spell_map.end(); ++it)
		spell_map[it->first] = it->second->clone();
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
	if (as == NULL)//verification de as != NULL SUPER Importante
		return ;
	if (spell_map.find(as->getName()) == spell_map.end() ){//ici c'est ==
		spell_map[as->getName()] = as->clone();
	}
}

void	Warlock::forgetSpell(std::string sn){
	if (!sn.empty() && spell_map.find(sn) != spell_map.end()){//penser a verif sn non vide
		delete spell_map[sn];
		spell_map.erase(sn);
	}
}

void	Warlock::launchSpell(std::string sn, ATarget const & t){
	if (sn.empty())//penser a verif sn non vide
		return ;
	if (spell_map.find(sn) != spell_map.end()){
		spell_map[sn]->launch(t);
	}
}
