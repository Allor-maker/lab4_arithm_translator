#pragma once
#include "stack.h"
#include <vector>
#include <map>
class Calc
{
public:
	static double Calculate(std::string& post_str, std::vector<std::pair<char, double>>& operands);
};