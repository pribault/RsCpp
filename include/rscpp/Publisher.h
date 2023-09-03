#pragma once

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
		virtual void subscribe(Subscriber<T> &subscriber) noexcept = 0;
	};
} // namespace rscpp
