#include "calc.h"

double Calc::Calculate(std::string& post_str, std::vector<std::pair<char, double>>& operands)
{
	Stack<std::vector, double> s1(std::vector<double> {});
	double left, right = 0;
	int i = 0;
	for (char ch : post_str)
	{
		switch (ch)
		{
		case '+':
			right = s1.top();
			s1.pop();
			left = s1.top();
			s1.pop();
			s1.push(left + right);
			break;
		case '-':
			right = s1.top();
			s1.pop();
			left = s1.top();
			s1.pop();
			s1.push(left - right);
			break;
		case '*':
			right = s1.top();
			s1.pop();
			left = s1.top();
			s1.pop();
			s1.push(left * right);
			break;
		case '/':
			right = s1.top();
			s1.pop();
			left = s1.top();
			s1.pop();
			s1.push(left / right);//проверка на ноль?
			break;
		default:
			s1.push(operands[i].second);
			i++;
			break;
		}
	}
	return s1.top();
}