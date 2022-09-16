#ifndef WARLOCK_H
# define WARLOCK_H

# include "iostream"

class Warlock{

private :
	std::string name;
	std::string	title;

private:
	Warlock();
	Warlock(const Warlock &src);
public:
	Warlock(std::string const & N, std::string const & T);
	virtual ~Warlock();

private:
	Warlock & operator=(Warlock const & src);

public:
	std::string const &	getName()const;
	std::string const &	getTitle()const;

	void	setTitle(std::string const & T);

	void 	introduce() const;
};

#endif