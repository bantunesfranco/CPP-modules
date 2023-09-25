/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 12:39:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/25 14:48:38 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <climits>

template <typename T>
class Array
{
	private:
		T*				_arr;
		unsigned int	_n;

	public:

		class IndexOutOfRangeException : public std::exception
		{
			virtual const char* what(void) const throw()
			{
				return ("Index Out Of Range");
			}
		};

		Array(void) : _arr(new T[0]), _n(0)
		{
			std::cout << "Default constructor called" << std::endl;
		}

		Array(unsigned int n) : _arr(new T[n > INT_MAX ? INT_MAX:n]), _n(n > INT_MAX ? INT_MAX:n)
		{
			std::cout << "Constructor called" << std::endl;
		}

		Array(const Array& src) : _arr(new T[0]),  _n(src._n)
		{
			std::cout << "Copy constructor called" << std::endl;
			*this = src;
		}

		~Array(void)
		{
			if (this->_arr)
				delete[] this->_arr;
			std::cout << "Destructor called" << std::endl;
		}

		Array&	operator=(const Array& src)
		{
			std::cout << "Constructor called" << std::endl;
			if (this != &src)
			{
				if (this->_arr)
					delete[] this->_arr;
				this->_n = src._n;
				this->_arr = new T[this->_n];
				for (unsigned int i = 0; i < this->_n; i++)
					this->_arr[i] = src._arr[i];
			}
			return (*this);
		}

		T& operator[](int index)
		{
			if (index < 0 || index >= static_cast<int>(this->_n))
				throw (Array::IndexOutOfRangeException());
			return (this->_arr[index]);
		}


		const T& operator[](int index) const
		{
			if (index < 0 || index >= static_cast<int>(this->_n))
				throw (Array::IndexOutOfRangeException());
			return (this->_arr[index]);
		}

		unsigned int	size(void)
		{
			return (this->_n);
		}
};

#endif
