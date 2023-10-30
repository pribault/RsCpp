export module rscpp.Processor;

import rscpp.Publisher;
import rscpp.Subscriber;

using namespace std;

export namespace rscpp
{
	template <typename T, typename R>
	class Processor : public Subscriber<T>, public Publisher<R>
	{
	public:
		Processor() = default;

	protected:
		explicit Processor(const shared_ptr<Processor<T, R>> &dd)
			: Subscriber<T>(static_pointer_cast<Subscriber<T>>(dd))
			, Publisher<R>(static_pointer_cast<Publisher<R>>(dd))
		{
		}
	};
} // namespace rscpp
