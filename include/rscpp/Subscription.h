#pragma once

#include <memory>

namespace rscpp
{
	/**
	 * @class Subscription Subscription.h <rscpp/Subscription.h>
	 * @brief A {@link rscpp::Subscription} represents a one-to-one lifecycle of a {@link rscpp::Subscriber} subscribing to a {@link rscpp::Publisher}.
	 * <p>
	 * It can only be used once by a single {@link rscpp::Subscriber}.
	 * <p>
	 * It is used to both signal desire for data and cancel demand (and allow resource cleanup).
	 */
	class Subscription
	{
	public:
		/**
		 * @private
		 * @brief {@link rscpp::Subscription} default constructor.
		 */
		Subscription();

		/**
		 * @brief No events will be sent by a {@link rscpp::Publisher} until demand is signaled via this method.
		 * <p>
		 *  It can be called however often and whenever needed—but if the outstanding cumulative demand ever becomes std::numeric_limits<size_t>::max() or more,
		 *  it may be treated by the {@link rscpp::Publisher} as "effectively unbounded".
		 * <p>
		 * Whatever has been requested can be sent by the {@link rscpp::Publisher} so only signal demand for what can be safely handled.
		 * <p>
		 * A {@link rscpp::Publisher} can send less than is requested if the stream ends but
		 * then must emit either {@link rscpp::Subscriber::onError(const std::exception_ptr&)} or {@link rscpp::Subscriber::onComplete()}.
		 *
		 * @param count the strictly positive number of elements to requests to the upstream {@link rscpp::Publisher}
		 */
		virtual void request(size_t count);

		/**
		 * @brief Request the {@link rscpp::Publisher} to stop sending data and clean up resources.
		 * <p>
		 * Data may still be sent to meet previously signalled demand after calling cancel.
		 */
		virtual void cancel();

	protected:
		/**
		 * @private
		 * @brief Construct a new {@link rscpp::Subscription} with the given implementation.
		 *
		 * @param dd The implementation pointer.
		 */
		explicit Subscription(const std::shared_ptr<Subscription> &dd);

		/**
		 * @private
		 * @brief The implementation pointer.
		 */
		std::shared_ptr<Subscription> d_ptr;
	};
} // namespace rscpp
