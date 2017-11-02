#include "stdafx.h"
#include "State.h"

using namespace std;

namespace Forgotten
{
	void State::AddTransition(shared_ptr<Transition> t)
	{
		mTransitions.push_back(t);
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
		return mName;
	}
	const vector<shared_ptr<Transition>>& State::Transitions()
	{
		return mTransitions;
	}
	shared_ptr<State> State::Update()
	{
		return shared_ptr<State>();
	}
}
