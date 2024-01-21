#pragma once

#include <rscpp/Publisher.h>
#include <rscpp/Subscriber.h>

namespace rscpp
{
	/**
	 * @class Processor Processor.h <rscpp/Processor.h>
	 * @brief A {@link rscpp::Processor} represents a processing stage—which is both a {@link rscpp::Subscriber}
	 * and a {@link rscpp::Publisher} and obeys the contracts of both.
	 *
	 * @param T the type of element signaled to the {@link rscpp::Subscriber}.
	 * @param R the type of element signaled by the {@link rscpp::Publisher}.
	 */
	template <typename T, typename R>
	class Processor : public Subscriber<T>, public Publisher<R>
	{
	public:
		/**
		 * @private
		 * @brief {@link rscpp::Processor} default constructor.
		 */
		Processor();

	protected:
		/**
		 * @private
		 * @brief Construct a new {@link rscpp::Processor} with the given implementation.
		 *
		 * @param dd The implementation pointer.
		 */
		explicit Processor(const std::shared_ptr<Processor<T, R>> &dd);
	};
} // namespace rscpp

#include <rscpp/inl/Processor.inl>
