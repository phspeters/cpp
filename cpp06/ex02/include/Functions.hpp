#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>
# include <exception>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif