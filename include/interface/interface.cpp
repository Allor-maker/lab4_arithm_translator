#include "interface.h"

void Interface::print_ch(const char& ch)
{
	std::cout << ch;
}
void Interface:: set_color(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void Interface::print_red_ch(const char& ch)
{
	set_color(12);//red
	std::cout << ch;
	set_color(7);//white
}
void Interface::delete_ch()
{
	std::cout << "\b \b";
}
