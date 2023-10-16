#pragma once

#include <exception>
#include <functional>

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
		using OnSubscribeMethod = std::function<void(const Subscription & /* subscription */)>;
		using OnNextMethod = std::function<void(const T & /* value */)>;
		using OnErrorMethod = std::function<void(const std::exception_ptr & /* error */)>;
		using OnCompleteMethod = std::function<void()>;

		inline Subscriber(const OnSubscribeMethod &onSubcribeMethod, const OnNextMethod &onNextMethod, const OnErrorMethod &onErrorMethod,
						  const OnCompleteMethod &onCompleteMethod)
			: m_onSubscribe(onSubcribeMethod)
			, m_onNext(onNextMethod)
			, m_onError(onErrorMethod)
			, m_onComplete(onCompleteMethod)
		{
		}
		inline void onSubscribe(const Subscription &subscription) const
		{
			if (m_onSubscribe)
				m_onSubscribe(subscription);
		}
		inline void onNext(const T &value) const
		{
			if (m_onNext)
				m_onNext(value);
		}
		inline void onError(const std::exception_ptr &error) const
		{
			if (m_onError)
				m_onError(error);
		}
		inline void onComplete() const
		{
			if (m_onComplete)
				m_onComplete();
		}

	protected:
		OnSubscribeMethod m_onSubscribe;
		OnNextMethod	  m_onNext;
		OnErrorMethod	  m_onError;
		OnCompleteMethod  m_onComplete;
	};
} // namespace rscpp
