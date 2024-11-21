#include "parser.h"

std::vector<char> Parser::pars(std::string str)
{
	std::vector<char> v{};
	for (char ch : str)
		v.push_back(ch);
	return v;
}
std::string Parser::term_analis()
{
	std::string input;
	Stack<std::vector, int> S(std::vector<int> {});
	int status = 0;
	int parenthesis_counter = 0;
	char ch = _getch();
	S.push(0);
	while (ch != 13)
	{
		switch (status)
		{
		case 0:
			if ((ch >= 48 && ch <= 57))
			{
				status = 1;
				Interface::print_ch(ch);
				input.push_back(ch);
				S.push(1);
				break;
			}

			if (ch == 40)
			{
				input.push_back(ch);
				status = 0;
				parenthesis_counter++;
				Interface::print_ch(ch);
				break;
			}
			if (ch == 8)
			{
				if (input.size() == 0) break;
				if (input.back() == 40)
					parenthesis_counter--;
				if (input.back() == 41)
					parenthesis_counter++;
				if (S.size() == 1 && S.top() == 0)
				{
					Interface::delete_ch();
					input.pop_back();
					break;
				}
				Interface::delete_ch();
				S.pop();
				input.pop_back();
				status = S.top();
				break;
			}
			else
			{
				Interface::print_red_ch(ch);
				status = 5;
				break;
			}
		case 1:
			if (ch == 43 || ch == 42 || ch == 45 || ch == 47)
			{
				status = 2;
				Interface::print_ch(ch);
				input.push_back(ch);
				S.push(2);
				break;
			}
			if (ch == 8)
			{
				if (input.back() == 41)
					parenthesis_counter++;
				if (input.back() == 40)
					parenthesis_counter--;
				Interface::delete_ch();
				S.pop();
				input.pop_back();
				status = S.top();
				break;
			}
			else
			{
				Interface::print_red_ch(ch);
				status = 5;
				break;
			}
		case 2:
			if (ch == 40)
			{
				status = 0;
				parenthesis_counter++;
				Interface::print_ch(ch);
				input.push_back(ch);
				S.push(0);
				break;
			}
			if ((ch >= 48 && ch <= 57))
			{
				status = 3;
				Interface::print_ch(ch);
				input.push_back(ch);
				S.push(3);
				break;
			}
			if (ch == 8)
			{
				if (input.back() == 40)
					parenthesis_counter--;
				if (input.back() == 41)
					parenthesis_counter++;
				Interface::delete_ch();
				S.pop();
				input.pop_back();
				status = S.top();
				break;
			}
			else
			{
				Interface::print_red_ch(ch);
				status = 5;
				break;
			}
		case 3:
			if (ch == 41)
			{
				status = 4;
				parenthesis_counter--;
				if (parenthesis_counter < 0)
				{
					Interface::print_red_ch(ch);
					status = 5;
					break;
				}
				Interface::print_ch(ch);
				input.push_back(ch);
				S.push(4);
				break;
			}
			if (ch == 43 || ch == 42 || ch == 45 || ch == 47)
			{
				status = 2;
				Interface::print_ch(ch);
				S.push(2);
				input.push_back(ch);
				break;
			}
			if (ch == 8)
			{
				if (input.back() == 40)
					parenthesis_counter--;
				if (input.back() == 41)
					parenthesis_counter++;
				Interface::delete_ch();
				S.pop();
				input.pop_back();
				status = S.top();
				break;
			}
			else
			{
				Interface::print_red_ch(ch);
				status = 5;
				break;
			}
		case 4:
			if (ch == 41)
			{
				status = 4;
				parenthesis_counter--;
				if (parenthesis_counter < 0)
				{
					Interface::print_red_ch(ch);
					status = 5;
					break;
				}
				Interface::print_ch(ch);
				input.push_back(ch);
				break;
			}
			if (ch == 43 || ch == 42 || ch == 45 || ch == 47)
			{
				status = 2;
				Interface::print_ch(ch);
				input.push_back(ch);
				S.push(2);
				break;
			}
			if (ch == 8)
			{
				if (input.back() == 40)
					parenthesis_counter--;
				if (input.back() == 41)
					parenthesis_counter++;
				Interface::delete_ch();
				S.pop();
				input.pop_back();
				status = S.top();
				break;
			}
			else
			{
				Interface::print_red_ch(ch);
				status = 5;
				break;
			}
		case 5:
			if (ch == 8)
			{
				status = S.top();
				Interface::delete_ch();
				break;
			}
		}
		ch = _getch();
	}
	std::cout << std::endl;
	if (parenthesis_counter != 0)
	{
		std::cout << std::endl;
		std::cout << "Check the number of parenthesis";
	}
	return input;
}