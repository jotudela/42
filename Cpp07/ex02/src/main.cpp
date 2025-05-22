#include "../inc/Array.hpp"

int main() {
    try {
        // Construction vide
        Array<int> a;
        std::cout << "a.size() = " << a.size() << std::endl;

        // Construction avec taille
        Array<int> b(5);
        std::cout << "b.size() = " << b.size() << std::endl;

        // Modification des éléments
        for (std::size_t i = 0; i < b.size(); ++i) {
            b[i] = static_cast<int>(i * 10);
        }

        // Affichage des éléments
        std::cout << "Contenu de b : ";
        for (std::size_t i = 0; i < b.size(); ++i) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;

        // Test de la copie
        Array<int> c = b; // constructeur de copie
        std::cout << "c (copie de b) avant modification : ";
        for (std::size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << " ";
        }
        std::cout << std::endl;

        // Modifier b et vérifier que c ne change pas
        b[0] = 999;
        std::cout << "b[0] = " << b[0] << ", c[0] = " << c[0] << std::endl;

        // Affectation
        Array<int> d;
        d = c; // opérateur d'affectation
        std::cout << "d (après affectation de c) : ";
        for (std::size_t i = 0; i < d.size(); ++i) {
            std::cout << d[i] << " ";
        }
        std::cout << std::endl;

        // Test exception : accès hors bornes
        std::cout << "Tentative d'accès à un index invalide..." << std::endl;
        std::cout << b[100] << std::endl; // devrait lancer une exception

    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    return 0;
}