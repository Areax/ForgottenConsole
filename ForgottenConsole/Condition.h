#pragma once
namespace Forgotten
{
	class Condition
	{
	public:
		virtual bool operator()() = 0;
	};
}