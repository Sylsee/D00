/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:00:07 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/24 17:02:37 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for (int i = 1; i < argc; i++) {
            for (int j = 0; argv[i][j]; j++) {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    std::cout << toupper(argv[i][j]);
                else
                    std::cout << argv[i][j];
            }
        }
		std::cout << std::endl;
    }
    return (0);
}