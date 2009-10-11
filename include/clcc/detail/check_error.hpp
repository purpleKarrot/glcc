/**************************************************************
 * Copyright (c) 2009 Daniel Pfeifer                          *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef CLCC_DETAIL_CHECK_ERROR_HPP
#define CLCC_DETAIL_CHECK_ERROR_HPP

//#define CLCC_CHECK_ERROR(X) X
#define CLCC_CHECK_ERROR(X) cl::detail::check_error(X)

#include <boost/system/system_error.hpp>

namespace cl
{
namespace detail
{

struct error_category: boost::system::error_category
{
	const char* name() const
	{
		return "OpenCL";
	}

	std::string message(int value) const
	{
		if (value == CL_SUCCESS)
			return "success";
		if (value == CL_DEVICE_NOT_FOUND)
			return "device not found";
		if (value == CL_DEVICE_NOT_AVAILABLE)
			return "device not available";
		if (value == CL_COMPILER_NOT_AVAILABLE)
			return "compiler not available";
		if (value == CL_MEM_OBJECT_ALLOCATION_FAILURE)
			return "mem object allocation failure";
		if (value == CL_OUT_OF_RESOURCES)
			return "out of resources";
		if (value == CL_OUT_OF_HOST_MEMORY)
			return "out of host memory";
		if (value == CL_PROFILING_INFO_NOT_AVAILABLE)
			return "profiling info not available";
		if (value == CL_MEM_COPY_OVERLAP)
			return "mem copy overlap";
		if (value == CL_IMAGE_FORMAT_MISMATCH)
			return "image format mismatch";
		if (value == CL_IMAGE_FORMAT_NOT_SUPPORTED)
			return "image format not supported";
		if (value == CL_BUILD_PROGRAM_FAILURE)
			return "build program failure";
		if (value == CL_MAP_FAILURE)
			return "map failure";
		if (value == CL_INVALID_VALUE)
			return "invalid value";
		if (value == CL_INVALID_DEVICE_TYPE)
			return "invalid device type";
		if (value == CL_INVALID_PLATFORM)
			return "invalid platform";
		if (value == CL_INVALID_DEVICE)
			return "invalid device";
		if (value == CL_INVALID_CONTEXT)
			return "invalid context";
		if (value == CL_INVALID_QUEUE_PROPERTIES)
			return "invalid queue properties";
		if (value == CL_INVALID_COMMAND_QUEUE)
			return "invalid command queue";
		if (value == CL_INVALID_HOST_PTR)
			return "invalid host ptr";
		if (value == CL_INVALID_MEM_OBJECT)
			return "invalid mem object";
		if (value == CL_INVALID_IMAGE_FORMAT_DESCRIPTOR)
			return "invalid image format descriptor";
		if (value == CL_INVALID_IMAGE_SIZE)
			return "invalid image size";
		if (value == CL_INVALID_SAMPLER)
			return "invalid sampler";
		if (value == CL_INVALID_BINARY)
			return "invalid binary";
		if (value == CL_INVALID_BUILD_OPTIONS)
			return "invalid build options";
		if (value == CL_INVALID_PROGRAM)
			return "invalid program";
		if (value == CL_INVALID_PROGRAM_EXECUTABLE)
			return "invalid program executable";
		if (value == CL_INVALID_KERNEL_NAME)
			return "invalid kernel name";
		if (value == CL_INVALID_KERNEL_DEFINITION)
			return "invalid kernel definition";
		if (value == CL_INVALID_KERNEL)
			return "invalid kernel";
		if (value == CL_INVALID_ARG_INDEX)
			return "invalid arg index";
		if (value == CL_INVALID_ARG_VALUE)
			return "invalid arg value";
		if (value == CL_INVALID_ARG_SIZE)
			return "invalid arg size";
		if (value == CL_INVALID_KERNEL_ARGS)
			return "invalid kernel args";
		if (value == CL_INVALID_WORK_DIMENSION)
			return "invalid work dimension";
		if (value == CL_INVALID_WORK_GROUP_SIZE)
			return "invalid work group size";
		if (value == CL_INVALID_WORK_ITEM_SIZE)
			return "invalid work item size";
		if (value == CL_INVALID_GLOBAL_OFFSET)
			return "invalid global offset";
		if (value == CL_INVALID_EVENT_WAIT_LIST)
			return "invalid event wait list";
		if (value == CL_INVALID_EVENT)
			return "invalid event";
		if (value == CL_INVALID_OPERATION)
			return "invalid operation";
		if (value == CL_INVALID_GL_OBJECT)
			return "invalid gl object";
		if (value == CL_INVALID_BUFFER_SIZE)
			return "invalid buffer size";
		if (value == CL_INVALID_MIP_LEVEL)
			return "invalid mip level";
		return "Unknown error";
	}
};

void check_error(cl_int error)
{
	using namespace boost::system;

	static error_category instance;

	if (error)
		throw system_error(error_code(error, instance));
}

} // namespace detail
} // namespace cl

#endif /* CLCC_DETAIL_CHECK_ERROR_HPP */
