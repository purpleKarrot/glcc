/*! \class Context
 * \brief Context interface for cl_context.
 */
class Context: public detail::Wrapper<cl_context>
{
public:

	Context(const VECTOR_CLASS<cl::device>& devices,
			cl_context_properties* properties = NULL, void(*notifyFptr)(
					const char *, const void *, ::size_t, void *) = NULL,
			void* data = NULL, cl_int* err = NULL)
	{
		cl_int error;
		object_ = ::clCreateContext(properties, (cl_uint) devices.size(),
				(cl_device_id*) &devices.front(), notifyFptr, data, &error);

		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
	}

	Context(
			cl_device_type type,
			cl_context_properties* properties = NULL,
			void(*notifyFptr)(const char *, const void *, ::size_t, void *) = NULL,
			void* data = NULL, cl_int* err = NULL)
	{
		cl_int error;
		object_ = ::clCreateContextFromType(properties, type, notifyFptr, data,
				&error);

		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
	}

	//! Default constructor; context is not valid at this point.
	Context()
	{
	}

	template<typename T>
	void getInfo(cl_context_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetContextInfo, object_, name,
				param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_context_info, name>::param_type //
	getInfo(cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_context_info, name>::param_type
				param;
		getInfo(name, &param);
		return param;
	}

	void getSupportedImageFormats(cl_mem_flags flags, cl_mem_object_type type,
			VECTOR_CLASS<ImageFormat>* formats)
	{
		cl_uint numEntries;
		CLCC_CHECK_ERROR(clGetSupportedImageFormats(object_, flags, type, 0,
				NULL, &numEntries));

		ImageFormat* value = (ImageFormat*) alloca(numEntries
				* sizeof(ImageFormat));
		CLCC_CHECK_ERROR(clGetSupportedImageFormats(object_, flags, type,
				numEntries, (cl_image_format*) value, NULL));

		formats->assign(&value[0], &value[numEntries]);
	}
};
