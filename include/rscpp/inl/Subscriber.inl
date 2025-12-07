#pragma once

#include <rscpp/Subscription.h>

#include <exception>

template <typename T>
rscpp::Subscriber<T>::Subscriber() = default;

template <typename T>
void rscpp::Subscriber<T>::onSubscribe(Subscription &subscription)
{
	if (d_ptr)
		d_ptr->onSubscribe(subscription);
}

template <typename T>
void rscpp::Subscriber<T>::onNext(const T &value)
{
	if (d_ptr)
		d_ptr->onNext(value);
}

template <typename T>
void rscpp::Subscriber<T>::onError(const std::exception_ptr &error)
{
	if (d_ptr)
		d_ptr->onError(error);
}

template <typename T>
template <typename E>
void rscpp::Subscriber<T>::onError(E error)
{
	onError(std::make_exception_ptr(error));
}

template <typename T>
void rscpp::Subscriber<T>::onComplete()
{
	if (d_ptr)
		d_ptr->onComplete();
}

template <typename T>
rscpp::Subscriber<T>::Subscriber(const std::shared_ptr<Subscriber<T>> &dd)
	: d_ptr(dd)
{
}
