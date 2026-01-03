#include "etudiant.h"
#include <ctype.h>
#include <time.h>

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

// Fonction pour vider le buffer d'entrée
void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// ==================== FONCTIONS POUR LES ENUMS ====================

// Afficher un enum Sexe
void afficherSexe(Sexe s) {
    switch(s) {
        case MASCULIN:
          printf("Masculin\t"); break;
        case FEMININ:
          printf("Feminin\t"); break;
    }
}

// Afficher un enum Département
void afficherDepartement(Departement d) {
    switch(d) {
        case INFOTEL: printf("INFOTEL\t"); break;
        case GENIE_CIVIL: printf("Genie Civil\t"); break;
    }
}

// Afficher un enum Filière
void afficherFiliere(Filiere f) {
    switch(f) {
        case DATA_SCIENCE: printf("Data Science\t"); break;
        case CRYPTOGRAPHIE_SECURITE:
          printf("Cryptographie et Securite\t");
          break;
        case RESEAU_TELECOM: printf("Reseau et Telecommunication\t"); break;
        case ROBOTIQUE_ET_SYSTEMES_EMBARQUES: printf("Robotique et systemes embarques\t");break;
        case GENIE_LOGICIEL: printf("Genie Logiciel\t"); break;
    }
}

// Afficher un enum Région
void afficherRegion(Region r) {
    switch(r) {
        case EXTREME_NORD: printf("Extreme-Nord\t"); break;
        case NORD: printf("Nord\t"); break;
        case ADAMAOUA: printf("Adamaoua\t"); break;
        case EST: printf("Est\t"); break;
        case SUD: printf("Sud\t"); break;
        case LITTORAL: printf("Littoral\t"); break;
        case CENTRE: printf("Centre\t"); break;
        case OUEST: printf("Ouest\t"); break;
        case SUD_OUEST: printf("Sud-Ouest\t"); break;
        case NORD_OUEST: printf("Nord-Ouest\t"); break;
    }
}

// ==================== FONCTIONS DE SAISIE POUR LES ENUMS ====================

Sexe saisirSexe() {
    char choix;
    do {
        printf("Sexe (M/F): ");
        scanf(" %c", &choix);
        viderBuffer();
        choix = toupper(choix);
    } while (choix != 'M' && choix != 'F');
    
    return (choix == 'M') ? MASCULIN : FEMININ;
}

Departement saisirDepartement() {
    int choix;
    do {
        printf("Departement (0: INFOTEL, 1: Genie Civil): ");
        scanf("%d", &choix);
        viderBuffer();
    } while (choix != 0 && choix != 1);
    
    return (choix == 0) ? INFOTEL : GENIE_CIVIL;
}

Filiere saisirFiliere() {
    int choix;
    printf("\n--- FILIERES ---\n");
    printf("0: Data Science\n");
    printf("1: Cryptographie et Securite\n");
    printf("2: Reseau et Telecom\n");
    printf("3: Robotique et systemes embarques\n");
    printf("4: Genie Logiciel\n");
    
    do {
        printf("Votre choix (0-4): ");
        scanf("%d", &choix);
        viderBuffer();
    } while (choix < 0 || choix > 4);
    
    return (Filiere)choix;
}

Region saisirRegion() {
    int choix;
    printf("\n--- REGIONS ---\n");
    printf("0: Extreme-Nord\n");
    printf("1: Nord\n");
    printf("2: Adamaoua\n");
    printf("3: Est\n");
    printf("4: Sud\n");
    printf("5: Littoral\n");
    printf("6: Centre\n");
    printf("7: Ouest\n");
    printf("8: Sud-Ouest\n");
    printf("9: Nord-Ouest\n");
    
    do {
        printf("Votre choix (0-9): ");
        scanf("%d", &choix);
        viderBuffer();
    } while (choix < 0 || choix > 9);
    
    return (Region)choix;
}


// Fonction d'enregistrement d'un étudiant

