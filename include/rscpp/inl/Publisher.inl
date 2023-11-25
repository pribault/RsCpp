#pragma once

#include <rscpp/Subscriber.h>

template <typename T>
rscpp::Publisher<T>::Publisher() = default;

template <typename T>
void rscpp::Publisher<T>::subscribe(Subscriber<T> &subscriber)
{
	if (d_ptr)
		d_ptr->subscribe(subscriber);
}

template <typename T>
rscpp::Publisher<T>::Publisher(const std::shared_ptr<Publisher<T>> &dd)
	: d_ptr(dd)
{
}
