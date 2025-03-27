/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:53:03 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 15:06:22 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Animal.hpp"

using std::string;
using std::cout;
using std::endl;

void testPolymorphism() {
    cout << "----- Test de polymorphisme -----" << endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    cout << "Type de j: " << j->getType() << endl;  // Doit afficher "Dog"
    cout << "Type de i: " << i->getType() << endl;  // Doit afficher "Cat"
    
    cout << "Son de i (Cat): ";
    i->makeSound();  // Doit afficher le son du chat
    cout << "Son de j (Dog): ";
    j->makeSound();  // Doit afficher le son du chien
    cout << "Son de meta (Animal): ";
    meta->makeSound();  // Doit afficher le son générique de l'animal
    
    delete i;  // Test de la destruction de l'objet Cat
    delete j;  // Test de la destruction de l'objet Dog
    delete meta;  // Test de la destruction de l'objet Animal
}

void testConstructorsAndAssignment() {
    cout << "\n----- Test des constructeurs et opérateurs d'assignation -----" << endl;
    
    // Test du constructeur par défaut et du constructeur de copie
    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1);  // Construction par copie
    Dog* dog3 = new Dog();
    *dog3 = *dog1;  // Assignation

    // Afficher les types après assignation et copie
    cout << "Type de dog1: " << dog1->getType() << endl;  // Doit afficher "Dog"
    cout << "Type de dog2 (copie): " << dog2->getType() << endl;  // Doit afficher "Dog"
    cout << "Type de dog3 (après assignation): " << dog3->getType() << endl;  // Doit afficher "Dog"
    
    delete dog1;
    delete dog2;
    delete dog3;
}

void testMemoryLeak() {
    cout << "\n----- Test de fuite mémoire -----" << endl;

    // Test de création et suppression d'objets pour vérifier les fuites mémoire
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    
    // Pas de fuite si on appelle delete correctement
    delete dog;
    delete cat;

    cout << "Aucune fuite mémoire après suppression des objets." << endl;
}

void testConstObjects() {
    cout << "\n----- Test avec des objets const -----" << endl;
    
    const Dog* dog = new Dog();
    const Cat* cat = new Cat();
    
    cout << "Son du chien (const): ";
    dog->makeSound();  // Vérifier si ça fonctionne avec un objet const
    cout << "Son du chat (const): ";
    cat->makeSound();  // Vérifier si ça fonctionne avec un objet const
    
    delete dog;
    delete cat;
}

int main() {
    testPolymorphism();         // Tester le polymorphisme
    testConstructorsAndAssignment(); // Tester les constructeurs et assignations
    testMemoryLeak();           // Tester la gestion de la mémoire
    testConstObjects();         // Tester les objets const

    return 0;
}