void enregistrerEtudiant(Etudiant etudiants[], int *index, int max) {
    if (*index >= max) {
        printf("Capacité maximale atteinte!\n");
        return;
    }
    
    Etudiant *e = &etudiants[*index];
    
    printf("\n=== ENREGISTREMENT ETUDIANT ===\n");
    
    // Matricule
    printf("Matricule: ");
    scanf("%s", e->matricule);
    viderBuffer();
    
    // Nom
    printf("Nom: ");
    fgets(e->nom, MAX_NOM, stdin);
    e->nom[strcspn(e->nom, "\n")] = '\0';
    
    // Prénom
    printf("Prenom: ");
    fgets(e->prenom, MAX_PRENOM, stdin);
    e->prenom[strcspn(e->prenom, "\n")] = '\0';
    
    // Date de naissance
    printf("Date de naissance (JJ MM AAAA): ");
    scanf("%d %d %d", &e->date_naissance.jour, &e->date_naissance.mois, &e->date_naissance.annee);
    viderBuffer();
    
    // Sexe (enum)
    e->sexe = saisirSexe();
    
    // Département (enum)
    e->departement = saisirDepartement();
    
    // Filière (enum)
    e->filiere = saisirFiliere();
    
    // Région (enum)
    e->region = saisirRegion();
    
    (*index)++;
    printf("Etudiant enregistre!\n");
}

// Afficher un étudiant
void afficherEtudiant(Etudiant e) {
    printf("Matricule : %s\n", e.matricule);
    printf("Nom : %s\n", e.nom);
    printf("Prenom : %s\n", e.prenom);
    printf("Date naissance : %02d/%02d/%d\n", e.date_naissance.jour, 
                                              e.date_naissance.mois, 
                                              e.date_naissance.annee);
    printf("Sexe: ");
    afficherSexe(e.sexe);
    printf("\nDepartement: ");
    afficherDepartement(e.departement);
    printf("\nFiliere: ");
    afficherFiliere(e.filiere);
    printf("\nRegion: ");
    afficherRegion(e.region);
    printf("\nAge: %d ans\n", calculerAge(e.date_naissance));
}

// Afficher tous les étudiants

void afficherTousEtudiants(Etudiant etudiants[], int nbEtudiants) {
    if (nbEtudiants == 0) {
        printf(" Aucun etudiant enregistre.\n");
        return;
    }
    
    printf("\n=== LISTE DES ETUDIANTS (%d) ===\n", nbEtudiants);
    for (int i = 0; i < nbEtudiants; i++) {
        printf("%d. [%s]    %s  %s  %02d/%02d/%d",  
               i + 1, 
               etudiants[i].matricule,
               etudiants[i].nom, 
               etudiants[i].prenom,
               etudiants[i].date_naissance.jour,
               etudiants[i].date_naissance.mois,
               etudiants[i].date_naissance.annee);
                afficherRegion(etudiants[i].region);
                afficherSexe(etudiants[i].sexe);
                afficherFiliere(etudiants[i].filiere);
                afficherDepartement(etudiants[i].departement);
                printf("\n");
    }

 }
// Modifier un étudiant (avec pointeurs comme demandé)
   void modifierEtudiant(Etudiant *etudiant) {
    printf("\n=== MODIFICATION ETUDIANT ===\n");
    printf("Etudiant: %s %s\n", etudiant->nom, etudiant->prenom);
    
    char temp[100];
    
    printf("Nouveau nom (actuel: %s): ", etudiant->nom);
    fgets(temp, sizeof(temp), stdin);
    if (strlen(temp) > 1) {
        temp[strcspn(temp, "\n")] = '\0';
        strcpy(etudiant->nom, temp);
    }
    
    printf("Modification terminee.\n");
}

// Rechercher par matricule
int rechercherParMatricule(Etudiant etudiants[], int nbEtudiants, char matricule[]) {
    for (int i = 0; i < nbEtudiants; i++) {
        if (strcmp(etudiants[i].matricule, matricule) == 0) {
            return i;
        }
    }
    return -1;
}

// Calculer l'âge
int calculerAge(Date date_naissance) {
    // Pour simplifier, on suppose l'année actuelle est 2025
    return 2025 - date_naissance.annee;
}

// Les autres fonctions (à implémenter par le groupe)
void supprimerEtudiant(Etudiant etudiants[], int *nbEtudiants, char matricule[]) {
    
    printf("Fonction supprimerEtudiant - A implementer\n");
}

void trierAlphabetique(Etudiant etudiants[], int nbEtudiants) {
   
    printf("Fonction trierAlphabetique - A implementer\n");
}

int rechercherDichotomique(Etudiant etudiants[], int nbEtudiants, char nom[]) {
    
    printf("Fonction rechercherDichotomique - A implementer\n");
    return -1;
}

//Tri par filiere
void trierParFiliere(Etudiant etudiants[], int nbEtudiants) {
    Etudiant temp;
    for (int i = 0; i < nbEtudiants; i++) {
        for (int j = i; j < nbEtudiants; j++) {
            if (etudiants[i].filiere > etudiants[j].filiere) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
}
// Rechercher par matricule


