export module rscpp.Subscription;

import <memory>;

using namespace std;

export namespace rscpp
{
	class Subscription
	{
	public:
		Subscription() = default;

		virtual void request(size_t count)
		{
			if (d_ptr)
				d_ptr->request(count);
		}

		virtual void cancel()
		{
			if (d_ptr)
				d_ptr->cancel();
		}

	protected:
		explicit Subscription(const shared_ptr<Subscription> &dd)
			: d_ptr(dd)
		{
		}

		shared_ptr<Subscription> d_ptr;
	};
} // namespace rscpp
