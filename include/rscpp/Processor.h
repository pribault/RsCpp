#pragma once

#include <rscpp/Publisher.h>
#include <rscpp/Subscriber.h>

namespace rscpp
{
	template <typename T, typename R>
	class Processor : public Subscriber<T>, public Publisher<R>
	{
	};
} // namespace rscpp
