/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnemmass <hnemmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:12:54 by hnemmass          #+#    #+#             */
/*   Updated: 2026/05/14 15:26:21 by hnemmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data d;
	Data *t = &d;
	
	std::cout << t << std::endl;
	std::cout << t->a << "---" << t->b << std::endl;
	
	uintptr_t test = Serializer::serialize(t);
	Data *test1 = Serializer::deserialize(test);
	
	std::cout << test1 << std::endl;
	std::cout << test1->a <<  "---" << test1->b << std::endl;
}