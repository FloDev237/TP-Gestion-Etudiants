#ifndef ETUDIANT_H
#define ETUDIANT_H

// Définitions des constantes
#define MAX_ETUDIANTS 1000
#define MAX_NOM 50
#define MAX_PRENOM 50
#define MAX_MATRICULE 15

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
    DATA_SCIENCE,
    CRYPTOGRAPHIE_SECURITE,
    RESEAU_TELECOM,
    ROBOTIQUE,
    GENIE_LOGICIEL
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

// Prototypes des fonctions
void afficherMenu();
void enregistrerEtudiant(Etudiant *etudiant);
void modifierEtudiant(Etudiant *etudiant);
int rechercherParMatricule(Etudiant etudiants[], int nbEtudiants, char matricule[]);
void supprimerEtudiant(Etudiant etudiants[], int *nbEtudiants, int index);
void trierAlphabetique(Etudiant etudiants[], int nbEtudiants);
int rechercherDichotomique(Etudiant etudiants[], int nbEtudiants, char nom[]);
int calculerAge(Date date_naissance);
void trierParFiliere(Etudiant etudiants[], int nbEtudiants);
void afficherListeEtudiants(Etudiant etudiants[], int nbEtudiants);

#endif
