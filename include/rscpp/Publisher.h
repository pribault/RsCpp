#pragma once

#include <functional>

namespace rscpp
{
	template <typename T>
	class Subscriber;
}

namespace rscpp
{
	template <typename T>
	class Publisher
	{
	public:
		using SubscribeMethod = std::function<void(const Subscriber<T> & /* subscriber */)>;

		inline Publisher(const SubscribeMethod &subscribeMethod)
			: m_subscribe(subscribeMethod)
		{
		}
		inline void subscribe(const Subscriber<T> &subscriber) const
		{
			if (m_subscribe)
				m_subscribe(subscriber);
		}

	protected:
		SubscribeMethod m_subscribe;
	};
} // namespace rscpp
