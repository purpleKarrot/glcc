/*! \class Sampler
 * \brief Sampler interface for cl_sampler.
 */
class Sampler: public detail::Wrapper<cl_sampler>
{
public:
	//! Default constructor.
	Sampler()
	{
	}

	//	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_REFERENCE_COUNT, cl_uint)
	//	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_CONTEXT, cl::Context)
	//	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_NORMALIZED_COORDS, cl_addressing_mode)
	//	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_ADDRESSING_MODE, cl_filter_mode)
	//	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_FILTER_MODE, cl_bool)

	template<typename T>
	void getInfo(cl_sampler_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetSamplerInfo, object_, name,
				param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_sampler_info, name>::param_type //
	getInfo(cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_sampler_info, name>::param_type
				param;
		cl_int result = getInfo(name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}
};
