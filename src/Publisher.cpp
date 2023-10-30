export module rscpp.Publisher;

import rscpp.Subscriber;

import <memory>;

using namespace std;

export namespace rscpp
{
	template <typename T>
	class Publisher
	{
	public:
		Publisher() = default;

		virtual void subscribe(Subscriber<T> &subscriber)
		{
			if (d_ptr)
				d_ptr->subscribe(subscriber);
		}

	protected:
		explicit Publisher(const shared_ptr<Publisher<T>> &dd)
			: d_ptr(dd)
		{
		}

		shared_ptr<Publisher<T>> d_ptr;
	};
} // namespace rscpp
