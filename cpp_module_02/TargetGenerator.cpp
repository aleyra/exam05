#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){
	for (std::map<std::string, ATarget*>::iterator it = target_map.begin(); it != target_map.end(); ++it){
		delete it->second;
	}
	target_map.clear();
}

TargetGenerator::TargetGenerator(const TargetGenerator & src){
	*this = src;
}

TargetGenerator &	TargetGenerator::operator=(const TargetGenerator & src){
	if (!target_map.empty()){
		for (std::map<std::string, ATarget*>::iterator it = target_map.begin(); it != target_map.end(); ++it){
			delete it->second;
		}
		target_map.clear();
	}
	for (std::map<std::string, ATarget*>::const_iterator it = src.target_map.begin(); it != src.target_map.end(); ++it){
		learnTargetType(it->second);
	}
	return (*this);
}

void	TargetGenerator::learnTargetType(ATarget* at){
	if (at == NULL)
		return ;
	if (target_map.find(at->getType()) == target_map.end())
		target_map[at->getType()] = at->clone();
}

void	TargetGenerator::forgetTargetType(std::string const & tn){
	if (tn.empty())
		return ;
	std::map<std::string, ATarget*>::iterator it = target_map.find(tn);
	if (it != target_map.end()){
		delete target_map[tn];
		target_map.erase(it);
	}
}

ATarget *	TargetGenerator::createTarget(std::string const & tn){
	if (tn.empty())//une condition de if a la fois pour eviter des erreurs bete
		return (NULL);
	std::map<std::string, ATarget*>::iterator it = target_map.find(tn);
	if (it != target_map.end())
		return target_map[tn]->clone();
	return (NULL);
}
