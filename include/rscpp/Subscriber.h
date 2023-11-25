#pragma once

#include <exception>
#include <memory>

namespace rscpp
{
	class Subscription;

	template <typename T>
	class Subscriber
	{
	public:
		Subscriber();

		virtual void onSubscribe(Subscription &subscription);

		virtual void onNext(const T &value);

		virtual void onError(const std::exception_ptr &error);

		virtual void onComplete();

	protected:
		explicit Subscriber(const std::shared_ptr<Subscriber<T>> &dd);

		std::shared_ptr<Subscriber<T>> d_ptr;
	};
} // namespace rscpp

#include <rscpp/inl/Subscriber.inl>
