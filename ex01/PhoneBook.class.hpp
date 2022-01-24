/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:39:22 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/24 23:52:28 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <sstream>

class	PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	static void	addContact(PhoneBook &contact);
	static void	searchContact(PhoneBook *contact);

	static int	getNbContact(void);
	
	bool	isEmpty(void);

private:

	static int	_nbContact;

	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif
