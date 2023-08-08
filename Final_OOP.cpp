//#include <iostream>
//#include"Regestration.h"
#include"Menu.h"
#include"Includes.h"
//#include"User.h"

int main()
{
	setlocale(LC_ALL, "ru");

	Console_reader<std::string> consoleReader;
	Console_writer<std::string> consoleWriter;

	std::vector<User> users;
	const std::string filename = "users.txt";
	Menu::display(consoleReader, consoleWriter, users, filename);


}
