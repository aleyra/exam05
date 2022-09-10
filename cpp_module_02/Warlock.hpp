#ifndef WARLOCK_H
# define WARLOCK_H

# include "iostream"
# include "Fwoosh.hpp"
# include "Dummy.hpp"
# include <map>

class ASpell;
class ATarget;

class Warlock{

private :
	std::string 					_name;
	std::string						_title;
	std::map<std::string, ASpell*>	_spell_map;

private:
	Warlock();
	Warlock(const Warlock &src);
public:
	Warlock(std::string const & N, std::string const & T);
	virtual ~Warlock();

private:
	Warlock	& operator=(Warlock const & src);

public:
	std::string const &	getName()const;
	std::string const &	getTitle()const;

	void	setTitle(std::string const & T);

	void 	introduce() const;

	void	learnSpell(ASpell* as);

	void	forgetSpell(std::string sn);

	void	launchSpell(std::string sn, ATarget const & t);
};

#endif