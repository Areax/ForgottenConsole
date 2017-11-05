#include "NarrationAction.h"
#include <fstream>
#include <iostream>

using namespace std;

namespace Forgotten
{
	NarrationAction::NarrationAction()
	{
	}

	NarrationAction::NarrationAction(string name, string textfile) : Action(name)
	{
		mTextfile = textfile == "" ? name : textfile;
	}

	void NarrationAction::operator()()
	{
		//string filename = getFilename("beginning");
		string filename = getFilename(mName);
		string line;
		ifstream f(filename);

		if (f.is_open())
		{
			while (getline(f, line))
			{
				cout << line << '\n';
			}
			f.close();
		}
	}

	string NarrationAction::getFilename(string textfileName)
	{
		return "Content//" + textfileName + ".txt";
	}
}
