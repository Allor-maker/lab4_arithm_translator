#pragma once
#include <iostream>
#include "interface.h"
#include <conio.h>
#include "stack.h"
#include <vector>

class Parser
{	
public:
	static std::vector<char> pars(std::string str);
	static std::string term_analis();
	
};