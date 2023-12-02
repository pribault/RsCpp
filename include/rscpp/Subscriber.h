#pragma once

#include <exception>
#include <memory>

namespace rscpp
{
	class Subscription;

	/**
	 * @brief Will receive call to {@link #onSubscribe(Subscription&)} once after passing an instance of {@link Subscriber} to {@link
	 * Publisher::subscribe(Subscriber&)}. <p> No further notifications will be received until {@link Subscription::request(long)} is called. <p> After
	 * signaling demand: <ul> <li> One or more invocations of {@link #onNext(Object)} up to the maximum number defined by {@link Subscription::request(long)}
	 * </li>
	 * <li>
	 * Single invocation of {@link #onError(const std::exception_ptr&)} or {@link Subscriber::onComplete()} which signals a terminal state after which no
	 * further events will be sent.
	 * </ul>
	 * <p>
	 * Demand can be signaled via {@link Subscription::request(size_t)} whenever the {@link Subscriber} instance is capable of handling more.
	 *
	 * @param <T> the type of element signaled
	 */
	template <typename T>
	class Subscriber
	{
	public:
		/**
		 * @private
		 * @brief {@link Subscriber} default constructor.
		 */
		Subscriber();

		/**
		 * @brief Invoked after calling {@link Publisher::subscribe(Subscriber&)}.
		 * <p>
		 * No data will start flowing until {@link Subscription::request(size_t)} is invoked.
		 * <p>
		 * It is the responsibility of this {@link Subscriber} instance to call {@link Subscription::request(size_t)} whenever more data is wanted.
		 * <p>
		 * The {@link Publisher} will send notifications only in response to {@link Subscription::request(size_t)}.
		 *
		 * @param subscription the {@link Subscription} that allows requesting data via {@link Subscription#request(size_t)}
		 */
		virtual void onSubscribe(Subscription &subscription);

		/**
		 * @brief Data notification sent by the {@link Publisher} in response to requests to {@link Subscription::request(size_t)}.
		 *
		 * @param value the element signaled
		 */
		virtual void onNext(const T &value);

		/**
		 * @brief Failed terminal state.
		 * <p>
		 * No further events will be sent even if {@link Subscription::request(size_t)} is invoked again.
		 *
		 * @param error the error signaled
		 */
		virtual void onError(const std::exception_ptr &error);

		/**
		 * @brief Successful terminal state.
		 * <p>
		 * No further events will be sent even if {@link Subscription::request(size_t)} is invoked again.
		 */
		virtual void onComplete();

	protected:
		/**
		 * @private
		 * @brief Construct a new {@link Subscriber} with the given implementation.
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
