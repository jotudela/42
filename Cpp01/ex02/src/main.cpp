/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:23:09 by jojo              #+#    #+#             */
/*   Updated: 2025/03/20 10:07:35 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string brain("HI THIS IS BRAIN");
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "Memory address: " << &brain << std::endl;
    std::cout << "Memory address: " << stringPTR << std::endl;
    std::cout << "Memory address: " << &stringREF << std::endl;

    std::cout << "Value: " << brain << std::endl;
    std::cout << "Value: " << *stringPTR << std::endl;
    std::cout << "Value: " << stringREF << std::endl;
    
    return 0;
}
