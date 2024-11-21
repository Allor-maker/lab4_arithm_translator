#include "converter.h"

std::string Converter::conv(std::vector<char> inp, std::vector<std::pair<char, double>>& operands)
{
	std::map<char, int> prio = { {'+',1}, {'-',1},{'*',2},{'/',2} };
	Stack<std::vector, char> s1(std::vector<char> {});
	std::string post_str;
	char stack_item;
	for (char ch : inp)
	{
		switch (ch)
		{
		case '(':
			s1.push(ch);
			break;
		case ')':
			stack_item = s1.top();
			s1.pop();
			while (stack_item != '(')
			{
				post_str += stack_item;
				stack_item = s1.top();
				s1.pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!s1.empty())
			{
				stack_item = s1.top();
				s1.pop();
				if (prio[ch] <= prio[stack_item])
				{
					post_str += stack_item;
				}
				else
				{
					s1.push(stack_item);
					break;
				}
			}
			s1.push(ch);
			break;
		default:
			operands.push_back({ ch,ch - '0' });
			post_str += ch;
			break;
		}


	}
	while (!s1.empty())
	{
		stack_item = s1.top();
		s1.pop();
		post_str += stack_item;
	}
	return post_str;
}