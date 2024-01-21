#pragma once

#include <memory>

namespace rscpp
{
	template <typename T>
	class Subscriber;

	/**
	 * @class Publisher Publisher.h <rscpp/Publisher.h>
	 * @brief A {@link rscpp::Publisher} is a provider of a potentially unbounded number of sequenced elements, publishing them according to
	 * the demand received from its {@link rscpp::Subscriber}(s).
	 *
	 * A {@link rscpp::Publisher} can serve multiple {@link rscpp::Subscriber}s subscribed {@link rscpp::Publisher::subscribe} dynamically
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
		 * @brief {@link rscpp::Publisher} default constructor.
		 */
		Publisher();

		/**
		 * @brief Request {@link rscpp::Publisher} to start streaming data.
		 * <p>
		 * This is a "factory method" and can be called multiple times, each time starting a new {@link rscpp::Subscription}.
		 * <p>
		 * Each {@link rscpp::Subscription} will work for only a single {@link rscpp::Subscriber}.
		 * <p>
		 * A {@link rscpp::Subscriber} should only subscribe once to a single {@link rscpp::Publisher}.
		 * <p>
		 * If the {@link rscpp::Publisher} rejects the subscription attempt or otherwise fails it will
		 * signal the error via {@link rscpp::Subscriber::onError(const std::exception_ptr &)}.
		 *
		 * @param subscriber The {@link rscpp::Subscriber} that will consume signals from this {@link rscpp::Publisher}
		 */
		virtual void subscribe(Subscriber<T> &subscriber);

	protected:
		/**
		 * @private
		 * @brief Construct a new {@link rscpp::Publisher} with the given implementation.
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
