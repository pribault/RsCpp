#pragma once

#include <exception>
#include <memory>

namespace rscpp
{
	class Subscription;

	/**
	 * @class Subscriber Subscriber.h <rscpp/Subscriber.h>
	 * @brief Will receive call to {@link #onSubscribe(Subscription&)} once after passing an instance of {@link rscpp::Subscriber} to
	 * {@link rscpp::Publisher::subscribe(Subscriber&)}.
	 * <p>
	 * No further notifications will be received until {@link rscpp::Subscription::request(size_t)} is called.
	 * <p>
	 * After signaling demand:
	 * <ul>
	 * <li>One or more invocations of {@link #onNext} up to the maximum number defined by {@link rscpp::Subscription::request(size_t)}</li>
	 * <li>Single invocation of {@link #onError(const std::exception_ptr&)} or {@link rscpp::Subscriber::onComplete()} which signals a terminal state after
	 * which no further events will be sent.</li>
	 * </ul>
	 * <p>
	 * Demand can be signaled via {@link rscpp::Subscription::request(size_t)} whenever the {@link rscpp::Subscriber} instance is capable of handling more.
	 *
	 * @param T the type of element signaled.
	 */
	template <typename T>
	class Subscriber
	{
	public:
		/**
		 * @private
		 * @brief {@link rscpp::Subscriber} default constructor.
		 */
		Subscriber();

		/**
		 * @brief Invoked after calling {@link rscpp::Publisher::subscribe(Subscriber&)}.
		 * <p>
		 * No data will start flowing until {@link rscpp::Subscription::request(size_t)} is invoked.
		 * <p>
		 * It is the responsibility of this {@link rscpp::Subscriber} instance to call {@link rscpp::Subscription::request(size_t)} whenever more data is
		 * wanted. <p> The {@link rscpp::Publisher} will send notifications only in response to {@link rscpp::Subscription::request(size_t)}.
		 *
		 * @param subscription the {@link rscpp::Subscription} that allows requesting data via {@link rscpp::Subscription#request(size_t)}
		 */
		virtual void onSubscribe(Subscription &subscription);

		/**
		 * @brief Data notification sent by the {@link rscpp::Publisher} in response to requests to {@link rscpp::Subscription::request(size_t)}.
		 *
		 * @param value the element signaled
		 */
		virtual void onNext(const T &value);

		/**
		 * @brief Failed terminal state.
		 * <p>
		 * No further events will be sent even if {@link rscpp::Subscription::request(size_t)} is invoked again.
		 *
		 * @param error the error signaled
		 */
		virtual void onError(const std::exception_ptr &error);

		/**
		 * @brief Successful terminal state.
		 * <p>
		 * No further events will be sent even if {@link rscpp::Subscription::request(size_t)} is invoked again.
		 */
		virtual void onComplete();

	protected:
		/**
		 * @private
		 * @brief Construct a new {@link rscpp::Subscriber} with the given implementation.
		 *
		 * @param dd The implementation pointer.
		 */
		explicit Subscriber(const std::shared_ptr<Subscriber<T>> &dd);

		/**
		 * @private
		 * @brief The implementation pointer.
		 */
		std::shared_ptr<Subscriber<T>> d_ptr;
	};
} // namespace rscpp

#include <rscpp/inl/Subscriber.inl>
