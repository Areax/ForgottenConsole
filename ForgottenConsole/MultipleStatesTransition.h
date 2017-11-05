#pragma once
#include "Transition.h"

using namespace std;

namespace Forgotten
{
	class State;

	class MultipleStatesTransition : public Transition
	{
	public:
		MultipleStatesTransition();
		void AddState(shared_ptr<State> target);
		void RemoveState(shared_ptr<State> s);
		virtual bool IsTriggered() override;
	
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