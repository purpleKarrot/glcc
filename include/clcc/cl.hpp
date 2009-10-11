/*******************************************************************************
 * Copyright (c) 2008-2009 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 ******************************************************************************/

/*! \file
 *
 *   \brief C++ bindings for OpenCL 1.0 (rev 45)
 *   \author Benedict R. Gaster and Laurent Morichetti
 *   \version 0.4
 *   \date September 2009
 */

#ifndef CL_HPP_
#define CL_HPP_

#include <clcc/detail/cl.hpp>
#include <clcc/detail/check_error.hpp>

#include <utility>

#include <vector>
#include <string>

#include <alloca.h>

#include <cstring>
#include <boost/array.hpp>
#include <boost/scoped_array.hpp>

/*! \namespace cl
 *
 * \brief The OpenCL C++ bindings are defined within this namespace.
 *
 */
namespace cl
{

class Program;
class device;
class Context;
class CommandQueue;

typedef std::string STRING_CLASS;
#define VECTOR_CLASS std::vector

#if !defined(__MAX_DEFAULT_VECTOR_SIZE)
#define __MAX_DEFAULT_VECTOR_SIZE 10
#endif

/*!
 * \brief size_t class used to interface between C++ and
 * OpenCL C calls that require arrays of size_t values, who's
 * size is known statically.
 */
template<int N>
struct size_t: std::vector<std::size_t>
{
};

typedef boost::array<std::size_t, 3> size_3_t;

namespace detail
{

	template<typename enum_type, cl_int Name>
	struct param_traits
	{
	};

#define __DECLARE_PARAM_TRAITS(token, param_name, T)         \
		struct token;                                        \
		template<>                                           \
		struct param_traits<token, param_name>               \
		{                                                    \
			enum { value = param_name };                     \
			typedef T param_type;                            \
		};                                                   \

