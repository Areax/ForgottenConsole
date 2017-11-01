#pragma once
#include "Action.h"
#include "Transition.h"
#include <string>
#include <vector>
#include <functional>

using namespace std;

namespace Forgotten
{
	class State
	{
	public:
		virtual void Enter() = 0;
		virtual void Exit() = 0;
		virtual void AddTransition(shared_ptr<Transition> t);
		virtual void AddTransitions(vector<shared_ptr<Transition>> t);
		virtual shared_ptr<Action> GetEnter();
		virtual void SetEnter(shared_ptr<Action> enter);
		virtual shared_ptr<Action> GetExit();
		virtual void SetExit(shared_ptr<Action> exit);
		virtual void SetName(string name);
		virtual const string& Name();
		virtual const vector<shared_ptr<Transition>>& Transitions();
		virtual shared_ptr<State> Update();


	private:
		shared_ptr<Action> mEnter;
		shared_ptr<Action> mExit;
		string mName;
		vector<shared_ptr<Transition>> mTransitions;


	};
}