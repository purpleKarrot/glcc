/*! \class Memory
 * \brief Memory interface for cl_mem.
 */
class Memory: public detail::Wrapper<cl_mem>
{
public:

	cl_mem_object_type type() const
	{
		return get<cl_mem_object_type> (CL_MEM_TYPE);
	}

	cl_mem_flags flags() const
	{
		return get<cl_mem_flags> (CL_MEM_FLAGS);
	}

	std::size_t size() const
	{
		return get<std::size_t> (CL_MEM_SIZE);
	}

	void* host_ptr() const
	{
		return get<void*> (CL_MEM_HOST_PTR);
	}

	cl_uint map_count() const
	{
		return get<cl_uint> (CL_MEM_MAP_COUNT);
	}

	cl_uint reference_count() const
	{
		return get<cl_uint> (CL_MEM_REFERENCE_COUNT);
	}

	cl_context context() const
	{
		return get<cl_context> (CL_MEM_CONTEXT);
	}

private:
	template<typename T>
	T get(cl_mem_info name) const
	{
		return detail::info<T>::get(clGetMemObjectInfo, object_, name);
	}

private:
	//	cl_mem name_;
};
