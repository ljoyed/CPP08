/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:03:46 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/08 14:25:02 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void printLines(int num)
{
    for (int i = 0; i < num; ++i)
        std::cout << std::endl;
}

int main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    int value1 = 3;
    int value2 = 6;

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    int value3 = 30;
    int value4 = 60;

    printLines(2);
    std::cout << "----- Container : VECTOR ------" << std::endl;
    std::cout << "Test 1: Element Found" << std::endl;
    try
    {
        std::vector<int>::const_iterator it = easyfind(vec, value1);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const itemNotFound& e)
    {
        std::cerr << e.what() << std::endl;
    }

    printLines(2);
    std::cout << "Test 2: Element Not Found" << std::endl;
    try
    {
        std::vector<int>::const_iterator it = easyfind(vec, value2);
        std::cout << "Found value: " << *it << std::endl;
    } 
    catch (const itemNotFound& e)
    {
        std::cerr << e.what() << std::endl;
    }

    printLines(3);
    std::cout << "----- Container : LIST ------" << std::endl;
    std::cout << "Test 3: Element Found" << std::endl;
    try
    {
        std::list<int>::const_iterator it = easyfind(lst, value3);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const itemNotFound& e)
    {
        std::cerr << e.what() << std::endl;
    }

    printLines(2);
    std::cout << "Test 4: Element Not Found" << std::endl;
    try
    {
        std::list<int>::const_iterator it = easyfind(lst, value4);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const itemNotFound& e)
    {
        std::cerr << e.what() << std::endl;
    }

    printLines(2);
    return 0;
}
