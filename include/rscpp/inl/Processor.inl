#pragma once

#include <rscpp/Publisher.h>
#include <rscpp/Subscriber.h>

template <typename T, typename R>
rscpp::Processor<T, R>::Processor() = default;

template <typename T, typename R>
rscpp::Processor<T, R>::Processor(const std::shared_ptr<Processor<T, R>> &dd)
	: Subscriber<T>(std::static_pointer_cast<Subscriber<T>>(dd))
	, Publisher<R>(std::static_pointer_cast<Publisher<R>>(dd))
{
}
