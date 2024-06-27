/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:03:46 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/10 19:14:59 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void printLines(int num)
{
    for (int i = 0; i < num; ++i)
        std::cout << std::endl;
}

int main()
{
    try
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        Span sp = Span(10);
        std::vector<int> numbers;

        // Generate 10 random numbers
        for (int i = 0; i < 10; ++i)
        {
            numbers.push_back(std::rand() % 100000); // Random number between 0 and 99999
        }

        sp.addRange(numbers.begin(), numbers.end());
        printLines(2);
        std::cout << "Elements in the container are : ";
        for (std::vector<int>::iterator it = sp.begin(); it != sp.end(); ++it)
            std::cout << *it << " ";
        printLines(2);
        std::cout << "Shortest span between any two elements : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span between any two elements  : " << sp.longestSpan() << std::endl;
        printLines(2);
    }
    catch(const Span::noCapacityError& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const Span::noSpanFound& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
return 0;
}