class device_set;

class device
{
private:
	friend class device_set;

	device(cl_device_id id)
	{
		id_ = id;
	}

public:
	device(const device& other)
	{
		id_ = other.id_;
	}

	device& operator =(const device& other)
	{
		id_ = other.id_;
		return *this;
	}

	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_TYPE, cl_device_type)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_VENDOR_ID, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_COMPUTE_UNITS, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_WORK_GROUP_SIZE, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_WORK_ITEM_SIZES, VECTOR_CLASS< ::size_t>)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_CLOCK_FREQUENCY, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_ADDRESS_BITS, cl_bitfield)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_READ_IMAGE_ARGS, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_WRITE_IMAGE_ARGS, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_MEM_ALLOC_SIZE, cl_ulong)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE2D_MAX_WIDTH, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE2D_MAX_HEIGHT, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE3D_MAX_WIDTH, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE3D_MAX_HEIGHT, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE3D_MAX_DEPTH, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE_SUPPORT, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_PARAMETER_SIZE, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_SAMPLERS, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MEM_BASE_ADDR_ALIGN, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_SINGLE_FP_CONFIG, cl_device_fp_config)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, cl_device_mem_cache_type)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, cl_ulong)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_GLOBAL_MEM_SIZE, cl_ulong)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, cl_ulong)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_CONSTANT_ARGS, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_LOCAL_MEM_TYPE, cl_device_local_mem_type)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_LOCAL_MEM_SIZE, cl_ulong)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_ERROR_CORRECTION_SUPPORT, cl_bool)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PROFILING_TIMER_RESOLUTION, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_ENDIAN_LITTLE, cl_bool)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_AVAILABLE, cl_bool)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_COMPILER_AVAILABLE, cl_bool)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_EXECUTION_CAPABILITIES, cl_device_exec_capabilities)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_QUEUE_PROPERTIES, cl_command_queue_properties)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PLATFORM, cl_platform_id)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_NAME, STRING_CLASS)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_VENDOR, STRING_CLASS)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DRIVER_VERSION, STRING_CLASS)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PROFILE, STRING_CLASS)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_VERSION, STRING_CLASS)
	//	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_EXTENSIONS, STRING_CLASS)

private:

	template<typename T>
	void getInfo(cl_device_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetDeviceInfo, id_, name, param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_device_info, name>::param_type //
	getInfo(cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_device_info, name>::param_type
				param;
		cl_int result = getInfo(name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}

public:
	cl_device_id id_;
};

class device_set
{
public:
	device_set(cl::platform platform, cl_device_type device_type)
	{
		CLCC_CHECK_ERROR(
				clGetDeviceIDs(platform.id_, device_type, 0, 0, &size_));

		ids_.reset(new cl_device_id[size_]);
		CLCC_CHECK_ERROR(clGetDeviceIDs(platform.id_, device_type, size_,
				ids_.get(), 0));
	}

	device operator[](std::size_t idx) const
	{
		return device(ids_[idx]);
	}

	cl_uint size() const
	{
		return size_;
	}

private:
	cl_uint size_;
	boost::scoped_array<cl_device_id> ids_;
};
