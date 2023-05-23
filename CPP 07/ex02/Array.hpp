/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:24:07 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/08 15:44:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY
# define ARRAY
# include <iostream>
template< typename T >
class Array 
{
private:

	unsigned int __size;
	T * __array;

protected:

	/* data */

public:


Array(/* args */)
: __size(0), __array(0)
{
}


Array(unsigned int size)
: __size(size)
{
	if (size)
	{
		this->__array = new T[size];
		for (unsigned int i = 0; i < size; i++)
		{
			this->__array[i] = T();
		}
	}
}


~Array()
{
	if (this->__array)
		delete [] this->__array;
	this->__array = 0;
}



Array(const Array< T > &obj)
: __size(obj.size())
{
	if (obj.size())
	{
		this->__array = new T[obj.size()];
		for (unsigned int i = 0; i < obj.size(); i++)
		{
			this->__array[i] = obj[i];
		}
	}
}


Array< T >& operator=(const Array< T >& x)
{
	this->__size = x.size();
	if (this->__array)
	{
		delete [] this->__array;
		this->__array = 0;
	}
	if (this->__size)
	{

		this->__array = new T[this->__size];
		for (unsigned int i = 0; i < this->__size; i++)
		{
			this->__array[i] = x[i];
		}
	}
	return (*this);
}


T & operator[](unsigned int pos) const
{
	if (pos > this->__size)
		throw std::exception();
	return (this->__array[pos]);        
}


unsigned int size() const
{
	return (this->__size);
}
 
};



template < typename T >
std::ostream& operator<<(std::ostream &out, const Array< T > &a)
{
	out << "[";
	for (unsigned int i = 0; i < a.size(); i++)
	{
		out << a[i] << ",";
	}
	out << "]";
	return (out);
}

#endif
