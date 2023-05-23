/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:45:01 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/10 17:55:39 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
#define MUTANTSTACK
#include <iostream>
#include <stack>
template <typename T>
class MutantStack : public std::stack<T>
{
private:
	/* data */

protected:
	/* data */

public:
	MutantStack(/* args */) // constructor
		: std::stack<T>::stack()
	{
	}
	~MutantStack() // destructor
	{
	}
	MutantStack(const MutantStack &obj) // copie constructor
		: std::stack<T>::stack(obj)
	{
	}
	MutantStack &operator=(const MutantStack &x) // assignation constructor
	{
		return (std::stack<T>::operator=(x));
	}

	class iterator
	{
	private:
		MutantStack<T> & __stack;
		void *__obj;

	public:
		iterator(MutantStack<T> & stak, void *o)
			:__stack(stak),  __obj(o)
		{
		}

		~iterator()
		{
		}

		void *getvalue() const
		{
			return (this->__obj);
		}

		MutantStack<T> & getstack() const
		{
			return (this->__stack);
		}

		iterator(const MutantStack<T>::iterator &obj)
		: __stack(obj.getstack()), __obj(obj.getvalue())
		{
		}

		iterator &operator=(const MutantStack<T>::iterator &x) // assignation constructor
		{
			this->__obj = x.getvalue();
			this->__stack = x.getstack();
			return (*this);
		}

		bool operator==(const MutantStack<T>::iterator &x) const
		{
			return (this->__obj == x.getvalue());
		}

		bool operator!=(const MutantStack<T>::iterator &x) const
		{
			return (this->__obj != x.getvalue());
		}

		MutantStack<T>::iterator &operator++()   // pré-incrémentation
		{
			MutantStack<T> tempo;
			void * ret = 0;

			while ((void *)&(this->__stack.top()) != this->__obj)
			{
				tempo.push(this->__stack.top());
				this->__stack.pop();
			}
			tempo.push(this->__stack.top());
			this->__stack.pop();
			ret = (void *)&(this->__stack.top());
			while (tempo.size())
			{
				this->__stack.push(tempo.top());
				tempo.pop();
			}
			this->__obj = ret;
			return (*this);
		}
		
		MutantStack<T>::iterator &operator--()   // pré-décrémentation
		{
			MutantStack<T> tempo;
			void * ret = 0;

			while ((void *)&(this->__stack.top()) != this->__obj)
			{
				tempo.push(this->__stack.top());
				this->__stack.pop();
			}
			this->__stack.push(tempo.top());
			tempo.pop();
			ret = (void *)&(this->__stack.top());
			while (tempo.size())
			{
				this->__stack.push(tempo.top());
				tempo.pop();
			}
			this->__obj = ret;
			return (*this);
		}

		MutantStack<T>::iterator operator++(int) // post-incrémentation
		{
			MutantStack<T> tempo;
			void * ret = 0;
			MutantStack<T>::iterator neew(this->__stack, this->__obj);

			while ((void *)&(this->__stack.top()) != this->__obj)
			{
				tempo.push(this->__stack.top());
				this->__stack.pop();
			}
			tempo.push(this->__stack.top());
			this->__stack.pop();
			ret = (void *)&(this->__stack.top());
			while (tempo.size())
			{
				this->__stack.push(tempo.top());
				tempo.pop();
			}
			this->__obj = ret;
			return (neew);
		}
		
		MutantStack<T>::iterator operator--(int) // post-décrémentation
		{
			MutantStack<T> tempo;
			void * ret = 0;
			MutantStack<T>::iterator neew(this->__stack, this->__obj);

			while ((void *)&(this->__stack.top()) != this->__obj)
			{
				tempo.push(this->__stack.top());
				this->__stack.pop();
			}
			this->__stack.push(tempo.top());
			tempo.pop();
			ret = (void *)&(this->__stack.top());
			while (tempo.size())
			{
				this->__stack.push(tempo.top());
				tempo.pop();
			}
			this->__obj = ret;
			return (neew);
		}
		T &operator*(void) const
    	{
      	  return (*((T *)(this->__obj)));
		}
	};

	MutantStack<T>::iterator begin()
	{
		MutantStack<T>::iterator ret(*this,(void *)&(this->top()));
		return (ret);
	}

	MutantStack<T>::iterator end()
	{
		MutantStack<T> tempo;

		while (this->size() - 1)
		{
			tempo.push(this->top());
			this->pop();
		}
		MutantStack<T>::iterator ret(*this,&(this->top()));
		while (tempo.size())
		{
			this->push(tempo.top());
			tempo.pop();
		}
		return (ret);
	}
};
#endif