	__DECLARE_PARAM_TRAITS(cl_platform_info,CL_PLATFORM_PROFILE, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_platform_info,CL_PLATFORM_VERSION, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_platform_info,CL_PLATFORM_NAME, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_platform_info,CL_PLATFORM_VENDOR, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_platform_info,CL_PLATFORM_EXTENSIONS, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_TYPE, cl_device_type)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_VENDOR_ID, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_COMPUTE_UNITS, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_WORK_GROUP_SIZE, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_WORK_ITEM_SIZES, VECTOR_CLASS< ::size_t>)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_CLOCK_FREQUENCY, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_ADDRESS_BITS, cl_bitfield)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_READ_IMAGE_ARGS, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_WRITE_IMAGE_ARGS, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_MEM_ALLOC_SIZE, cl_ulong)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE2D_MAX_WIDTH, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE2D_MAX_HEIGHT, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE3D_MAX_WIDTH, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE3D_MAX_HEIGHT, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE3D_MAX_DEPTH, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_IMAGE_SUPPORT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_PARAMETER_SIZE, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_SAMPLERS, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MEM_BASE_ADDR_ALIGN, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_SINGLE_FP_CONFIG, cl_device_fp_config)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, cl_device_mem_cache_type)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, cl_ulong)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_GLOBAL_MEM_SIZE, cl_ulong)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, cl_ulong)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_MAX_CONSTANT_ARGS, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_LOCAL_MEM_TYPE, cl_device_local_mem_type)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_LOCAL_MEM_SIZE, cl_ulong)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_ERROR_CORRECTION_SUPPORT, cl_bool)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PROFILING_TIMER_RESOLUTION, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_ENDIAN_LITTLE, cl_bool)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_AVAILABLE, cl_bool)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_COMPILER_AVAILABLE, cl_bool)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_EXECUTION_CAPABILITIES, cl_device_exec_capabilities)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_QUEUE_PROPERTIES, cl_command_queue_properties)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PLATFORM, cl_platform_id)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_NAME, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_VENDOR, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DRIVER_VERSION, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_PROFILE, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_VERSION, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_device_info,CL_DEVICE_EXTENSIONS, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_context_info,CL_CONTEXT_REFERENCE_COUNT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_context_info,CL_CONTEXT_DEVICES, VECTOR_CLASS<device>)
	__DECLARE_PARAM_TRAITS(cl_context_info,CL_CONTEXT_PROPERTIES, cl_context_properties)
	__DECLARE_PARAM_TRAITS(cl_event_info,CL_EVENT_COMMAND_QUEUE, cl::CommandQueue)
	__DECLARE_PARAM_TRAITS(cl_event_info,CL_EVENT_COMMAND_TYPE, cl_command_type)
	__DECLARE_PARAM_TRAITS(cl_event_info,CL_EVENT_REFERENCE_COUNT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_event_info,CL_EVENT_COMMAND_EXECUTION_STATUS, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_profiling_info,CL_PROFILING_COMMAND_QUEUED, cl_ulong)
	__DECLARE_PARAM_TRAITS(cl_profiling_info,CL_PROFILING_COMMAND_SUBMIT, cl_ulong)
	__DECLARE_PARAM_TRAITS(cl_profiling_info,CL_PROFILING_COMMAND_START, cl_ulong)
	__DECLARE_PARAM_TRAITS(cl_profiling_info,CL_PROFILING_COMMAND_END, cl_ulong)
	__DECLARE_PARAM_TRAITS(cl_mem_info,CL_MEM_TYPE, cl_mem_object_type)
	__DECLARE_PARAM_TRAITS(cl_mem_info,CL_MEM_FLAGS, cl_mem_flags)
	__DECLARE_PARAM_TRAITS(cl_mem_info,CL_MEM_SIZE, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_mem_info,CL_MEM_HOST_PTR, void*)
	__DECLARE_PARAM_TRAITS(cl_mem_info,CL_MEM_MAP_COUNT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_mem_info,CL_MEM_REFERENCE_COUNT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_mem_info,CL_MEM_CONTEXT, cl::Context)
	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_FORMAT, cl_image_format)
	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_ELEMENT_SIZE, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_ROW_PITCH, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_SLICE_PITCH, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_WIDTH, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_HEIGHT, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_image_info,CL_IMAGE_DEPTH, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_REFERENCE_COUNT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_CONTEXT, cl::Context)
	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_NORMALIZED_COORDS, cl_addressing_mode)
	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_ADDRESSING_MODE, cl_filter_mode)
	__DECLARE_PARAM_TRAITS(cl_sampler_info,CL_SAMPLER_FILTER_MODE, cl_bool)
	__DECLARE_PARAM_TRAITS(cl_program_info,CL_PROGRAM_REFERENCE_COUNT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_program_info,CL_PROGRAM_CONTEXT, cl::Context)
	__DECLARE_PARAM_TRAITS(cl_program_info,CL_PROGRAM_NUM_DEVICES, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_program_info,CL_PROGRAM_DEVICES, VECTOR_CLASS<cl_device_id>)
	__DECLARE_PARAM_TRAITS(cl_program_info,CL_PROGRAM_SOURCE, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_program_info,CL_PROGRAM_BINARY_SIZES, VECTOR_CLASS< ::size_t>)
	__DECLARE_PARAM_TRAITS(cl_program_info,CL_PROGRAM_BINARIES, VECTOR_CLASS<char *>)
	__DECLARE_PARAM_TRAITS(cl_program_build_info,CL_PROGRAM_BUILD_STATUS, cl_build_status)
	__DECLARE_PARAM_TRAITS(cl_program_build_info,CL_PROGRAM_BUILD_OPTIONS, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_program_build_info,CL_PROGRAM_BUILD_LOG, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_kernel_info,CL_KERNEL_FUNCTION_NAME, STRING_CLASS)
	__DECLARE_PARAM_TRAITS(cl_kernel_info,CL_KERNEL_NUM_ARGS, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_kernel_info,CL_KERNEL_REFERENCE_COUNT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_kernel_info,CL_KERNEL_CONTEXT, cl::Context)
	__DECLARE_PARAM_TRAITS(cl_kernel_info,CL_KERNEL_PROGRAM, cl::Program)
	__DECLARE_PARAM_TRAITS(cl_kernel_work_group_info,CL_KERNEL_WORK_GROUP_SIZE, ::size_t)
	__DECLARE_PARAM_TRAITS(cl_kernel_work_group_info,CL_KERNEL_COMPILE_WORK_GROUP_SIZE, cl::size_t<3>)
	__DECLARE_PARAM_TRAITS(cl_command_queue_info,CL_QUEUE_CONTEXT, cl::Context)
	__DECLARE_PARAM_TRAITS(cl_command_queue_info,CL_QUEUE_DEVICE, cl::device)
	__DECLARE_PARAM_TRAITS(cl_command_queue_info,CL_QUEUE_REFERENCE_COUNT, cl_uint)
	__DECLARE_PARAM_TRAITS(cl_command_queue_info,CL_QUEUE_PROPERTIES, cl_command_queue_properties)

#undef __DECLARE_PARAM_TRAITS
}

#include <clcc/detail/get_info_helper.hpp>

namespace detail
{

	template<typename Func, typename T>
	inline cl_int getInfo(Func f, cl_uint name, T* param)
	{
		return GetInfoHelper<Func, T>::get(f, name, param);
	}

	template<typename Func, typename Arg0>
	struct GetInfoFunctor0
	{
		Func f_;
		const Arg0& arg0_;
		cl_int operator ()(cl_uint param, ::size_t size, void* value,
				::size_t* size_ret)
		{
			return f_(arg0_, param, size, value, size_ret);
		}
	};

