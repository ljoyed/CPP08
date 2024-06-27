/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:08:34 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/11 17:22:39 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <vector>
#include <list>
#include <iostream> 


template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
	 	MutantStack(){}
        ~MutantStack(){}
    	MutantStack(const MutantStack& origObj) : std::stack<T, Container>(origObj) {}
        MutantStack& operator=(const MutantStack& origObj)
    	{
			if (this != &origObj)
			{
				std::stack<T, Container>::operator=(origObj);
			}
			return *this;
    	}

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};

#endif