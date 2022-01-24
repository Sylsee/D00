/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:53:59 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/24 23:18:38 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int	main(void)
{
	std::string	action;
	PhoneBook	contact[8];

	while (1)
	{
		std::cout << "Input: ";
		std::getline(std::cin, action);
		if (action.compare("EXIT") == 0)
			break;
		else if (action.compare("ADD") == 0) {
			PhoneBook::addContact(contact[PhoneBook::getNbContact()]);
		}
		else if (action.compare("SEARCH") == 0) {
			PhoneBook::searchContact(contact);
		}
	}
	return (0);
}