	template<typename Func, typename Arg0, typename Arg1>
	struct GetInfoFunctor1
	{
		Func f_;
		const Arg0& arg0_;
		const Arg1& arg1_;
		cl_int operator ()(cl_uint param, ::size_t size, void* value,
				::size_t* size_ret)
		{
			return f_(arg0_, arg1_, param, size, value, size_ret);
		}
	};

	template<typename Func, typename Arg0, typename T>
	inline cl_int getInfo(Func f, const Arg0& arg0, cl_uint name, T* param)
	{
		GetInfoFunctor0<Func, Arg0> f0 =
		{	f, arg0};
		return GetInfoHelper<GetInfoFunctor0<Func, Arg0> , T>::get(f0, name, param);
	}

	template<typename Func, typename Arg0, typename Arg1, typename T>
	inline cl_int getInfo(Func f, const Arg0& arg0, const Arg1& arg1, cl_uint name,
			T* param)
	{
		GetInfoFunctor1<Func, Arg0, Arg1> f0 =
		{	f, arg0, arg1};
		return GetInfoHelper<GetInfoFunctor1<Func, Arg0, Arg1> , T>::get(f0, name,
				param);
	}

	template<typename T>
	struct ReferenceHandler
	{
	};

	template<>
	struct ReferenceHandler<cl_device_id>
	{
		// cl_device_id does not have retain().
		static cl_int retain(cl_device_id device)
		{
			return CL_INVALID_DEVICE;
		}
		// cl_device_id does not have release().
		static cl_int release(cl_device_id device)
		{
			return CL_INVALID_DEVICE;
		}
	};

	template<>
	struct ReferenceHandler<cl_platform_id>
	{
		// cl_platform_id does not have retain().
		static cl_int retain(cl_platform_id device)
		{
			return CL_INVALID_PLATFORM;
		}
		// cl_platform_id does not have release().
		static cl_int release(cl_platform_id device)
		{
			return CL_INVALID_PLATFORM;
		}
	};

	template<>
	struct ReferenceHandler<cl_context>
	{
		static cl_int retain(cl_context context)
		{
			return ::clRetainContext(context);
		}
		static cl_int release(cl_context context)
		{
			return ::clReleaseContext(context);
		}
	};

	template<>
	struct ReferenceHandler<cl_command_queue>
	{
		static cl_int retain(cl_command_queue queue)
		{
			return ::clRetainCommandQueue(queue);
		}
		static cl_int release(cl_command_queue queue)
		{
			return ::clReleaseCommandQueue(queue);
		}
	};

	template<>
	struct ReferenceHandler<cl_mem>
	{
		static cl_int retain(cl_mem memory)
		{
			return ::clRetainMemObject(memory);
		}
		static cl_int release(cl_mem memory)
		{
			return ::clReleaseMemObject(memory);
		}
	};

	template<>
	struct ReferenceHandler<cl_sampler>
	{
		static cl_int retain(cl_sampler sampler)
		{
			return ::clRetainSampler(sampler);
		}
		static cl_int release(cl_sampler sampler)
		{
			return ::clReleaseSampler(sampler);
		}
	};

	template<>
	struct ReferenceHandler<cl_program>
	{
		static cl_int retain(cl_program program)
		{
			return ::clRetainProgram(program);
		}
		static cl_int release(cl_program program)
		{
			return ::clReleaseProgram(program);
		}
	};

	template<>
	struct ReferenceHandler<cl_kernel>
	{
		static cl_int retain(cl_kernel kernel)
		{
			return ::clRetainKernel(kernel);
		}
		static cl_int release(cl_kernel kernel)
		{
			return ::clReleaseKernel(kernel);
		}
	};

	template<>
	struct ReferenceHandler<cl_event>
	{
		static cl_int retain(cl_event event)
		{
			return ::clRetainEvent(event);
		}
		static cl_int release(cl_event event)
		{
			return ::clReleaseEvent(event);
		}
	};

	template<typename T>
	class Wrapper
	{
	protected:
		typedef T cl_type;
		cl_type object_;

	public:
		Wrapper() :
		object_(NULL)
		{
		}

		~Wrapper()
		{
			if (object_ != NULL)
			{
				release();
			}
		}

		Wrapper(const Wrapper<cl_type>& rhs)
		{
			object_ = rhs.object_;
			if (object_ != NULL)
			{
				retain();
			}
		}

		Wrapper<cl_type>& operator =(const Wrapper<cl_type>& rhs)
		{
			if (object_ != NULL)
			{
				release();
			}
			object_ = rhs.object_;
			if (object_ != NULL)
			{
				retain();
			}
			return *this;
		}

		cl_type operator ()() const
		{
			return object_;
		}

		cl_type& operator ()()
		{
			return object_;
		}

	protected:

