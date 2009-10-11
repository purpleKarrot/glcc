class Program: public detail::Wrapper<cl_program>
{
public:
	typedef std::vector<std::pair<const void*, ::size_t> > Binaries;
	typedef std::vector<std::pair<const char*, ::size_t> > Sources;

	Program(const Context& context, const Sources& sources, cl_int* err = NULL)
	{
		cl_int error;

		const cl_uint n = (cl_uint) sources.size();
		::size_t* lengths = (::size_t*) alloca(n * sizeof(::size_t));
		const char** strings = (const char**) alloca(n * sizeof(const char*));

		for (::size_t i = 0; i < n; ++i)
		{
			strings[i] = sources[i].first;
			lengths[i] = sources[i].second;
		}

		object_ = ::clCreateProgramWithSource(context(), n, strings, lengths,
				&error);

		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
	}

	Program(const Context& context, const VECTOR_CLASS<cl::device>& devices,
			const Binaries& binaries,
			VECTOR_CLASS<cl_int>* binaryStatus = NULL, cl_int* err = NULL)
	{
		cl_int error;
		const ::size_t n = binaries.size();
		::size_t* lengths = (::size_t*) alloca(n * sizeof(::size_t));
		const unsigned char** images = (const unsigned char**) alloca(n
				* sizeof(const void*));

		for (::size_t i = 0; i < n; ++i)
		{
			images[i] = (const unsigned char*) binaries[i].first;
			lengths[i] = binaries[i].second;
		}

		object_ = ::clCreateProgramWithBinary(context(),
				(cl_uint) devices.size(), (cl_device_id*) &devices.front(),
				lengths, images,
				binaryStatus != NULL ? (cl_int*) &binaryStatus->front() : NULL,
				&error);

		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
	}

	//! Default constructor; program is not valid at this point.
	Program()
	{
	}

	void build(const VECTOR_CLASS<cl::device>& devices, const char* options =
			NULL, void(*notifyFptr)(cl_program, void *) = NULL, void* data =
			NULL) const
	{
		CLCC_CHECK_ERROR(::clBuildProgram(object_, (cl_uint) devices.size(),
				(cl_device_id*) &devices.front(), options, notifyFptr, data));
	}

	template<typename T>
	void getInfo(cl_program_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetProgramInfo, object_, name,
				param));
	}

	template<cl_int name> typename detail::param_traits<
			detail::cl_program_info, name>::param_type getInfo(cl_int* err =
			NULL) const
	{
		typename detail::param_traits<detail::cl_program_info, name>::param_type
				param;
		cl_int result = getInfo(name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}

	template<typename T>
	void getBuildInfo(const cl::device& device, cl_program_build_info name,
			T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetProgramBuildInfo, object_,
				device.id_, name, param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_program_build_info, name>::param_type //
	getBuildInfo(const cl::device& device, cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_program_build_info, name>::param_type
				param;
		cl_int result = getBuildInfo(device, name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}

	void createKernels(VECTOR_CLASS<Kernel>* kernels)
	{
		cl_uint numKernels;
		CLCC_CHECK_ERROR(::clCreateKernelsInProgram(object_, 0, NULL,
				&numKernels));

		Kernel* value = (Kernel*) alloca(numKernels * sizeof(Kernel));
		CLCC_CHECK_ERROR(::clCreateKernelsInProgram(object_, numKernels,
				(cl_kernel*) value, NULL));

		kernels->assign(&value[0], &value[numKernels]);
	}
};
