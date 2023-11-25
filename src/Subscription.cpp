#include "rscpp/Subscription.h"

using namespace rscpp;
using namespace std;

Subscription::Subscription() = default;

void Subscription::request(size_t count)
{
	if (d_ptr)
		d_ptr->request(count);
}

void Subscription::cancel()
{
	if (d_ptr)
		d_ptr->cancel();
}

Subscription::Subscription(const shared_ptr<Subscription> &dd)
	: d_ptr(dd)
{
}
