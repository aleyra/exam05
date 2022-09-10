#ifndef SPELLBOOK_H
# define SPELLBOOK_H

# include "Fireball.hpp"
# include "Fwoosh.hpp"
# include "Polymorph.hpp"
# include "Dummy.hpp"
# include "BrickWall.hpp"
# include <map>

class ASpell;
class ATarget;

class SpellBook{

private:
	std::map<std::string, ASpell*>	spell_map;
public:
	SpellBook();
private:
	SpellBook(SpellBook const & src);
public:
	virtual ~SpellBook();
private:
	SpellBook &	operator=(SpellBook const & src);

public:
	void	learnSpell(ASpell* s);
	void	forgetSpell(std::string const & sn);
	ASpell*	createSpell(std::string const & sn);

};

#endif