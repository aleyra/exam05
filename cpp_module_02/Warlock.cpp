#include "Warlock.hpp"

Warlock::Warlock(){}

Warlock::Warlock(const Warlock & src){*this = src;}

Warlock::Warlock(std::string const & N, std::string const & T){
	this->_name = N;
	this->_title = T;
	std::cout << this->_name << ": This looks like another boring day\n";
}

Warlock::~Warlock(){
	for (std::map<std::string, ASpell*>::iterator it = this->_spell_map.begin(); it != this->_spell_map.end(); ++it)
		delete (it->second);
	this->_spell_map.clear();
	std::cout << this->_name << ": My job here is done!\n";
}

Warlock &	Warlock::operator=(Warlock const & src){
	this->_name = src._name;
	this->_title = src._title;
	for (std::map<std::string, ASpell*>::iterator it = this->_spell_map.begin(); it != this->_spell_map.end(); ++it)
		delete (it->second);
	this->_spell_map.clear();
	for (std::map<std::string, ASpell*>::const_iterator it = src._spell_map.begin(); it !=src._spell_map.end(); ++it)
		this->_spell_map[it->first] = it->second->clone();
	return (*this);
}

std::string const &	Warlock::getName() const{
	return (this->_name);
}

std::string const &	Warlock::getTitle() const {
	return (this->_title);
}

void	Warlock::setTitle(std::string const & T){
	this->_title = T;
}

void	Warlock::introduce() const{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n";
}

void	Warlock::learnSpell(ASpell* as){
	if (as != NULL)
		this->_spell_map[as->getName()] = as->clone();
}

void	Warlock::forgetSpell(std::string sn){
	if (this->_spell_map.find(sn) != this->_spell_map.end()){
		delete this->_spell_map[sn];
		this->_spell_map.erase(sn);
	}
}

void	Warlock::launchSpell(std::string sn, ATarget const & t){
	if (this->_spell_map.find(sn) != this->_spell_map.end()){
		this->_spell_map[sn]->launch(t);
	}
}
