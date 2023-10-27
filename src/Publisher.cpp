export module rscpp.Publisher;

import rscpp.Subscriber;

import <functional>;

export namespace rscpp
{
	template <typename T>
	class Publisher
	{
	public:
		using SubscribeMethod = std::function<void(const Subscriber<T> & /* subscriber */)>;

		explicit Publisher() {}
		explicit Publisher(const SubscribeMethod &subscribeMethod)
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
