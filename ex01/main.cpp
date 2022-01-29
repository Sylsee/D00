/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:53:59 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/29 15:51:59 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string	action;
	PhoneBook	phoneBook;

	while (1)
	{
		std::cout << "Input: ";
		std::getline(std::cin, action);
		if (action.compare("EXIT") == 0)
			break;
		else if (action.compare("ADD") == 0)
			phoneBook.addContact();
		else if (action.compare("SEARCH") == 0)
			phoneBook.searchContact();
	}
	return (0);
}
