/*! \class KernelFunctor
 * \brief Kernel functor interface
 *
 * \note Currently only functors of zero to ten arguments are supported. It
 * is straightforward to add more and a more general solution, similar to
 * Boost.Lambda could be followed if required in the future.
 */
class KernelFunctor
{
private:
	Kernel& kernel_;
	CommandQueue& queue_;
	NDRange offset_;
	NDRange global_;
	NDRange local_;

public:
	KernelFunctor(Kernel& kernel, const CommandQueue& queue,
			const NDRange& offset, const NDRange& global, const NDRange& local) :
		kernel_(kernel), queue_((CommandQueue&) queue), offset_(
				(NDRange) offset), global_((NDRange) global), local_(
				(NDRange) local)
	{
	}

	/*! \brief Assignment operator.
	 *
	 * \param rhs KernelFunctor object for rhs of assignment.
	 *
	 * \return KernelFunctor object for lhs of assignment.
	 */
	KernelFunctor& operator=(const KernelFunctor& rhs);

	/*! \brief Copy constructor
	 *
	 * \param rhs is the KernelFunctor to be copied (cloned).
	 */
	KernelFunctor(const KernelFunctor& rhs);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	inline Event operator()(const VECTOR_CLASS<Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<typename A1>
	inline Event operator()(const A1& a1, const VECTOR_CLASS<Event>* events =
			NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2>
	inline Event operator()(const A1& a1, const A2& a2, const VECTOR_CLASS<
			Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 3 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const VECTOR_CLASS<Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const VECTOR_CLASS<Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const VECTOR_CLASS<Event>* events =
					NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *  \param a6 is used argument 5 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5, class A6>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6,
			const VECTOR_CLASS<Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *  \param a6 is used argument 5 for the kernel call.
	 *  \param a7 is used argument 6 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5, class A6,
			class A7>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6, const A7& a7,
			const VECTOR_CLASS<Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *  \param a6 is used argument 5 for the kernel call.
	 *  \param a7 is used argument 6 for the kernel call.
	 *  \param a8 is used argument 7 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5, class A6,
			class A7, class A8>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6, const A7& a7,
			const A8& a8, const VECTOR_CLASS<Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *  \param a6 is used argument 5 for the kernel call.
	 *  \param a7 is used argument 6 for the kernel call.
	 *  \param a8 is used argument 7 for the kernel call.
	 *  \param a9 is used argument 8 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5, class A6,
			class A7, class A8, class A9>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6, const A7& a7,
			const A8& a8, const A9& a9, const VECTOR_CLASS<Event>* events =
					NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *  \param a6 is used argument 5 for the kernel call.
	 *  \param a7 is used argument 6 for the kernel call.
	 *  \param a8 is used argument 7 for the kernel call.
	 *  \param a9 is used argument 8 for the kernel call.
	 *  \param a10 is used argument 9 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5, class A6,
			class A7, class A8, class A9, class A10>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6, const A7& a7,
			const A8& a8, const A9& a9, const A10& a10, const VECTOR_CLASS<
					Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *  \param a6 is used argument 5 for the kernel call.
	 *  \param a7 is used argument 6 for the kernel call.
	 *  \param a8 is used argument 7 for the kernel call.
	 *  \param a9 is used argument 8 for the kernel call.
	 *  \param a10 is used argument 9 for the kernel call.
	 *  \param a11 is used argument 10 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5, class A6,
			class A7, class A8, class A9, class A10, class A11>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6, const A7& a7,
			const A8& a8, const A9& a9, const A10& a10, const A11& a11,
			const VECTOR_CLASS<Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *  \param a6 is used argument 5 for the kernel call.
	 *  \param a7 is used argument 6 for the kernel call.
	 *  \param a8 is used argument 7 for the kernel call.
	 *  \param a9 is used argument 8 for the kernel call.
	 *  \param a10 is used argument 9 for the kernel call.
	 *  \param a11 is used argument 10 for the kernel call.
	 *  \param a12 is used argument 11 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5, class A6,
			class A7, class A8, class A9, class A10, class A11, class A12>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6, const A7& a7,
			const A8& a8, const A9& a9, const A10& a10, const A11& a11,
			const A12& a12, const VECTOR_CLASS<Event>* events = NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *  \param a6 is used argument 5 for the kernel call.
	 *  \param a7 is used argument 6 for the kernel call.
	 *  \param a8 is used argument 7 for the kernel call.
	 *  \param a9 is used argument 8 for the kernel call.
	 *  \param a10 is used argument 9 for the kernel call.
	 *  \param a11 is used argument 10 for the kernel call.
	 *  \param a12 is used argument 11 for the kernel call.
	 *  \param a13 is used argument 12 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5, class A6,
			class A7, class A8, class A9, class A10, class A11, class A12,
			class A13>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6, const A7& a7,
			const A8& a8, const A9& a9, const A10& a10, const A11& a11,
			const A12& a12, const A13& a13, const VECTOR_CLASS<Event>* events =
					NULL);

	/*! \brief Enqueue a command to execute a kernel on a device.
	 *
	 *  \param a1 is used argument 0 for the kernel call.
	 *  \param a2 is used argument 1 for the kernel call.
	 *  \param a3 is used argument 2 for the kernel call.
	 *  \param a4 is used argument 3 for the kernel call.
	 *  \param a5 is used argument 4 for the kernel call.
	 *  \param a6 is used argument 5 for the kernel call.
	 *  \param a7 is used argument 6 for the kernel call.
	 *  \param a8 is used argument 7 for the kernel call.
	 *  \param a9 is used argument 8 for the kernel call.
	 *  \param a10 is used argument 9 for the kernel call.
	 *  \param a11 is used argument 10 for the kernel call.
	 *  \param a12 is used argument 11 for the kernel call.
	 *  \param a13 is used argument 12 for the kernel call.
	 *  \param a13 is used argument 13 for the kernel call.
	 *
	 *  \param events specifies the list of events that need to complete before
	 *  this particular command can be executed. If \a events is NULL, its
	 *  default value, then this particular command does not wait on any event
	 *  to complete. The events specified in \a events act as
	 *  synchronization points.
	 *
	 *  \return An event that identifies this particular kernel
	 *  execution instance.
	 *
	 * \note In the case that exceptions are enabled and error value
	 * other than CL_SUCCESS is generated, then cl::Error exception is
	 * generated, otherwise the returned error is stored in the Kernel
	 * object and can get accessed using \a get_error.
	 */
	template<class A1, class A2, class A3, class A4, class A5, class A6,
			class A7, class A8, class A9, class A10, class A11, class A12,
			class A13, class A14>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6, const A7& a7,
			const A8& a8, const A9& a9, const A10& a10, const A11& a11,
			const A12& a12, const A13& a13, const A14& a14, const VECTOR_CLASS<
					Event>* events = NULL);

	template<class A1, class A2, class A3, class A4, class A5, class A6,
			class A7, class A8, class A9, class A10, class A11, class A12,
			class A13, class A14, class A15>
	inline Event operator()(const A1& a1, const A2& a2, const A3& a3,
			const A4& a4, const A5& a5, const A6& a6, const A7& a7,
			const A8& a8, const A9& a9, const A10& a10, const A11& a11,
			const A12& a12, const A13& a13, const A14& a14, const A15& a15,
			const VECTOR_CLASS<Event>* events = NULL);
};

