/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:39:22 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/29 15:52:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <sstream>
# include "Contact.hpp"

class	PhoneBook {

public:

	Contact	contact[8];

	PhoneBook( void );
	~PhoneBook( void );

	void	addContact( void );
	void	searchContact( void ) const;

private:

	static int	_nbContact;

};

#endif
