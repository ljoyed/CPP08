/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:31:13 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/10 17:51:33 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _N(n)
{}

Span::Span(const Span &origObj) : _N(origObj._N), _store(origObj._store)
{}

Span& Span::operator=(const Span &origObj)
{
    if (this != &origObj)
    {
        this->_N = origObj._N;
        this->_store = origObj._store;
    }
    return (*this);
}

Span::~Span()
{}

void Span::addNumber(unsigned int num)
{
    if (_store.size() >= _N)
        throw noCapacityError();
    else
        _store.push_back(num);
}

unsigned int Span::shortestSpan(void)
{
    std::vector<int> sortedStore; //a vector to sort the original vector
    int minSpan;
    int span;

    if (_store.size() < 2)
        throw noSpanFound();

    sortedStore = _store;
    std::sort(sortedStore.begin(), sortedStore.end());

    minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedStore.size(); ++i)
    {
        span = sortedStore[i] - sortedStore[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return static_cast<unsigned int>(minSpan);
}

unsigned int Span::longestSpan(void)
{
    std::vector<int> sortedStore;
    int maxSpan;

    if (_store.size() < 2)
        throw noSpanFound();

    sortedStore = _store;
    std::sort(sortedStore.begin(), sortedStore.end());
    maxSpan = sortedStore.back() - sortedStore.front();
    return static_cast<unsigned int>(maxSpan);   
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _store.size() > _N)
    {
        throw noCapacityError();
    }
    _store.insert(_store.end(), begin, end);
}

std::vector<int>::iterator Span::begin()
{
    return _store.begin();
}
        
std::vector<int>::iterator Span::end()
{
    return _store.end();
}
