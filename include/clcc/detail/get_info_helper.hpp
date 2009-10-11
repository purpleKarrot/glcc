/*
 * get_info_helper.hpp
 *
 *  Created on: 09.10.2009
 *      Author: daniel
 */

#ifndef CLCC_GET_GET_INFO_HELPER_HPP
#define CLCC_GET_GET_INFO_HELPER_HPP

namespace detail
{

template<typename T>
struct info
{
	template<typename Object>
	static T get(cl_int(*function)(Object, cl_uint, std::size_t, void*,
			std::size_t*), Object object, cl_uint name)
	{
		T value;
		CLCC_CHECK_ERROR(function(object, name, sizeof(T), &value, 0));
		return value;
	}
};

template<>
struct info<std::string>
{
	template<typename Object>
	static std::string get(cl_int(*function)(Object, cl_uint, std::size_t,
			void*, std::size_t*), Object object, cl_uint name)
	{
		std::size_t length;
		CLCC_CHECK_ERROR(function(object, name, 0, 0, &length));

		std::string str;
		str.resize(length);
		CLCC_CHECK_ERROR(function(object, name, length, &str[0], 0));

		return str;
	}
};

// GetInfo help struct
template<typename Functor, typename T>
struct GetInfoHelper
{
	static cl_int get(Functor f, cl_uint name, T* param)
	{
		return f(name, sizeof(T), param, NULL);
	}
};

// Specialized GetInfoHelper for VECTOR_CLASS params
template<typename Func, typename T>
struct GetInfoHelper<Func, VECTOR_CLASS<T> >
{
	static cl_int get(Func f, cl_uint name, VECTOR_CLASS<T>* param)
	{
		::size_t required;
		cl_int err = f(name, 0, NULL, &required);
		if (err != CL_SUCCESS)
		{
			return err;
		}

		T* value = (T*) alloca(required);
		err = f(name, required, value, NULL);
		if (err != CL_SUCCESS)
		{
			return err;
		}

		param->assign(&value[0], &value[required / sizeof(T)]);
		return CL_SUCCESS;
	}
};

// Specialized GetInfoHelper for STRING_CLASS params
template<typename Func>
struct GetInfoHelper<Func, STRING_CLASS>
{
	static cl_int get(Func f, cl_uint name, STRING_CLASS* param)
	{
		::size_t required;
		cl_int err = f(name, 0, NULL, &required);
		if (err != CL_SUCCESS)
		{
			return err;
		}

		char* value = (char*) alloca(required);
		err = f(name, required, value, NULL);
		if (err != CL_SUCCESS)
		{
			return err;
		}

		*param = value;
		return CL_SUCCESS;
	}
};

} // end namespace detail

#endif /* CLCC_GET_GET_INFO_HELPER_HPP */
