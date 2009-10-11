/*! \class Buffer
 * \brief Memory buffer interface.
 */
class Buffer: public Memory
{
public:
	Buffer(const Context& context, cl_mem_flags flags, ::size_t size,
			void* host_ptr = NULL, cl_int* err = NULL)
	{
		cl_int error;
		object_ = ::clCreateBuffer(context(), flags, size, host_ptr, &error);


		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
	}

	//! Default constructor; buffer is not valid at this point.
	Buffer()
	{
	}
};
