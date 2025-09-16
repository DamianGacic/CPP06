
#ifndef IDENTIFY_H
#define IDENTIFY_H


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>

Base*	generate(void);
void	identify(Base* base_pointer);
void	identify(Base& base_reference);


#endif //IDENTIFY_H
