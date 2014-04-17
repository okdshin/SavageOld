#ifndef SAVAGE_DEBUG_H
#define SAVAGE_DEBUG_H
//20140326

#include <iostream>
#define SAVAGE_DEBUG_PRINT(Message) \
	std::cout << "DEBUG: " << Message << std::endl;
#define SAVAGE_DEBUG_DEFAULT_IMPLEMENTATION_USED_NOTATION \
	std::cout << "DEBUG: " << __FILE__  << ":" << __LINE__ << ": default implementation used" << std::endl;

#endif //SAVAGE_DEBUG_H
