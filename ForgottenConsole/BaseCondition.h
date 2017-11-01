#pragma once

namespace Forgotten
{
	class BaseCondition
	{
		virtual bool operator()() = 0;
	};
}