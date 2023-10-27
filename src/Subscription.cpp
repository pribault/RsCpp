export module rscpp.Subscription;

import <functional>;
import <memory>;

export namespace rscpp
{
	class Subscription
	{
	public:
		struct State
		{
		};

		using RequestMethod = std::function<void(size_t /* count */)>;
		using CancelMethod = std::function<void()>;
		using StatePtr = std::shared_ptr<State>;

		explicit Subscription() {}
		explicit Subscription(const RequestMethod &requestMethod, const CancelMethod &cancelMethod, const StatePtr &state = nullptr)
			: m_request(requestMethod)
			, m_cancel(cancelMethod)
			, m_state(state)
		{
		}

		inline void request(size_t count) const
		{
			if (m_request)
				m_request(count);
		}

		inline void cancel() const
		{
			if (m_cancel)
				m_cancel();
		}

	protected:
		RequestMethod m_request;
		CancelMethod  m_cancel;
		StatePtr	  m_state;
	};
} // namespace rscpp
