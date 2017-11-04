// ForgottenConsole.cpp : Defines the entry point for the console application.
//
#include "RoomsStateMachine.h"
#include <iostream>
#include <fstream>


using namespace Forgotten;
using namespace std;

string getFilename(string textfileName)
{
	return "Content//" + textfileName + ".txt";
}

int main()
{
	RoomsStateMachine rooms = RoomsStateMachine();
	rooms.Initialize();

	string command;
	string line;
	string filename = getFilename("beginning");
	ifstream f(filename);

	/*if (f.is_open())
		std::cout << f.rdbuf();*/

	if (f.is_open())
	{
		while (getline(f, line))
		{
			cout << line << '\n';
		}
		f.close();
	}

	while (command != "exit")
	{

		cout << ">";
		cin >> command;
		rooms.Update();
	}

    return 0;
}

