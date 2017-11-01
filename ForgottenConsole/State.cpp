#include "stdafx.h"
#include "State.h"

using namespace std;

namespace Forgotten
{
	void State::AddTransition(shared_ptr<Transition> t)
	{
		mTransitions.insert(t);
	}
	void State::AddTransitions(vector<shared_ptr<Transition>> t)
	{
		for each(auto transition in t)
		{
			AddTransition(transition);
		}
	}
	shared_ptr<Action> State::GetEnter()
	{
		return mEnter;
	}
	void State::SetEnter(shared_ptr<Action> enter)
	{
		mEnter = enter;
	}
	shared_ptr<Action> State::GetExit()
	{
		return mExit;
	}
	void State::SetExit(shared_ptr<Action> exit)
	{
		mExit = exit;
	}
	void State::SetName(string name)
	{
		mName = name;
	}
	const string & State::Name()
	{
		// TODO: insert return statement here
	}
	const vector<shared_ptr<Transition>>& State::Transitions()
	{
		// TODO: insert return statement here
	}
	shared_ptr<State> State::Update()
	{
		return shared_ptr<State>();
	}
}
