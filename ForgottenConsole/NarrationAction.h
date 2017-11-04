#pragma once
#include "Action.h"

namespace Forgotten
{
	class NarrationAction : public Action
	{
	public:
		NarrationAction(string name, string textfile = "");
		virtual void operator()() override;
		string getFilename(string textfileName);

	private:
		string mTextfile;
	};
}
