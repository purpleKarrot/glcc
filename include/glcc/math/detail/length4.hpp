/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_DETAIL_LENGTH_4_HPP
#define GLCC_MATH_DETAIL_LENGTH_4_HPP

#include <cmath>
#include <boost/operators.hpp>

namespace gl
{
namespace math
{
namespace detail
{

class length4: public boost::less_than_comparable<length4,
        boost::less_than_comparable<length4, float> >
{
private:

public:
	float squared() const
	{
		return x_ * x_ + y_ * y_;
	}

	operator float() const
	{
		return std::sqrt(squared());
	}

	bool operator<(const length4& other) const
	{
		return squared() < other.squared();
	}

	bool operator<(float d) const
	{
		// TODO: not complete yet
		return x_ < d && y_ < d && (squared() < d * d);
	}

	bool operator>(float d) const
	{
		// TODO: not complete yet
		return x_ > d || y_ > d || (squared() > d * d);
	}

private:
	float x_;
	float y_;
	float z_;
	float w_;
};

} // namespace detail
} // namespace math
} // namespace gl

#endif /* GLCC_MATH_DETAIL_LENGTH_4_HPP */
