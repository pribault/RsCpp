#pragma once

#include <memory>

namespace rscpp
{
	class Subscription
	{
	public:
		Subscription();

		virtual void request(size_t count);

		virtual void cancel();

	protected:
		explicit Subscription(const std::shared_ptr<Subscription> &dd);

		std::shared_ptr<Subscription> d_ptr;
	};
} // namespace rscpp
