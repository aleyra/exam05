#include "Warlock.hpp"

Warlock::Warlock(){}

Warlock::Warlock(const Warlock & src){*this = src;}

Warlock::Warlock(std::string const & N, std::string const & T){
	name = N;
	title = T;
	std::cout << name << ": This looks like another boring day.\n";//putain de '.' de merde
}

Warlock::~Warlock(){
	std::cout << name << ": My job here is done!\n";
}

Warlock &	Warlock::operator=(Warlock const & src){
	name = src.name;
	title = src.title;
	return (*this);
}

std::string const & Warlock::getName() const{
	return (name);
}

std::string const &Warlock::getTitle() const {
	return (title);
}

void	Warlock::setTitle(std::string const & T){
	title = T;
}

void Warlock::introduce() const{
	std::cout << name << ": I am " << name << ", " << title << "!\n";
}


