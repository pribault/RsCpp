#pragma once

#include <exception>

namespace rscpp
{
	template <typename T>
	class Subscription;
}

namespace rscpp
{
	template <typename T>
	class Subscriber
	{
	public:
		virtual void onSubscribe(Subscription<T> &subscription) noexcept = 0;

		virtual void onNext(const T &value) noexcept = 0;
		virtual void onError(const std::exception_ptr &exception) noexcept = 0;
		virtual void onComplete(const Subscription<T> &subscription) noexcept = 0;
	};
} // namespace rscpp
