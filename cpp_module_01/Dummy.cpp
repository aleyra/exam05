#include "Dummy.hpp"

Dummy::Dummy():ATarget("Target Practice Dummy"){
}

Dummy::~Dummy(){}

Dummy*	Dummy::clone() const{//du coup const ici aussi
	return (new Dummy());
}
