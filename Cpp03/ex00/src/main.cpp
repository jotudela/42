/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:53:03 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 13:34:22 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

using std::string;
using std::cout;
using std::endl;

int main(void){
    
    ClapTrap clap1("CL4P-TP");
    ClapTrap clap2("FR4G-TP");

    clap1.attack("FR4G-TP");
    clap2.takeDamage(0);

    clap2.beRepaired(0);
    clap2.attack("CL4P-TP");
    clap1.takeDamage(0);
    
    clap1.beRepaired(0);
    clap1.attack("FR4G-TP");
    clap2.takeDamage(0);
}