		cl_int retain() const
		{
			return ReferenceHandler<cl_type>::retain(object_);
		}

		cl_int release() const
		{
			return ReferenceHandler<cl_type>::release(object_);
		}
	};

} // namespace detail

/*! \stuct ImageFormat
 * \brief ImageFormat interface fro cl_image_format.
 */
struct ImageFormat: public cl_image_format
{
	ImageFormat(cl_channel_order order, cl_channel_type type)
	{
		image_channel_order = order;
		image_channel_data_type = type;
	}
};

#include <clcc/platform.hpp>
#include <clcc/device.hpp>

/*! \brief Allow to runtime to release the resources allocated by the OpenCL
 *  compiler.
 *
 *  This is a hint from the application and does not guarantee that the compiler
 *  will not be used in the future or that the compiler will actually be
 *  unloaded by the implementation.
 *
 *  \return This call currently always returns CL_SUCCESS
 *
 */
static inline cl_int UnloadCompiler()
{
	return ::clUnloadCompiler();
}

#include <clcc/context.hpp>
#include <clcc/event.hpp>

/*! \brief Wait on the host thread for commands identified by event objects in
 *  event_list to complete.
 *
 *  A command is considered complete if its execution status is CL_COMPLETE or
 *  a negative value. The events specified in event_list act as synchronization
 *  points.
 *
 * \param events is a vector of events.
 *
 *  \return One of the following values:
 *  - CL_SUCCESS if the function was executed successfully.
 *  - CL_INVALID_VALUE if size of \a events is zero.
 *  - CL_INVALID_EVENT if an event in \a events is not valid.
 *
 * \note In the case that exceptions are enabled and error value
 * other than CL_SUCCESS is generated, then cl::Error exception is
 * generated.
 */
inline static void WaitForEvents(const VECTOR_CLASS<Event>& events)
{
	CLCC_CHECK_ERROR( ::clWaitForEvents( (cl_uint) events.size(),
					(cl_event*)&events.front()));
}

#include <clcc/memory.hpp>
#include <clcc/buffer.hpp>
#include <clcc/image.hpp>
#include <clcc/sampler.hpp>

class Program;
class CommandQueue;
class Kernel;

/*! \class NDRange
 * \brief NDRange interface
 */
class NDRange
{
private:
	size_3_t sizes_;
	cl_uint dimensions_;

public:
	NDRange()
	: dimensions_(0)
	{}

	//! Create a 1D range
	NDRange(::size_t size0)
	: dimensions_(1)
	{
		sizes_[0]=size0;
	}

	//! Create a 2D range
	NDRange(::size_t size0, ::size_t size1)
	: dimensions_(2)
	{
		sizes_[0]=size0;
		sizes_[1]=size1;
	}

	//! Create a 3D range
	NDRange(::size_t size0, ::size_t size1, ::size_t size2)
	: dimensions_(3)
	{
		sizes_[0]=size0;
		sizes_[1]=size1;
		sizes_[2]=size2;
	}

	operator const std::size_t*() const
	{	return sizes_.data();}

	std::size_t dimensions() const
	{	return dimensions_;}
};

//! Null range object
static const NDRange NullRange;

#include <clcc/kernel_functor.hpp>

/*!
 * \struct LocalSpaceArg
 * \brief Local address raper for use with Kernel::setArg
 */
struct LocalSpaceArg
{
	::size_t size_;
};

//! \cond DOXYGEN_DETAIL
namespace detail
{

	template <typename T>
	struct KernelArgumentHandler
	{
		static ::size_t size(const T& value)
		{	return sizeof(T);}
		static T* ptr(T& value)
		{	return &value;}
	};

	template <>
	struct KernelArgumentHandler<LocalSpaceArg>
	{
		static ::size_t size(const LocalSpaceArg& value)
		{	return value.size_;}
		static void* ptr(LocalSpaceArg& value)
		{	return NULL;}
	};

} // namespace detail
//! \endcond

/*! \brief Create a local address space argument
 *
 * \param size is the size in bytes of the memory to be allocated in the
 * __local memory space.
 *
 * \return A local address space argument, of \a size bytes, that can
 * be used as an argument to Kernel::setArgs or to a KernelFunctor(...) call.
 */
inline LocalSpaceArg
__local(::size_t size)
{
	LocalSpaceArg ret =
	{	size};
	return ret;
}

#include <clcc/kernel.hpp>
#include <clcc/program.hpp>

inline Kernel::Kernel(const Program& program, const char* name, cl_int* err)
{
	cl_int error;

	object_ = ::clCreateKernel(program(), name, &error);
	CLCC_CHECK_ERROR(error);

	if (err != NULL)
	{
		*err = error;
	}
}

#include <clcc/command_queue.hpp>
#include <clcc/kernel_functor.cpp>

} // namespace cl

#endif // CL_HPP_
