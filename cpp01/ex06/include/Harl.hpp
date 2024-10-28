#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
public:
	Harl();
	~Harl();
	
	void complain(std::string level);

private:
	typedef void (Harl::*HarlMemberFunction)(void);

	int	getStartLevel(std::string level);

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	enum Level {
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

};

#endif