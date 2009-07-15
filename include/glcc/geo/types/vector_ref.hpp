/*
 * vector_ref.hpp
 *
 *  Created on: 16.05.2009
 *      Author: daniel
 */

#ifndef VECTOR_REF_HPP_
#define VECTOR_REF_HPP_

#include "vector.hpp"

template<typename T>
class vec2_ref: private boost::noncopyable
{
public:
	const vector<T, 2>& operator=(const vector<T, 2>& other)
	{
		x_ = other.x();
		y_ = other.y();
		return other;
	}

private:
	vec2_ref(T& x, T& y) :
		x_(x), y_(y)
	{
	}

	T& x_;
	T& y_;
};

template<typename T>
class vec3_ref: private boost::noncopyable
{
public:
	const vector<T, 3>& operator=(const vector<T, 3>& other)
	{
		x_ = other.x();
		y_ = other.y();
		z_ = other.z();
		return other;
	}

private:
	vec3_ref(T& x, T& y, T& z) :
		x_(x), y_(y), z_(z)
	{
	}

	T& x_;
	T& y_;
	T& z_;
};

template<typename T>
class vec4_ref: private boost::noncopyable
{
public:
	const vector<T, 4>& operator=(const vector<T, 4>& other)
	{
		x_ = other.x();
		y_ = other.y();
		z_ = other.z();
		w_ = other.w();
		return other;
	}

private:
	vec4_ref(T& x, T& y, T& z, T& w) :
		x_(x), y_(y), z_(z), w_(w)
	{
	}

	T& x_;
	T& y_;
	T& z_;
	T& w_;
};

#endif /* VECTOR_REF_HPP_ */
