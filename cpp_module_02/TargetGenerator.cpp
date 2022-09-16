#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){
	for (std::map<std::string, ATarget*>::iterator it = target_map.begin(); it != target_map.end(); ++it){
		delete it->second;
	}
	target_map.clear();
}

TargetGenerator::TargetGenerator(const TargetGenerator & src){

}

TargetGenerator &	TargetGenerator::operator=(const TargetGenerator & src){
	return (*this);
}

void	TargetGenerator::learnTargetType(ATarget* at){

}

void	TargetGenerator::forgetTargetType(std::string const & tn){

}

ATarget *	TargetGenerator::createTarget(std::string const & tn){
	
}
