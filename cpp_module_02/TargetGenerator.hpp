#ifndef TARGETGENERATOR_H
# define TARGETGENERATOR_H

# include "Fireball.hpp"
# include "Fwoosh.hpp"
# include "Polymorph.hpp"
# include "Dummy.hpp"
# include "BrickWall.hpp"
# include <map>

class ASpell;
class ATarget;

class TargetGenerator{

private:
	std::map<std::string, ATarget*>	target_map;
public:
	TargetGenerator();
private:
	TargetGenerator(TargetGenerator const & src);
public:
	virtual ~TargetGenerator();
private:
	TargetGenerator &	operator=(TargetGenerator const & src);

public:
	void	learnTargetType(ATarget* s);
	void	forgetTargetType(std::string const & tn);
	ASpell*	createTarget(std::string const & tn);

};

#endif
