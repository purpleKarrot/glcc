/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_SET_HPP
#define GLCC_SET_HPP

#include <boost/scoped_array.hpp>
#include <stdexcept>

namespace gl
{

template<typename T>
class set: private boost::noncopyable
{
	typedef typename T::base_type base_type;

public:
	set(std::size_t count) :
		count_(count), elements_(new unsigned int[count])
	{
		base_type::gen(count_, elements_.get());
	}

	~set()
	{
		base_type::del(count_, elements_.get());
	}

	//	 begin()
	//	 end()
	//	 rbegin()
	//	 rend()

	std::size_t size() const
	{
		return count_;
	}

	base_type operator[](std::size_t idx)
	{
		assert(idx < count_ && "index out of range" );
		return base_type(elements_[idx]);
	}

	base_type at(std::size_t idx)
	{
		if (idx >= count_)
			throw std::out_of_range("gl::set<>: index out of range");

		return base_type(elements_[idx]);
	}

	void swap(set& other)
	{
		std::swap(count_, other.count_);
		elements_.swap(other.elements_);
	}

protected:
	std::size_t count_;
	boost::scoped_array<unsigned int> elements_;
};

} // namespace gl

#endif /* GLCC_SET_HPP */
