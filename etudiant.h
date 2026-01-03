#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définitions des constantes
#define MAX_ETUDIANTS 100
#define MAX_NOM 50
#define MAX_PRENOM 50
#define MAX_MATRICULE 15
#define MAX_FILIERE 50
#define MAX_REGION 30
#define MAX_DEPARTEMENT 20

// Énumération pour le sexe
typedef enum {
    MASCULIN,
    FEMININ
} Sexe;

// Énumération pour le département
typedef enum {
    INFOTEL,
    GENIE_CIVIL
} Departement;

// Énumération pour la filière
typedef enum {
    CRYPTOGRAPHIE_SECURITE,
    DATA_SCIENCE,
    GENIE_LOGICIEL,
    RESEAU_TELECOM,
    ROBOTIQUE_ET_SYSTEMES_EMBARQUES
} Filiere;

// Énumération pour la région
typedef enum {
    EXTREME_NORD,
    NORD,
    ADAMAOUA,
    EST,
    SUD,
    LITTORAL,
    CENTRE,
    OUEST,
    SUD_OUEST,
    NORD_OUEST
} Region;

// Structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure principale Étudiant
typedef struct {
    char matricule[MAX_MATRICULE];
    char nom[MAX_NOM];
    char prenom[MAX_PRENOM];
    Date date_naissance;
    Sexe sexe;
    Departement departement;
    Filiere filiere;
    Region region;
} Etudiant;

void viderBuffer();
int calculerAge(Date date_naissance);
// Fonctions pour afficher les enums
void afficherSexe(Sexe s);
void afficherDepartement(Departement d);
void afficherFiliere(Filiere f);
void afficherRegion(Region r);

// Fonctions pour saisir les enums
Sexe saisirSexe();
Departement saisirDepartement();
Filiere saisirFiliere();
Region saisirRegion();

// Prototypes des fonctions
void afficherMenu();
void enregistrerEtudiant(Etudiant etudiants[], int *index, int max);
void afficherEtudiant(Etudiant e);
void afficherTousEtudiants(Etudiant etudiants[], int nbEtudiants);
void modifierEtudiant(Etudiant *etudiant);
int rechercherParMatricule(Etudiant etudiants[], int nbEtudiants, char matricule[]);
void supprimerEtudiant(Etudiant etudiants[], int *nbEtudiants, char matricule[]);
void trierAlphabetique(Etudiant etudiants[], int nbEtudiants);
int rechercherDichotomique(Etudiant etudiants[], int nbEtudiants, char nom[]);
void trierParFiliere(Etudiant etudiants[], int nbEtudiants);

#endif
