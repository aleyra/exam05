#ifndef TARGET_GENERATOR_H
# define TARGET_GENERATOR_H

# include "iostream"
# include "Dummy.hpp"
# include "BrickWall.hpp"
# include <map>

class TargetGenerator{
	private:
		std::map<std::string, ATarget*>	target_map;
		
	public:
		TargetGenerator();
		virtual ~TargetGenerator();
	private:
		TargetGenerator(const TargetGenerator & src);

		TargetGenerator &	operator=(const TargetGenerator & src);
	
	public:
		void	learnTargetType(ATarget* at);
		void	forgetTargetType(std::string const & tn);
		ATarget *	createTarget(std::string const & tn);
};

#endif