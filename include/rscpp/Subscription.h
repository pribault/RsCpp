#pragma once

namespace rscpp
{
	template <typename T>
	class Subscription
	{
	public:
		virtual void request(size_t count) noexcept = 0;
		virtual void cancel() noexcept = 0;
	};
} // namespace rscpp
