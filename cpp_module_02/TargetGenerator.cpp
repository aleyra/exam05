#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){
	for (std::map<std::string, ATarget*>::iterator it = this->target_map.begin(); it != this->target_map.end(); ++it){
		delete it->second;
	}
	this->target_map.clear();
}

void	TargetGenerator::learnTarget(ASpell* s){
	std::map<std::string, ASpell*>::iterator it = this->spell_map.find(s->getName());
	if (it != this->spell_map.end())
		delete it->second;
	this->spell_map.at(s->getName()) = s->clone();
}

void	TargetGenerator::forgetSpell(std::string const & sn){
	std::map<std::string, ASpell*>::iterator it = this->spell_map.find(sn);
	if (it != this->spell_map.end())
		delete it->second;
	this->spell_map.erase(sn);
}

ASpell*	TargetGenerator::createSpell(std::string const & sn){
	std::map<std::string, ASpell*>::iterator it = this->spell_map.find(sn);
	if (it != this->spell_map.end())
		return it->second->clone();
	return NULL;
}
