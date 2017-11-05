#pragma once
#include <memory>
#include <random>
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

		template<typename Iter, typename RandomGenerator>
		Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
			std::uniform_int_distribution<> dis(0, (int) std::distance(start, end) - 1);
			std::advance(start, dis(g));
			return start;
		}

		template<typename Iter>
		Iter select_randomly(Iter start, Iter end) {
			static std::random_device rd;
			static std::mt19937 gen(rd());
			return select_randomly(start, end, gen);
		}
	};
}