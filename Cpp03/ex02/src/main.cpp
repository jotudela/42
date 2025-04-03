/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:53:03 by jotudela          #+#    #+#             */
/*   Updated: 2025/04/03 14:56:06 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"  // Inclure ScavTrap pour tester ScavTrap
#include "../inc/FragTrap.hpp"  // Inclure FragTrap pour tester FragTrap

using std::cout;
using std::endl;

int main() {
    std::cout << "=== Création des ScavTraps ===" << std::endl;
    ScavTrap s1("David");
    ScavTrap s2("Darius");

    std::cout << "\n=== Création des FragTraps ===" << std::endl;
    FragTrap f1("Mike");
    FragTrap f2("Tom");

    std::cout << "\n=== Test de l'attaque ScavTrap ===" << std::endl;
    s1.attack("Darius");
    s2.attack("David");

    std::cout << "\n=== Test de l'attaque FragTrap ===" << std::endl;
    f1.attack("Tom");
    f2.attack("Mike");

    std::cout << "\n=== Test de la capacité spéciale FragTrap ===" << std::endl;
    f1.highFivesGuys();
    f2.highFivesGuys();

    std::cout << "\n=== Test des copies ===" << std::endl;
    ScavTrap s3(s1);  // Test du constructeur de copie pour ScavTrap
    FragTrap f3(f1);  // Test du constructeur de copie pour FragTrap

    std::cout << "\n=== Affichage des stats ===" << std::endl;
    s1.printStats();
    cout << endl;
    s2.printStats();
    cout << endl;
    f1.printStats();
    cout << endl;
    f2.printStats();

    std::cout << "\n=== Fin du programme ===" << std::endl;
    return 0;
}
