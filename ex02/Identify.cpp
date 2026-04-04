/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnemmass <hnemmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:34:31 by hnemmass          #+#    #+#             */
/*   Updated: 2026/04/03 20:06:37 by hnemmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

void identify(Base *p)
{
	if (p == NULL)
		std::cout << "NULL pointer entred to the function" << std::endl;

	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}

	if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}
	
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}

	std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(...)
	{
		try 
		{
			dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(...)
		{		
			try 
			{
				dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(...)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}