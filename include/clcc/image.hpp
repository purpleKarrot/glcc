/*! \class Image
 * \brief Base class  interface for all images.
 */
class Image: public Memory
{
public:
	//	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_FORMAT, cl_image_format)
	//	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_ELEMENT_SIZE, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_ROW_PITCH, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_SLICE_PITCH, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_WIDTH, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_HEIGHT, ::size_t)
	//	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_DEPTH, ::size_t)

	template<typename T>
	void getImageInfo(cl_image_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetImageInfo, object_, name,
				param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_image_info, name>::param_type //
	getImageInfo(cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_image_info, name>::param_type
				param;
		cl_int result = getImageInfo(name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}
};

class Image2D: public Image
{
public:
	Image2D(const Context& context, cl_mem_flags flags, ImageFormat format,
			::size_t width, ::size_t height, ::size_t row_pitch,
			void* host_ptr = NULL, cl_int* err = NULL)
	{
		cl_int error;
		object_ = ::clCreateImage2D(context(), flags, &format, width, height,
				row_pitch, host_ptr, &error);

		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
	}

	//! Default constructor; image is not valid at this point.
	Image2D()
	{
	}
};

class Image3D: public Image
{
public:

	Image3D(const Context& context, cl_mem_flags flags, ImageFormat format,
			::size_t width, ::size_t height, ::size_t depth,
			::size_t row_pitch, ::size_t slice_pitch, void* host_ptr = NULL,
			cl_int* err = NULL)
	{
		cl_int error;
		object_ = ::clCreateImage3D(context(), flags, &format, width, height,
				depth, row_pitch, slice_pitch, host_ptr, &error);

		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
	}

	//! Default constructor; image is not valid at this point.
	Image3D()
	{
	}
};
