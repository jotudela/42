/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:36:53 by jojo              #+#    #+#             */
/*   Updated: 2025/03/17 15:45:13 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

class PhoneBook
{
    private:
        std::string a_tab[7];
    public:
        PhoneBook();
        ~PhoneBook();
        void    ft_add(std::string tab[7]);
        void    ft_search(void);
};

void    ft_exit(void);

#endif