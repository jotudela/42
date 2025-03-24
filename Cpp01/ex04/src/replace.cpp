/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:01:09 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 10:34:40 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.hpp"

#include <iostream>
#include <fstream>
#include <string>

void replace_And_Create(const std::string& file, const std::string& str1, const std::string& str2)
{
    std::ifstream fichierLecture(file.c_str());
    if (!fichierLecture) {
        std::cerr << "Erreur d'ouverture du fichier !" << std::endl;
        return;
    }

    std::string contenu, ligne;
    while (std::getline(fichierLecture, ligne)) {
        std::string nouvelleLigne;
        size_t i = 0;

        while (i < ligne.length()) {
            if (ligne.substr(i, str1.length()) == str1) {
                nouvelleLigne += str2;
                i += str1.length();
            } else {
                nouvelleLigne += ligne[i];
                i++;
            }
        }

        contenu += nouvelleLigne + "\n";
    }
    fichierLecture.close();

    std::ofstream fichierEcriture((file + ".replace").c_str());
    if (!fichierEcriture) {
        std::cerr << "Erreur lors de l'écriture du fichier !" << std::endl;
        return;
    }
    fichierEcriture << contenu;
    fichierEcriture.close();
}