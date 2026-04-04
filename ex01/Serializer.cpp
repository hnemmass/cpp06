/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnemmass <hnemmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:52:32 by hnemmass          #+#    #+#             */
/*   Updated: 2026/04/03 15:59:35 by hnemmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return (result);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *result = reinterpret_cast<Data*>(raw);
	return(result);
}