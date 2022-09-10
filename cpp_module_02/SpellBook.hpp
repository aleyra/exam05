#ifndef SPELL_BOOK_H
# define SPELL_BOOK_H

# include "Fireball.hpp"
# include "Fwoosh.hpp"
# include "Polymorph.hpp"
# include "ATarget.hpp"
# include <map>

class ATarget;

class SpellBook{
public:
	std::map<std::string, ASpell*>	spell_map;

public:
	SpellBook();
	virtual ~SpellBook();
private:
	SpellBook(SpellBook const & src);
	SpellBook &	operator=(SpellBook const & src);
	
public:
	void learnSpell(ASpell* as);
	void forgetSpell(std::string const & sn);
	ASpell* createSpell(std::string const & sn);
};

#endif