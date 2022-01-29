/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:12:58 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/29 16:14:09 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
{
	return ;
}

Contact::~Contact( void )
{
	return ;
}

void	getInfo(std::string print, std::string &str)
{
	std::cout << print << ": ";
	std::getline(std::cin, str);
}

void	Contact::newContact( int index )
{
	this->_index = index + 1;
	getInfo("First name", this->_firstName);
	getInfo("Last name", this->_lastName);
	getInfo("Nick name", this->_nickName);
	getInfo("Phone number", this->_phoneNumber);
	getInfo("Darkest secret", this->_darkestSecret);
}

bool	Contact::isEmpty( void ) const
{
	return (this->_firstName.empty() && this->_lastName.empty()
			&& this->_nickName.empty() && this->_phoneNumber.empty()
			&& this->_darkestSecret.empty());
}

int			Contact::getIndex( void ) const
{
	return this->_index;
}

std::string	Contact::getFirstName( void ) const
{
	return this->_firstName;
}

std::string	Contact::getLastName( void ) const
{
	return this->_lastName;
}

std::string	Contact::getNickName( void ) const
{
	return this->_nickName;
}

std::string	Contact::getPhoneNumber( void ) const
{
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret( void ) const
{
	return this->_darkestSecret;
}
