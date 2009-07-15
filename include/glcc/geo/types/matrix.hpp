/*
 * matrix.hpp
 *
 *  Created on: 28.02.2009
 *      Author: daniel
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <glcc/geo/types/vector.hpp>

namespace geo
{

template<typename T, std::size_t M, std::size_t N>
class matrix: public boost::additive<matrix<T, M, N> , //
		boost::multiplicative<matrix<T, M, N> , T> >
{
	enum
	{
		Rows = M, Cols = N, Size = M * N
	};

public:
	matrix()
	{
	}

	~matrix()
	{
	}

	matrix(T a)
	{
	}

	matrix(const matrix& other) :
		elems(other.elems)
	{
	}

	/// Matrizenaddition
	matrix& operator+=(const matrix& other)
	{
		loop_op<Size>::eval(plus_assign(), elems, other.elems);
		return *this;
	}

	/// Matrizensubtraktion
	matrix& operator-=(const matrix& other)
	{
		loop_op<Size>::eval(minus_assign(), elems, other.elems);
		return *this;
	}

	/// Matrizenmultiplikation
	matrix& operator*=(const matrix& other)
	{
		//		Matrix<T> temp(*this);
		//		set_product(temp, other);
		return *this;
	}

	/// Skalarmultiplikation
	matrix& operator*=(T skalar)
	{
		loop_op<Size>::eval(multiplies_assign(), elems, skalar);
		return *this;
	}

	/// Skalardivision
	matrix& operator/=(T skalar)
	{
		loop_op<Size>::eval(divides_assign(), elems, skalar);
		return *this;
	}

//private:
	T elems[Size];
};

} // namespace geo

#endif /* MATRIX_HPP_ */
