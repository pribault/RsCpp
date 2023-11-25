#pragma once

#include <memory>

namespace rscpp
{
	template <typename T>
	class Subscriber;

	template <typename T>
	class Publisher
	{
	public:
		Publisher();

		virtual void subscribe(Subscriber<T> &subscriber);

	protected:
		explicit Publisher(const std::shared_ptr<Publisher<T>> &dd);

		std::shared_ptr<Publisher<T>> d_ptr;
	};
} // namespace rscpp

#include <rscpp/inl/Publisher.inl>
