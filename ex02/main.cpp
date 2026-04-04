/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnemmass <hnemmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:51:11 by hnemmass          #+#    #+#             */
/*   Updated: 2026/04/04 15:42:05 by hnemmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Generate.hpp"
#include "Identify.hpp"

int main()
{
	std::srand(time(0));

	for (int i = 0; i < 3; i++)
	{
		Base *b = generate();
		Base &c = *b;
		identify(b);
		identify(c);
		delete b;
	}
}