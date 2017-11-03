#include "RoomState.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Forgotten
{
	RoomState::RoomState(string name)
	{
		mName = name;
	}

	void RoomState::Enter()
	{
		string filename = "Content//" + mName + ".txt"; //Depending on the room we're in, we're going to open the text file associated with that room.
		ifstream f(filename);

		if (f.is_open())
			std::cout << f.rdbuf();

		cout << "Now entering " + mName << endl;


	}

	void RoomState::Exit()
	{
		cout << "Now leaving..." << endl;
	}

	shared_ptr<State> RoomState::Update()
	{
		for each(shared_ptr<Transition> t in mTransitions)
		{
			
			if (t->IsTriggered())
				return t->Target();
		}
		
		return NULL;
	}
}
