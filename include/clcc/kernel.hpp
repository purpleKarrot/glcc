class Kernel: public detail::Wrapper<cl_kernel>
{
public:

	inline Kernel(const Program& program, const char* name, cl_int* err = NULL);

	//! Default constructor; kernel is not valid at this point.
	Kernel()
	{
	}

	std::string function_name() const
	{
		return get<std::string>(CL_KERNEL_FUNCTION_NAME);
	}

	cl_uint num_args() const
	{
		return get<cl_uint> (CL_KERNEL_NUM_ARGS);
	}

	cl_uint reference_count() const
	{
		return get<cl_uint> (CL_KERNEL_REFERENCE_COUNT);
	}

	//	__DECLARE_PARAM_TRAITS(cl_kernel_info,CL_KERNEL_CONTEXT, cl::Context)
	//	__DECLARE_PARAM_TRAITS(cl_kernel_info,CL_KERNEL_PROGRAM, cl::Program)

	//	__DECLARE_PARAM_TRAITS(cl_kernel_work_group_info,CL_KERNEL_WORK_GROUP_SIZE, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_kernel_work_group_info,CL_KERNEL_COMPILE_WORK_GROUP_SIZE, cl::size_t<3>)


	template<typename T>
	void getInfo(cl_kernel_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetKernelInfo, object_, name,
				param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_kernel_info, name>::param_type //
	getInfo(cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_kernel_info, name>::param_type
				param;
		cl_int result = getInfo(name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}

	template<typename T>
	void getWorkGroupInfo(const cl::device& device,
			cl_kernel_work_group_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetKernelWorkGroupInfo,
				device.id_, object_, name, param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_kernel_work_group_info, name>::param_type //
	getWorkGroupInfo(cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_kernel_work_group_info, name>::param_type
				param;
		cl_int result = getWorkGroupInfo(name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}

	template<typename T>
	void setArg(cl_uint index, T value)
	{
		CLCC_CHECK_ERROR(::clSetKernelArg(object_, index,
				detail::KernelArgumentHandler<T>::size(value),
				detail::KernelArgumentHandler<T>::ptr(value)));
	}

	void setArg(cl_uint index, ::size_t size, void* argPtr)
	{
		CLCC_CHECK_ERROR(clSetKernelArg(object_, index, size, argPtr));
	}

	KernelFunctor bind(const CommandQueue& queue, const NDRange& offset,
			const NDRange& global, const NDRange& local)
	{
		return KernelFunctor(*this, queue, offset, global, local);
	}

	KernelFunctor bind(const CommandQueue& queue, const NDRange& global,
			const NDRange& local)
	{
		return KernelFunctor(*this, queue, NullRange, global, local);
	}

private:
	template<typename T>
	T get(cl_kernel_info name) const
	{
		return detail::info<T>::get(clGetKernelInfo, object_, name);
	}
};

