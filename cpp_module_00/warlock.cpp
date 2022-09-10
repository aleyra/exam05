#include "Warlock.hpp"

Warlock::Warlock(){}

Warlock::Warlock(const Warlock & src){*this = src;}

Warlock::Warlock(std::string const & N, std::string const & T){
	this->_name = N;
	this->_title = T;
	std::cout << this->_name << ": This looks like another boring day.\n";//putain de '.' de merde
}

Warlock::~Warlock(){
	std::cout << this->_name << ": My job here is done!\n";
}

Warlock &	Warlock::operator=(Warlock const & src){
	this->_name = src._name;
	this->_title = src._title;
	return (*this);
}

std::string const & Warlock::getName() const{
	return (this->_name);
}

std::string const &Warlock::getTitle() const {
	return (this->_title);
}

void	Warlock::setTitle(std::string const & T){
	this->_title = T;
}

void Warlock::introduce() const{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n";
}


