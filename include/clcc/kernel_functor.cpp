inline KernelFunctor& KernelFunctor::operator=(const KernelFunctor& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	kernel_ = rhs.kernel_;
	queue_ = rhs.queue_;
	offset_ = rhs.offset_;
	global_ = rhs.global_;
	local_ = local_;

	return *this;
}

inline KernelFunctor::KernelFunctor(const KernelFunctor& rhs) :
	kernel_(rhs.kernel_), queue_(rhs.queue_)
{
	*this = rhs;
}

Event KernelFunctor::operator()(const VECTOR_CLASS<Event>* events)
{
	Event event;

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1>
Event KernelFunctor::operator()(const A1& a1, const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1, typename A2>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const VECTOR_CLASS<
		Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1, typename A2, typename A3>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1, typename A2, typename A3, typename A4>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1, typename A2, typename A3, typename A4, typename A5>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1, typename A2, typename A3, typename A4, typename A5,
		typename A6>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6,
		const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1, typename A2, typename A3, typename A4, typename A5,
		typename A6, typename A7>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6, const A7& a7,
		const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);
	kernel_.setArg(6, a7);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1, typename A2, typename A3, typename A4, typename A5,
		typename A6, typename A7, typename A8>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
		const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);
	kernel_.setArg(6, a7);
	kernel_.setArg(7, a8);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1, typename A2, typename A3, typename A4, typename A5,
		typename A6, typename A7, typename A8, typename A9>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
		const A9& a9, const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);
	kernel_.setArg(6, a7);
	kernel_.setArg(7, a8);
	kernel_.setArg(8, a9);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<typename A1, typename A2, typename A3, typename A4, typename A5,
		typename A6, typename A7, typename A8, typename A9, typename A10>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
		const A9& a9, const A10& a10, const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);
	kernel_.setArg(6, a7);
	kernel_.setArg(7, a8);
	kernel_.setArg(8, a9);
	kernel_.setArg(9, a10);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<class A1, class A2, class A3, class A4, class A5, class A6, class A7,
		class A8, class A9, class A10, class A11>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
		const A9& a9, const A10& a10, const A11& a11,
		const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);
	kernel_.setArg(6, a7);
	kernel_.setArg(7, a8);
	kernel_.setArg(8, a9);
	kernel_.setArg(9, a10);
	kernel_.setArg(10, a11);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<class A1, class A2, class A3, class A4, class A5, class A6, class A7,
		class A8, class A9, class A10, class A11, class A12>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
		const A9& a9, const A10& a10, const A11& a11, const A12& a12,
		const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);
	kernel_.setArg(6, a7);
	kernel_.setArg(7, a8);
	kernel_.setArg(8, a9);
	kernel_.setArg(9, a10);
	kernel_.setArg(10, a11);
	kernel_.setArg(11, a12);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<class A1, class A2, class A3, class A4, class A5, class A6, class A7,
		class A8, class A9, class A10, class A11, class A12, class A13>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
		const A9& a9, const A10& a10, const A11& a11, const A12& a12,
		const A13& a13, const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);
	kernel_.setArg(6, a7);
	kernel_.setArg(7, a8);
	kernel_.setArg(8, a9);
	kernel_.setArg(9, a10);
	kernel_.setArg(10, a11);
	kernel_.setArg(11, a12);
	kernel_.setArg(12, a13);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<class A1, class A2, class A3, class A4, class A5, class A6, class A7,
		class A8, class A9, class A10, class A11, class A12, class A13,
		class A14>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
		const A9& a9, const A10& a10, const A11& a11, const A12& a12,
		const A13& a13, const A14& a14, const VECTOR_CLASS<Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);
	kernel_.setArg(6, a7);
	kernel_.setArg(7, a8);
	kernel_.setArg(8, a9);
	kernel_.setArg(9, a10);
	kernel_.setArg(10, a11);
	kernel_.setArg(11, a12);
	kernel_.setArg(12, a13);
	kernel_.setArg(13, a14);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}

template<class A1, class A2, class A3, class A4, class A5, class A6, class A7,
		class A8, class A9, class A10, class A11, class A12, class A13,
		class A14, class A15>
Event KernelFunctor::operator()(const A1& a1, const A2& a2, const A3& a3,
		const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
		const A9& a9, const A10& a10, const A11& a11, const A12& a12,
		const A13& a13, const A14& a14, const A15& a15, const VECTOR_CLASS<
				Event>* events)
{
	Event event;

	kernel_.setArg(0, a1);
	kernel_.setArg(1, a2);
	kernel_.setArg(2, a3);
	kernel_.setArg(3, a4);
	kernel_.setArg(4, a5);
	kernel_.setArg(5, a6);
	kernel_.setArg(6, a7);
	kernel_.setArg(7, a8);
	kernel_.setArg(8, a9);
	kernel_.setArg(9, a10);
	kernel_.setArg(10, a11);
	kernel_.setArg(11, a12);
	kernel_.setArg(12, a13);
	kernel_.setArg(13, a14);
	kernel_.setArg(14, a15);

	queue_.enqueueNDRangeKernel(kernel_, offset_, global_, local_, NULL, &event);

	return event;
}
