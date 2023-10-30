export module rscpp.Subscriber;

import rscpp.Subscription;

import <exception>;
import <memory>;

using namespace std;

export namespace rscpp
{
	template <typename T>
	class Subscriber
	{
	public:
		Subscriber() = default;

		virtual void onSubscribe(Subscription &subscription)
		{
			if (d_ptr)
				d_ptr->onSubscribe(subscription);
		}

		virtual void onNext(const T &value)
		{
			if (d_ptr)
				d_ptr->onNext(value);
		}

		virtual void onError(const exception_ptr &error)
		{
			if (d_ptr)
				d_ptr->onError(error);
		}

		virtual void onComplete()
		{
			if (d_ptr)
				d_ptr->onComplete();
		}

	protected:
		explicit Subscriber(const shared_ptr<Subscriber<T>> &dd)
			: d_ptr(dd)
		{
		}

		shared_ptr<Subscriber<T>> d_ptr;
	};
} // namespace rscpp
