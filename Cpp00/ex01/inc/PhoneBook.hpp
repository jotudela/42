/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:36:53 by jojo              #+#    #+#             */
/*   Updated: 2025/03/18 13:48:15 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;
    public:
        PhoneBook();
        void ft_add();
        void ft_search();
        std::string truncate(const std::string& str);
        void print_contact(int index);
};

void    ft_exit(void);

#endif