#pragma once
#include "Action.h"

namespace Forgotten
{

	class MultipleStatesAction : public Action
	{

	public:
		MultipleStatesAction(string name);
		
		void AddState(shared_ptr<State> s);
		void RemoveState(shared_ptr<State> s);
		vector<shared_ptr<State>> States();
		virtual void operator()() override;
	private:
		vector<shared_ptr<State>> mStates;

		template<typename I>
		I random_element(I start, I end)
		{
			const unsigned long n = distance(start, end);
			const unsigned long divisor = (RAND_MAX + 1) / n;

			unsigned long k;
			do { k = std::rand() / divisor; } while (k >= n);

			advance(start, k);
			return start;
		};
	};
}