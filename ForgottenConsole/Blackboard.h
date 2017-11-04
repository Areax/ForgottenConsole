#pragma once
#include <string>

using namespace std;

namespace Forgotten
{
	class Blackboard
	{
	public:
		static void SetCommand(string command);
		static string GetCommand();
	private:
		static string currentCommand;

		Blackboard();
	};
}