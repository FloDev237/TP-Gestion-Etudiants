#include "etudiant.h"
#include <stdio.h>
#include <string.h>

// Afficher le menu
void afficherMenu() {
    printf("\n.............................................\n");
    printf(".       MENU DE GESTION DES ETUDIANTS       .\n");
    printf(".............................................\n");
    printf(".  1.  Enregistrer un nouvel etudiant       .\n");
    printf(".  2.  Modifier les informations            .\n");
    printf(".  3.  Rechercher par matricule             .\n");
    printf(".  4.  Supprimer un etudiant                .\n");
    printf(".  5.  Trier par ordre alphabetique         .\n");
    printf(".  6.  Rechercher par dichotomique          .\n");
    printf(".  7.  Calculer l'age d'un etudiant         .\n");
    printf(".  8.  Trier par filiere                    .\n");
    printf(".  9.  Afficher la liste des etudiants      .\n");
    printf(".  0.  Quitter l'application                .\n");
    printf(".............................................\n");
}

// Enregistrer un nouvel étudiant
// Afficher un étudiant
// Afficher tous les étudiants
// Modifier un étudiant (avec pointeurs comme demandé)
// Rechercher par matricule
// Calculer l'âge
// Les autres fonctions (à implémenter par ton équipe)
// trier par ordre alphabétique
void trierAlphabetique(Etudiant etudiants[], int nbEtudiants) {
Etudiant temp; 
for (int i = 0; i < nbEtudiants - 1; i++) {
    for (int j = i + 1; j < nbEtudiants; j++) {
        if (strcmp(etudiants[i].nom, etudiants[j].nom) > 0) {
            temp = etudiants[i];
            etudiants[i] = etudiants[j];
            etudiants[j] = temp;
        }
    }
}
}
// Rechercher par dichotomique
int recherche_dichotomique(Etudiant *liste, int taille, const char *matricule_recherche) {
    int gauche = 0;
    int droite = taille - 1;    

    while (gauche <= droite) {
        int milieu = (gauche + droite) / 2;
        int cmp = strcmp(liste[milieu].matricule, matricule_recherche);
        if (cmp == 0) {
            return milieu; // Trouvé
        } else if (cmp < 0) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

}