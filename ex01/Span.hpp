/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:08:34 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/10 19:10:48 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <limits>
#include <iterator>
#include <ctime>
#include <cstdlib>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _store;
        Span();
    
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span &origObj);
        Span& operator=(const Span &origObj);
        void addNumber(unsigned int num);
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        std::vector<int>::iterator begin();
        std::vector<int>::iterator end();
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);

    class noCapacityError : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Container has no more capacity!");
            }
    };

    class noSpanFound : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Not enough elements in the container to calculate their span!");
            }
    };



};

#endif