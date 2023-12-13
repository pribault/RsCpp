#pragma once

#include <memory>

namespace rscpp
{
	template <typename T>
	class Subscriber;

	/**
	 * @class Publisher Publisher.h <rscpp/Publisher.h>
	 * @brief A {@link Publisher} is a provider of a potentially unbounded number of sequenced elements, publishing them according to
	 * the demand received from its {@link Subscriber}(s).
	 *
	 * A {@link Publisher} can serve multiple {@link Subscriber}s subscribed {@link Publisher::subscribe} dynamically
	 * at various points in time.
	 *
	 * @param T the type of element signaled.
	 */
	template <typename T>
	class Publisher
	{
	public:
		/**
		 * @private
		 * @brief {@link Publisher} default constructor.
		 */
		Publisher();

		/**
		 * @brief Request {@link Publisher} to start streaming data.
		 * <p>
		 * This is a "factory method" and can be called multiple times, each time starting a new {@link Subscription}.
		 * <p>
		 * Each {@link Subscription} will work for only a single {@link Subscriber}.
		 * <p>
		 * A {@link Subscriber} should only subscribe once to a single {@link Publisher}.
		 * <p>
		 * If the {@link Publisher} rejects the subscription attempt or otherwise fails it will
		 * signal the error via {@link Subscriber::onError(const std::exception_ptr &)}.
		 *
		 * @param subscriber the {@link Subscriber} that will consume signals from this {@link Publisher}
		 */
		virtual void subscribe(Subscriber<T> &subscriber);

	protected:
		/**
		 * @private
		 * @brief Construct a new {@link Publisher} with the given implementation.
		 *
		 * @param dd The implementation pointer.
		 */
		explicit Publisher(const std::shared_ptr<Publisher<T>> &dd);

		/**
		 * @private
		 * @brief The implementation pointer.
		 */
		std::shared_ptr<Publisher<T>> d_ptr;
	};
} // namespace rscpp

#include <rscpp/inl/Publisher.inl>
