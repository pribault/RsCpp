#pragma once

#include <exception>

namespace rscpp
{
	class Subscription;
}

namespace rscpp
{
	template <typename T>
	class Subscriber
	{
	public:
		virtual void onSubscribe(Subscription &subscription) noexcept = 0;

		virtual void onNext(const T &value) noexcept = 0;
		virtual void onError(const std::exception_ptr &exception) noexcept = 0;
		virtual void onComplete() noexcept = 0;
	};
} // namespace rscpp
