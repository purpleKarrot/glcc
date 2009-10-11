class platform_set;

class platform
{
private:
	friend class platform_set;
	friend class device_set;

	platform(cl_platform_id id)
	{
		id_ = id;
	}

public:
	platform(const platform& other)
	{
		id_ = other.id_;
	}

	platform& operator =(const platform& other)
	{
		id_ = other.id_;
		return *this;
	}

	std::string profile()
	{
		return get<std::string>(CL_PLATFORM_PROFILE);
	}

	std::string version()
	{
		return get<std::string>(CL_PLATFORM_VERSION);
	}

	std::string name()
	{
		return get<std::string>(CL_PLATFORM_NAME);
	}

	std::string vendor()
	{
		return get<std::string>(CL_PLATFORM_VENDOR);
	}

	std::string extensions()
	{
		return get<std::string>(CL_PLATFORM_EXTENSIONS);
	}

private:
	template<typename T>
	T get(cl_platform_info name) const
	{
		return detail::info<T>::get(clGetPlatformInfo, id_, name);
	}

private:
	cl_platform_id id_;
};

class platform_set
{
public:
	platform_set() :
		size_(0)
	{
		CLCC_CHECK_ERROR(clGetPlatformIDs(0, 0, &size_));

		ids_.reset(new cl_platform_id[size_]);

		CLCC_CHECK_ERROR(clGetPlatformIDs(size_, ids_.get(), 0));
	}

	platform operator[](std::size_t idx) const
	{
		return platform(ids_[idx]);
	}

	cl_uint size() const
	{
		return size_;
	}

private:
	cl_uint size_;
	boost::scoped_array<cl_platform_id> ids_;
};

