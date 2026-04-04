/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnemmass <hnemmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:21:39 by hnemmass          #+#    #+#             */
/*   Updated: 2026/04/03 18:31:35 by hnemmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Generate.hpp"

Base *generate(void)
{
	int num = std::rand() % 3;
	
	if (num == 0)
		return new A;
	else if (num == 1)
		return new B;
	else
		return new C;
}