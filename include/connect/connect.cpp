#include "connect.h"

void Connect::connection()
{
	char ch;
	do {
		std::string str;
		str = Parser::term_analis();
		std::vector<char> inp = Parser::pars(str);

		std::vector<std::pair<char, double>> operands;
		std::string post_str;
		post_str = Converter::conv(inp, operands);

		double ans;
		ans = Calc::Calculate(post_str, operands);

		std::cout << ans << std::endl;
		std::cout << "Click ESC to close or ENTER to continue";

		ch = _getch();
		if (ch == 13)
			std::cout << std::endl;
	} while (ch != 27);

}