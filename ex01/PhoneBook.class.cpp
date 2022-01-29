/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:25:38 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/29 16:25:38 by spoliart         ###   ########.fr       */
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

void	PhoneBook::addContact( void )
{
	int	index = PhoneBook::_nbContact % 8;

	this->contact[index].newContact(index);

	PhoneBook::_nbContact += 1;
	std::cout << "Contact n°" << index + 1 << std::endl;
}

void	format( std::string str, bool print_pipe = true )
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

void	PhoneBook::searchContact( void ) const
{
	if (PhoneBook::_nbContact == 0) {
		std::cout << "Add somes contact before searching for them" << std::endl;
		return ;
	}

	for (int i = 0; i < 8; i++) {
		if (this->contact[i].isEmpty() == false) {
			std::cout << std::setfill(' ') << std::setw(10);
			std::cout << this->contact[i].getIndex() << "|";
			format(this->contact[i].getFirstName());
			format(this->contact[i].getLastName());
			format(this->contact[i].getNickName(), false);
		}
	}

	int			index = 0;
	std::string	s_index;

	std::cout << "Which contact would you like to see? ";
	std::getline(std::cin, s_index);
	std::stringstream intValue(s_index);
	intValue >> index;

	if (PhoneBook::_nbContact != 0 && index > 0 && index < 9
			&& this->contact[index - 1].isEmpty() == false) {
		std::cout << this->contact[index - 1].getFirstName() << std::endl;
		std::cout << this->contact[index - 1].getLastName() << std::endl;
		std::cout << this->contact[index - 1].getNickName() << std::endl;
		std::cout << this->contact[index - 1].getPhoneNumber() << std::endl;
		std::cout << this->contact[index - 1].getDarkestSecret() << std::endl;
	}
	else if (index < 1 || index > 9 || index > PhoneBook::_nbContact)
		std::cout << "The given index doesn't exists in our database" << std::endl;
	else
		std::cout << "This contact is empty" << std::endl;
}
