/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:03:46 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/11 17:21:29 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void printLines(int num)
{
    for (int i = 0; i < num; ++i)
        std::cout << std::endl;
}

int main()
{
	MutantStack<int> mstack;
	printLines(2);
	std::cout << "    Mutant Stack Test" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "Pushing 100 onto the stack" << std::endl;
	mstack.push(100);
	std::cout << "Pushing 200 onto the stack" << std::endl;
	mstack.push(200);
	std::cout << "Pushing 300 onto the stack" << std::endl;
	mstack.push(300);
	std::cout << "Pushing 400 onto the stack" << std::endl;
	mstack.push(400);
	std::cout << "Pushing 500 onto the stack" << std::endl;
	mstack.push(500);
	printLines(1);
	std::cout << "Stack top                       : " << mstack.top() << std::endl;
	std::cout << "Stack size                      : " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "First element during iteration  : " << *it << std::endl;
	std::cout << "Last element during iteration   : " << mstack.top() << std::endl;
	++it;
    std::cout << "After incrementing the iterator : " << *it << std::endl;
	--it;
    std::cout << "After decrementing the iterator : " << *it << std::endl;
    std::cout << "Iterating over the stack........." << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	printLines(3);
	std::cout << "Using the copy constructor..." << std::endl;
	std::stack<int> s(mstack);
    std::cout << "s.top() : " << s.top() << std::endl;
    std::cout << "s.size() : " << s.size() << std::endl;
    printLines(3);
    
    std::list<int> lst;
	std::cout << "        List Test" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "Pushing 100 onto the list" << std::endl;
	lst.push_back(100);
	std::cout << "Pushing 200 onto the list" << std::endl;
	lst.push_back(200);
	std::cout << "Pushing 300 onto the list" << std::endl;
	lst.push_back(300);
	std::cout << "Pushing 400 onto the list" << std::endl;
	lst.push_back(400);
	std::cout << "Pushing 500 onto the list" << std::endl;
	lst.push_back(500);
	printLines(1);
	std::cout << "List top                        : " << lst.back() << std::endl;
	std::cout << "List size                       : " << lst.size() << std::endl;
	std::list<int>::iterator l_it = lst.begin();
	std::list<int>::iterator l_ite = lst.end();
	std::cout << "First element during iteration  : " << *l_it << std::endl;
	std::cout << "Last element during iteration   : " << lst.back() << std::endl;
	++l_it;
    std::cout << "After incrementing the iterator : " << *l_it << std::endl;
	--l_it;
    std::cout << "After decrementing the iterator : " << *l_it << std::endl;
    std::cout << "Iterating over the list.........." << std::endl;
	while (l_it != l_ite)
	{
		std::cout << *l_it << std::endl;
		++l_it;
	}
	printLines(2);
	return 0;

}