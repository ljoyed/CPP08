/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:08:34 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/08 14:17:40 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>

class itemNotFound : public std::exception
{
    private:
        std::string message;
    public:
        itemNotFound(int value)
        {
            std::ostringstream oss;
            oss << value << " not found in container";
            message = oss.str();
        }
        
        virtual const char* what() const throw()
        {
            return message.c_str();
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
    {
        throw (itemNotFound(value));
    }
    return it;
}

#endif