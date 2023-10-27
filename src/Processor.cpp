export module rscpp.Processor;

import rscpp.Publisher;
import rscpp.Subscriber;

export namespace rscpp
{
	template <typename T, typename R>
	class Processor : public Subscriber<T>, public Publisher<R>
	{
	};
} // namespace rscpp
