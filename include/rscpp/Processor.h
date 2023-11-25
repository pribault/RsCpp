#pragma once

#include <rscpp/Publisher.h>
#include <rscpp/Subscriber.h>

namespace rscpp
{
	template <typename T, typename R>
	class Processor : public Subscriber<T>, public Publisher<R>
	{
	public:
		Processor();

	protected:
		explicit Processor(const std::shared_ptr<Processor<T, R>> &dd);
	};
} // namespace rscpp

#include <rscpp/inl/Processor.inl>
