/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 12:39:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/28 16:09:11 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

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

		Array(void) : _arr(NULL), _n(0)
		{
			std::cout << "Default constructor called" << std::endl;
		}

		Array(unsigned int n) : _arr(new T[n]), _n(n)
		{
			std::cout << "Constructor called" << std::endl;
		}

		Array(const Array& src)
		{
			std::cout << "Copy constructor called" << std::endl;
			*this = src;
		}

		virtual ~Array(void)
		{
			if (this->_arr != 0)
				delete [] this->_arr;
			std::cout << "Destructor called" << std::endl;
		}

		Array&	operator=(const Array& src)
		{
			std::cout << "Constructor called" << std::endl;
			if (this != &src)
			{
				this->_n = src._n;
				this->_arr = src._arr;
			}
			return (*this);
		}

		T& operator[](int index)
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
