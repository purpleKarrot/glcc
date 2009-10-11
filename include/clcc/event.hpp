/*! \class Event
 * \brief Event interface for cl_event.
 */
class Event: public detail::Wrapper<cl_event>
{
public:
	//! Default constructor; event is not valid at this point.
	Event()
	{
	}

	//	cl::CommandQueue command_queue() const
	//	{
	//		return getInfo<CL_EVENT_COMMAND_QUEUE> (0);
	//	}

	//	__DECLARE_PARAM_TRAITS(cl_event_info,CL_EVENT_COMMAND_QUEUE, cl::CommandQueue)
	//	__DECLARE_PARAM_TRAITS(cl_event_info,CL_EVENT_COMMAND_TYPE, cl_command_type)
	//	__DECLARE_PARAM_TRAITS(cl_event_info,CL_EVENT_REFERENCE_COUNT, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_event_info,CL_EVENT_COMMAND_EXECUTION_STATUS, cl_uint)


	template<typename T>
	void getInfo(cl_event_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetEventInfo, object_, name,
				param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_event_info, name>::param_type //
	getInfo(cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_event_info, name>::param_type
				param;
		cl_int result = getInfo(name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}

	template<typename T>
	void getProfilingInfo(cl_profiling_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetEventProfilingInfo, object_,
				name, param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_profiling_info, name>::param_type //
	getProfilingInfo(cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_profiling_info, name>::param_type
				param;
		cl_int result = getProfilingInfo(name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}

	void wait() const
	{
		CLCC_CHECK_ERROR(::clWaitForEvents(1, &object_));
	}
};

