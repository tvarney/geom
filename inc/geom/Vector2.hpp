
/**
 * \file Vector2.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header of Vector2 structure.
 */

/* Copyright (C) 2014 Troy Varney
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef GEOM_VECTOR_2_HPP
#define GEOM_VECTOR_2_HPP

#include <cstdint>
#include <cmath>

#include "VectorTraits.hpp"

namespace geom {
  /**
   * \brief A templated 2 dimensional vector structure
   */
  template <typename Scalar>
  struct Vector2 {
		typedef Scalar type;
		
    /**
     * \brief Construct a \c Vector2 with 0 length
     */
    constexpr Vector2() :
      x(0), y(0)
    { }
    /**
     * \brief Construct a \c Vector2 with the given components
     * \arg \c x The x component of the \c Vector2 object
     * \arg \c y The y component of the \c Vector2 object
     */
    constexpr Vector2(const Scalar &x, const Scalar &y) :
      x(x), y(y)
    { }
    /**
     * \brief Construct a \c Vector2 object which is a copy of the given
     * \c Vector2 object.
     * \arg \c source The \c Vector2 object to copy
     */
    constexpr Vector2(const Vector2<Scalar> &source) :
      x(source.x), y(source.y)
    { }
    /**
     * \brief Construct a \c Vector2 object which is a converted copy of the
     * given \c Vector2 object.
     * \arg \c source The \c Vector2 object to convert from
     */
    template <typename Other>
    constexpr Vector2(const Vector2<Other> &source) :
      x(source.x), y(source.y)
    { }
    ~Vector2() = default;
    
    /**
     * \brief Assign value from the given \c Vector2 object.
     * \arg \c source The \c Vector2 object to assign values from
     * \return A reference to the \c Vector2 object being assigned to
     */
    Vector2<Scalar> & operator=(const Vector2<Scalar> &source) {
      x = source.x;
      y = source.y;
      return *this;
    }
    /**
     * \brief Assign converted value from the given \c Vector2 object.
     * \arg \c source The \c Vector2 obejct to assign converted values from
     * \return A reference to the \c Vector2 object being assigned to
     */
    template <typename Other>
    Vector2<Scalar> & operator=(const Vector2<Other> &source) {
      x = static_cast<Scalar>(source.x);
      y = static_cast<Scalar>(source.y);
      return *this;
    }
    
		/**
		 * \breif Get a negated copy of this vector.
		 * \return A new \c Vector2 object with components multiplied by -1
		 */
		Vector2<Scalar> operator-() {
			return Vector2<Scalar>(-x, -y);
		}
		
    /**
     * \brief Assign the result of adding two vectors.
     * \arg \c rhs The vector to add to this \c Vector2 object
     * \return A reference to the \c Vector2 object being assigned to
     */
		template <typename RhsType>
    Vector2<Scalar> & operator+=(const Vector2<RhsType> &rhs) {
      return *this = *this + rhs;
    }
		
		/**
		 * \brief Assign the result of subtracting two vectors.
		 * \arg \c rhs The vector to subtract from this \c Vector2 object
		 * \return A reference to the \c Vector2 object being assigned to
		 */
		template <typename RhsType>
		Vector2<Scalar> & operator-=(const Vector2<RhsType> &rhs) {
			return *this = *this - rhs;
		}
		
		/**
		 * \breif Assign the result of multiplying a vector by a scalar.
		 * \arg \c rhs The scalar to multiply this vector by
		 * \return A reference to the \c Vector2 object being assigned to
		 */
		template <typename RhsType>
		Vector2<Scalar> & operator*=(const RhsType &rhs) {
			return *this = *this * rhs;
		}
		
		/**
		 * \brief Assign the result of dividing a vector by a scalar.
		 * \arg \c rhs The scalar to divide this vector by
		 * \return A reference to the \c Vector2 object being assigned to
		 */
		template <typename RhsType>
		Vector2<Scalar> & operator/=(const RhsType &rhs) {
			return *this = *this / rhs;
		}
    
    Scalar x; /**< The x component of the \c Vector2 object */
    Scalar y; /**< The y component of the \c Vector2 object */
  };
  
  typedef Vector2<std::int32_t> Vec2i;
  typedef Vector2<std::uint32_t> Vec2u;
  typedef Vector2<std::int64_t> Vec2l;
  typedef Vector2<std::uint64_t> Vec2ul;
  typedef Vector2<float> Vec2f;
  typedef Vector2<double> Vec2d;
  
	/**
	 * \brief Check \c Vector2 equality component-wise.
	 * \arg \c lhs The left side of the comparison
	 * \arg \c rhs The right side of the comparison
	 * \return If each component in the the lhs vector is equal to the rhs
	 * vector
	 */
	template <typename LType, typename RType>
	bool operator==(const Vector2<LType> &lhs, const Vector2<RType> &rhs) {
		return (lhs.x == rhs.x && lhs.y == rhs.y);
	}
	
	/**
	 * \breif Test if two vectors are not equal.
	 * \arg \c lhs The vector on the left of the inequality operator.
	 * \arg \c rhs The vector on the right of the inequality operator.
	 * \return True if any element is different, False otherwise.
	 */
	template <typename LType, typename RType>
	bool operator!=(const Vector2<LType> &lhs, const Vector2<RType> &rhs) {
		return !(lhs == rhs);
	}
	
	/**
	 * \breif Test vectors component-wise for being less than.
	 * \arg \c lhs The vector on the left of the less than operator.
	 * \arg \c rhs The vector on the right of the less than operator.
	 * \return True if all elements in lhs are smaller than the corresponding
	 * element in rhs.
	 */
	template <typename LType, typename RType>
	bool operator>(const Vector2<LType> &lhs, const Vector2<RType> &rhs) {
		return (lhs.x > rhs.x && lhs.y > rhs.y);
	}
	
	/**
	 * \brief Test vectors component-wise for being less than or equal.
	 * \arg \c lhs The vector on the left of the less than or equal operator.
	 * \arg \c rhs The vector on the right of the less than or equal operator.
	 * \return True if all elements in lhs are smaller than or equal to the
	 * corresponding element in rhs.
	 */
	template <typename LType, typename RType>
	bool operator>=(const Vector2<LType> &lhs, const Vector2<RType> &rhs) {
		return (lhs.x >= rhs.x && lhs.y >= rhs.y);
	}
	
	/**
	 * \brief Test vectors component-wise for being greater than.
	 * \arg \c lhs The vector on the left of the greater than operator.
	 * \arg \c rhs The vector on the right of the greater than operator.
	 * \return True if all elements in lhs are larger than the corresponding
	 * element in rhs.
	 */
	template <typename LType, typename RType>
	bool operator<(const Vector2<LType> &lhs, const Vector2<RType> &rhs) {
		return (lhs.x < rhs.x && lhs.y < rhs.y);
	}
	
	/**
	 * \brief Test vectors component-wise for being greater than or equal.
	 * \arg \c lhs The vector on the left of the greater than or equal operator.
	 * \arg \c rhs The vector on the right of the greater than or equal operator.
	 * \return True if all elements in lhs are larger than or equal to the
	 * corresponding element in rhs.
	 */
	template <typename LType, typename RType>
	bool operator<=(const Vector2<LType> &lhs, const Vector2<RType> &rhs) {
		return (lhs.x <= rhs.x && lhs.y <= rhs.y);
	}
	
  /**
   * \brief Add two \c Vector2 objects together and return the result.
   * \arg \c lhs The operand on the left hand side of the addition symbol
   * \arg \c rhs The operand on the right hand side of the addition symbol
   * \return A new \c Vector2 object that contains the result of adding lhs
	 * and rhs
   */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector2<Result> operator+(const Vector2<LhsType> &lhs,
														const Vector2<RhsType> &rhs)
  {
    return Vector2<Result>(lhs.x + rhs.x, lhs.y + rhs.y);
  }
	
	/**
	 * \breif Subtract two \c Vector2 objects and return the result.
	 * \arg \c lhs The operand on the left hand side of the expression.
	 * \arg \c rhs The operand on the right hand side of the expression.
	 * \return A new \c Vector2 object that contains the results of subtracting
	 * rhs from lhs
	 */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector2<Result> operator-(const Vector2<LhsType> &lhs,
                            const Vector2<RhsType> &rhs)
  {
    return Vector2<Result>(lhs.x - rhs.x, lhs.y - rhs.y);
  }
  
	/**
	 * \brief Piecewise multiply two \c Vector2 objects and return the result.
	 * \arg \c lhs The operand on the left hand side of the expression
	 * \arg \c rhs The operand on the right hand side of the expression
	 * \return A new \c Vector2 object that contains the results of muliplying
	 * lhs by rhs.
	 */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector2<Result> operator*(const Vector2<LhsType> &lhs,
                            const Vector2<RhsType> &rhs)
  {
    return Vector2<Result>(lhs.x * rhs.x, lhs.y * rhs.y);
  }
  
	/**
	 * \breif Piecewise divide two \c Vector2 objects and return the result.
	 * \arg \c lhs The operand on the left hand side of the expression
	 * \arg \c rhs The operand on the right hand side of the expression
	 * \return A new \c Vector2 object that contains the results of dividing lhs
	 * by rhs.
	 */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector2<Result> operator/(const Vector2<LhsType> &lhs,
                            const Vector2<RhsType> &rhs)
  {
    return Vector2<Result>(lhs.x / rhs.x, lhs.y / rhs.y);
  }
	
	/**
	 * \brief Scalar multiplication of a \c Vector2 object.
	 * \arg \c lhs The \c Vector2 object to multiply.
	 * \arg \c rhs The scalar to multiply the \c Vector2 object by.
	 * \return A new \c Vector2 object that is the result of the scalar
	 * multiplication.
	 */
	template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
	Vector2<Result> operator*(const Vector2<LhsType> &lhs, const RhsType &rhs)
	{
		static_assert(!IsVector<RhsType>(),
									"Multiplication not defined for the given types");
		return Vector2<Result>(lhs.x * rhs, lhs.y * rhs);
	}
	
	/**
	 * \breif Scalar mulitplication of a \c Vector2 object.
	 * \arg \c lhs The scalar to multiply the \c Vector2 object by.
	 * \arg \c rhs The \c Vector2 object to multiply.
	 * \return A new \c Vector2 object that is the result of the scalar
	 * multiplication.
	 */
	template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
	Vector2<Result> operator*(const LhsType &lhs, const Vector2<RhsType> &rhs)
	{
		static_assert(!IsVector<LhsType>(),
									"Multiplication not defined for the given types");
		return Vector2<Result>(rhs.x * lhs, rhs.y * lhs);
	}
	
	/**
	 * \breif Scalar division of a \c Vector2 object.
	 * \arg \c lhs The \c Vector2 object to divide.
	 * \arg \c rhs The scalar to divide the \c Vector2 object by.
	 * \return A new \c Vector2 object that is the result of the scalar division
	 */
	template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
	Vector2<Result> operator/(const Vector2<LhsType> &lhs, const RhsType &rhs)
	{
		static_assert(!IsVector<RhsType>(),
									"Division not defined for the given types");
		return Vector2<Result>(lhs.x / rhs, lhs.y / rhs);
	}
	
	/**
	 * \brief Get the length of the vector.
	 * 
	 * Any type vector which isn't a float or double vector is first converted to
	 * a double vector.
	 * 
	 * \arg \c v The vector to get the length of.
	 */
	template <typename Scalar>
	double length(const Vector2<Scalar> &v) {
		return std::sqrt((double)(v.x * v.x + v.y * v.y));
	}
	inline float length(const Vector2<float> &f) {
		return std::sqrt(f.x * f.x + f.y * f.y);
	}
	
	/**
	 * \brief Dot product between two vectors.
	 * \arg \c lhs The \c Vector2 object on the left side of the dot operation.
	 * \arg \c rhs The \c Vector2 object on the right of the dot operation.
	 * \return The result of the dot product of the two \c Vector2 objects.
	 */
	template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
	Result dot(const Vector2<LhsType> &lhs, const Vector2<RhsType> &rhs) {
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}
	
	/**
	 * \brief Reflect the given vector around the given normal.
	 * 
	 * Given reflect(i,n), the reflection is calculated as
	 * \f$ i - 2 * (i \cdot n) * n\f$
	 * 
	 * \arg \c vec The vector to reflect
	 * \arg \c normal The normal vector of the surface vec reflected from
	 * \return A new \c Vector2 object that is the reflection
	 */
	template <typename rtype, typename ltype,
						typename Result = typename VectorOpResult<rtype,ltype>::type>
	Vector2<Result> reflect(const Vector2<ltype> &vec,
													const Vector2<rtype> &normal)
	{
		const Vector2<Result> i(vec);
		const Vector2<Result> n(normal);
		return i - ((2 * dot(i, n)) * n);
	}
	
	/**
	 * \brief Normalize the \c Vector2 object.
	 * 
	 * \arg \c vec The \c Vector2 object to normalize.
	 * \return A new \c Vector2 object which is normalized.
	 */
	template <typename IntegralType, typename RType = double>
	Vector2<RType> normalize(const Vector2<IntegralType> &source) {
		return source / length(source);
	}
	inline Vector2<float> normalize(const Vector2<float> &source) {
		return source / length(source);
	}
	
	/**
	 * \brief Calculate refracted vector.
	 * 
	 * The refracted index is calculated by finding the value
	 * \f$k = 1 - e * e * (1 - (n \cdot i)^2)\f$
	 * and if it is negative returning a null vector, otherwise returning the
	 * vector \f$e * i - (e * (n \cdot i) + k^0.5) * n\f$
	 * 
	 * This function will cause a compile error if the index of refraction is
	 * not a floating point type. To allow this function to work with custom
	 * types that express proper floating point semantics, override the standard
	 * structure \c std::is_floating_point for your type to be \c std::true_type
	 * 
	 * The return type is the common type between the vector types and the index
	 * type.
	 * 
	 * \arg \c i The incident vector.
	 * \arg \c n The normal vector of the refracting surface.
	 * \arg \c eta The index of refraction of the refracting surface.
	 * \return The refracted \c Vector2 object
	 */
	template <typename VType1, typename VType2, typename FType,
						typename R = typename std::common_type<FType,VType1,VType2>::type>
	Vector2<R> refract(const Vector2<VType1> &i, const Vector2<VType2> &n,
										 const FType &eta)
	{
		static_assert(std::is_floating_point<FType>::value,
									"The type of a refraction index must be floating point");
		
		R dot_ni = dot(n, i);
		R k = 1.0 - eta * eta * (1.0 - dot_ni * dot_ni);
		if(k < 0.0) {
			return Vector2<R>(0.0, 0.0);
		}else {
			return (eta * i - (eta * dot_ni + std::sqrt(k)) * n);
		}
	}
	
	template <typename T>
	struct IsVector<Vector2<T>> : public std::true_type { };
	template <typename T>
	struct IsVector2<Vector2<T>> : public std::true_type { };
	template <typename T>
	struct VectorType<Vector2<T>> {
		typedef T type;
	};
}

#endif
