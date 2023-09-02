#pragma once

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
		virtual void onSubscribe(const Subscription &subscription) noexcept = 0;

		template <std::enable_if<!std::is_scalar<T>::value, bool> = true>
		virtual void onNext(const T &value) noexcept = 0;
		template <std::enable_if<std::is_scalar<T>::value, bool> = true>
		virtual void onNext(T value) noexcept = 0;

		virtual void onError(const std::exception_ptr &exception) noexcept = 0;
		virtual void onComplete(const Subscription &subscription) noexcept = 0;
	};
} // namespace rscpp
