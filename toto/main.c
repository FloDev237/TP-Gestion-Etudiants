#include <stdio.h>
#include "etudiant.h"
#include <stdlib.h>

int main() {
    printf("..........................................\n");
    printf("  BIENVENUE SUR NOTRE APPLICATION DE      \n");
    printf("      GESTION DES ETUDIANTS               \n");
    printf("..........................................\n\n");
    
    Etudiant etudiants[5] = { {"MAT001", "Durand", "Alice", {12, 5, 2000}, FEMININ, INFOTEL, DATA_SCIENCE, NORD}, {"MAT002", "Martin", "Jean", {23, 8, 1999}, MASCULIN, INFOTEL, DATA_SCIENCE, SUD}, {"MAT003", "Bernard", "Sophie", {7, 3, 2001}, FEMININ, INFOTEL, DATA_SCIENCE, EST}, {"MAT004", "Petit", "Luc", {15, 11, 1998}, MASCULIN, INFOTEL, DATA_SCIENCE, OUEST}, {"MAT005", "André", "Paul", {30, 1, 2002}, MASCULIN, INFOTEL, DATA_SCIENCE, NORD} };
    printf("Liste des étudiants avant le tri:\n");
    for(int i=0; i<5;i++){
        printf("Etudiant %s \t %s\n ", etudiants[i].nom,  etudiants[i].prenom);
    }
    printf("\nListe des étudiants après le tri alphabétique:\n");
    trierAlphabetique(etudiants, 5);
    for(int i=0; i<5;i++){
        printf("Etudiant %s \t %s\n ", etudiants[i].nom,  etudiants[i].prenom);
    }
    //afficherMenu();      
    // Créer le tableau d'étudiants
 }