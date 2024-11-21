#pragma once
#include <iostream>
#include "stack.h"
#include <vector>
#include <map>
#include <string>

class Converter
{
	
public:
	static std::string conv(std::vector<char> inp, std::vector<std::pair<char, double>>& operands);
};