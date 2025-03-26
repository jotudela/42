/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:53:03 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 18:45:55 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

using std::string;
using std::cout;
using std::endl;

int main(void) {
    std::cout << "=== Création des ScavTraps ===" << std::endl;
    ScavTrap a("David");
    ScavTrap b("Darius");

    std::cout << "\n=== Test de l'attaque ===" << std::endl;
    a.attack("Darius");
    b.attack("David");

    std::cout << "\n=== Test de la copie ===" << std::endl;
    ScavTrap c(a);  // Test du constructeur de copie
    ScavTrap d("test");
    d = c;

    std::cout << "\n=== Test des dégâts et réparation ===" << std::endl;
    b.attack("David");
    a.takeDamage(a.getAttacksDamage());
    a.beRepaired(2);
    b.attack("David");
    a.takeDamage(b.getAttacksDamage());
    b.attack("David");
    a.takeDamage(b.getAttacksDamage());
    b.attack("David");
    a.takeDamage(b.getAttacksDamage());
    b.attack("David");
    a.takeDamage(b.getAttacksDamage());
    a.beRepaired(20);
    b.attack("David");
    a.takeDamage(b.getAttacksDamage());
    a.beRepaired(5);
    b.guardGate();
    a.attack("Darius");
    b.takeDamage(a.getAttacksDamage());

    std::cout << "\n=== Affichage des stats ===" << std::endl;
    a.printStats();
    cout << endl;
    b.printStats();
    cout << endl;
    c.printStats();

    std::cout << "\n=== Fin du programme ===" << std::endl;
    return 0;
}
