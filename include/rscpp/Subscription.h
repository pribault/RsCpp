#pragma once

#include <functional>

namespace rscpp
{
	class Subscription
	{
	public:
		using RequestMethod = std::function<void(size_t)>;
		using CancelMethod = std::function<void()>;

		inline Subscription(const RequestMethod &requestMethod, const CancelMethod &cancelMethod)
			: m_request(requestMethod)
			, m_cancel(cancelMethod)
		{
		}
		inline void request(size_t count) const { m_request(count); }
		inline void cancel() const { m_cancel(); }

	protected:
		RequestMethod m_request;
		CancelMethod  m_cancel;
	};
} // namespace rscpp
