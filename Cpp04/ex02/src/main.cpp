/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:59:13 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 16:26:32 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

using std::cout;
using std::endl;

void testBasicCreation() {
    cout << "\n===== TEST 1: Création et destruction basique =====" << endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    cout << "Type de dog: " << dog->getType() << endl;
    cout << "Type de cat: " << cat->getType() << endl;
    dog->makeSound();
    cat->makeSound();
    delete dog;
    delete cat;
}

void testArray() {
    cout << "\n===== TEST 2: Création et destruction d'un tableau d'animaux =====" << endl;
    int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; i++) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < size; i++) {
        delete animals[i];
    }
}

void testDeepCopy() {
    cout << "\n===== TEST 3: Copie profonde (constructeur de copie) =====" << endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Manger un os");
    dog1.getBrain()->setIdea(1, "Courir après le chat");

    Dog dog2(dog1); // Utilisation du constructeur de copie
    cout << "Idée du dog1[0]: " << dog1.getBrain()->getIdea(0) << endl;
    cout << "Idée du dog2[0]: " << dog2.getBrain()->getIdea(0) << endl;

    dog2.getBrain()->setIdea(0, "Dormir toute la journée");

    cout << "Après modification de dog2:" << endl;
    cout << "Idée du dog1[0]: " << dog1.getBrain()->getIdea(0) << endl;
    cout << "Idée du dog2[0]: " << dog2.getBrain()->getIdea(0) << endl;
}

void testAssignmentOperator() {
    cout << "\n===== TEST 4: Opérateur d'assignation =====" << endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Jouer avec une balle");

    Dog dog2;
    dog2 = dog1; // Utilisation de l'opérateur d'assignation

    cout << "Idée du dog1[0]: " << dog1.getBrain()->getIdea(0) << endl;
    cout << "Idée du dog2[0]: " << dog2.getBrain()->getIdea(0) << endl;

    dog2.getBrain()->setIdea(0, "Attraper un frisbee");

    cout << "Après modification de dog2:" << endl;
    cout << "Idée du dog1[0]: " << dog1.getBrain()->getIdea(0) << endl;
    cout << "Idée du dog2[0]: " << dog2.getBrain()->getIdea(0) << endl;
}

void testPolymorphism() {
    cout << "\n===== TEST 5: Polymorphisme =====" << endl;
    Animal* a = new Dog();
    Animal* b = new Cat();

    cout << "Animal a (dog) fait un son: ";
    a->makeSound();
    cout << "Animal b (cat) fait un son: ";
    b->makeSound();

    delete a;
    delete b;
}

int main() {
    testBasicCreation();
    testArray();
    testDeepCopy();
    testAssignmentOperator();
    testPolymorphism();

    cout << "\n===== FIN DES TESTS =====" << endl;
    return 0;
}