/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:25:38 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/25 17:04:40 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int	PhoneBook::_nbContact = 0;

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	PhoneBook::getNbContact(void)
{
	return PhoneBook::_nbContact;
}

void	getInfo(std::string print, std::string &str)
{
	std::cout << print << ": ";
	std::getline(std::cin, str);
}

void	PhoneBook::addContact(PhoneBook &contact)
{
	if (PhoneBook::_nbContact >= 8) {
		std::cout << "Sorry, your phone book is full." << std::endl;
		return ;
	}

	contact._index = PhoneBook::_nbContact + 1;
	getInfo("First name", contact._firstName);
	getInfo("Last name", contact._lastName);
	getInfo("Nick name", contact._nickName);
	getInfo("Phone number", contact._phoneNumber);
	getInfo("Darkest secret", contact._darkestSecret);

	PhoneBook::_nbContact += 1;
	std::cout << "Contact n°" << PhoneBook::_nbContact << std::endl;
}

void	truncate(std::string str, bool print_pipe = true)
{
	std::cout << std::setw(10);
	if (str.length() > 10) {
		std::cout << str.substr(0, 9) + '.';
		if (print_pipe == true)
			std::cout << '|';
		else
			std::cout << std::endl;
	}
	else if (str.length() == 10) {
		std::cout << str.substr(0, 10);
		if (print_pipe == true)
			std::cout << '|';
		else
			std::cout << std::endl;
	}
	else {
		std::cout << str;
		if (print_pipe == true)
			std::cout << '|';
		else
			std::cout << std::endl;
	}
}

bool	PhoneBook::isEmpty(void)
{
	return (this->_firstName.empty() && this->_lastName.empty()
			&& this->_nickName.empty() && this->_phoneNumber.empty()
			&& this->_darkestSecret.empty());
}

void	PhoneBook::searchContact(PhoneBook *contact)
{
	int			index = 0;
	std::string	s_index;

	if (PhoneBook::_nbContact == 0) {
		std::cout << "Add somes contact before searching for them" << std::endl;
		return ;
	}

	for (int i = 0; i < PhoneBook::_nbContact; i++) {
		if (contact[i].isEmpty() == false) {
			std::cout << std::setfill(' ') << std::setw(10);
			std::cout << contact[i]._index << "|";
			truncate(contact[i]._firstName);
			truncate(contact[i]._lastName);
			truncate(contact[i]._nickName, false);
		}
	}

	std::cout << "Which contact would you like to see? ";
	std::getline(std::cin, s_index);
	std::stringstream intValue(s_index);
	intValue >> index;
	std::cout << "index: " << index << std::endl;

	if (PhoneBook::_nbContact != 0 && index > 0 && index < PhoneBook::_nbContact + 1
			&& contact[index - 1].isEmpty() == false) {
		std::cout << contact[index - 1]._firstName << std::endl;
		std::cout << contact[index - 1]._lastName << std::endl;
		std::cout << contact[index - 1]._nickName << std::endl;
		std::cout << contact[index - 1]._phoneNumber << std::endl;
		std::cout << contact[index - 1]._darkestSecret << std::endl;
	}
	else if (PhoneBook::_nbContact == 0 || index < 1 || index > PhoneBook::_nbContact + 1)
		std::cout << "The given index doesn't exists in our database" << std::endl;
	else
		std::cout << "This contact is empty" << std::endl;
}
