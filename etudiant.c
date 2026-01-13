#include "etudiant.h"
#include <ctype.h>
#include <time.h>

// Afficher le menu
void afficherMenu() {
    // system("chcp 65001 > nul");
    printf("\n.............................................\n");
    printf(".       MENU DE GESTION DES ETUDIANTS       .\n");
    printf(".............................................\n");
    printf(".  1.  Enregistrer un nouvel étudiant       .\n");
    printf(".  2.  Modifier les informations            .\n");
    printf(".  3.  Rechercher par matricule             .\n");
    printf(".  4.  Supprimer un etudiant                .\n");
    printf(".  5.  Trier par ordre alphabetique         .\n");
    printf(".  6.  Rechercher par dichotomique          .\n");
    printf(".  7.  Calculer l'age d'un étudiant         .\n");
    printf(".  8.  Trier par filiere                    .\n");
    printf(".  9.  Afficher la liste des étudiants      .\n");
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
          printf("%-8s\t", "Masculin"); break;
        case FEMININ:
          printf("%-8s\t", "Feminin"); break;
    }
}

// Afficher un enum Département
void afficherDepartement(Departement d) {
    // system("chcp 65001 > nul");
    switch(d) {
        case INFOTEL: printf("%-11s\t", "INFOTEL"); break;
        case GENIE_CIVIL: printf("%-11s\t", "Génie Civil"); break;
    }
}

// Afficher un enum Filière
void afficherFiliere(Filiere f) {
    switch(f) {
        case DATA_SCIENCE: printf("%-35s\t","Data Science"); break;
        case CRYPTOGRAPHIE_SECURITE: printf("%-35s\t", "Cryptographie et Sécurité"); break;
        case RESEAU_TELECOM: printf("%-35s\t","Réseau et Télécommunication"); break;
        case ROBOTIQUE_ET_SYSTEMES_EMBARQUES: printf("%-35s\t","Robotique et systèmes embarqués");break;
        case GENIE_LOGICIEL: printf("%-35s\t","Génie Logiciel"); break;
    }
}

// Afficher un enum Région
void afficherRegion(Region r) {
    switch(r) {
        case EXTREME_NORD: printf("%-12s\t","Extreme-Nord"); break;
        case NORD: printf("%-12s\t","Nord"); break;
        case ADAMAOUA: printf("%-12s\t","Adamaoua"); break;
        case EST: printf("%-12s\t","Est"); break;
        case SUD: printf("%-12s\t","Sud"); break;
        case LITTORAL: printf("%-12s\t","Littoral"); break;
        case CENTRE: printf("%-12s\t","Centre"); break;
        case OUEST: printf("%-12s\t","Ouest"); break;
        case SUD_OUEST: printf("%-12s\t","Sud-Ouest"); break;
        case NORD_OUEST: printf("%-12s\t","Nord-Ouest"); break;
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
    // system("chcp 65001 > nul");
    int choix;
    do {
        printf("Departement (0: INFOTEL, 1: Génie Civil): ");
        scanf("%d", &choix);
        viderBuffer();
    } while (choix != 0 && choix != 1);
    
    return (choix == 0) ? INFOTEL : GENIE_CIVIL;
}

Filiere saisirFiliere() {
    int choix;
    printf("\n--- FILIERES ---\n");
    printf("0: Data Science\n");
    printf("1: Cryptographie et Sécurité\n");
    printf("2: Réseau et Télécommunication\n");
    printf("3: Robotique et systemès embarqués\n");
    printf("4: Génie Logiciel\n");
    
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

//fonction enregistrement de la date de naissance d'un etudiant
void LireDate(Etudiant *e) {
    Date date_naissance;
    printf("Date de naissance (JJ MM AAAA): ");
    scanf("%d %d %d", &date_naissance.jour, &date_naissance.mois,
        &date_naissance.annee);
    viderBuffer();
  // verification de la validite de la date
    if ((date_naissance.jour >= 1 && date_naissance.jour <= 31) &&
      (date_naissance.mois == 1 || date_naissance.mois == 3 ||
       date_naissance.mois == 5 || date_naissance.mois == 7 ||
       date_naissance.mois == 8 || date_naissance.mois == 10 ||
       date_naissance.mois == 12)) {
        e->date_naissance.jour = date_naissance.jour;
        e->date_naissance.mois = date_naissance.mois;
        e->date_naissance.annee = date_naissance.annee;
    } else if ((date_naissance.jour >= 1 && date_naissance.jour <= 30) &&
             (date_naissance.mois == 4 || date_naissance.mois == 6 ||
              date_naissance.mois == 9 || date_naissance.mois == 11)) {
        e->date_naissance.jour = date_naissance.jour;
        e->date_naissance.mois = date_naissance.mois;
        e->date_naissance.annee = date_naissance.annee;
    } else if ((date_naissance.jour >= 1 && date_naissance.jour <= 29) &&
             (date_naissance.mois == 2) &&
             ((date_naissance.annee % 400 == 0 ||
               date_naissance.annee % 4 == 0) &&
              (date_naissance.annee % 100 != 0))) {
        e->date_naissance.jour = date_naissance.jour;
        e->date_naissance.mois = date_naissance.mois;
        e->date_naissance.annee = date_naissance.annee;
    } else {
        printf("Votre date de naissance n\'est pas valide, veillez entrer une nouvelle date de naissance\n");
        LireDate(e);
    }
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
    LireDate(e);

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
    printf("\nDépartement: ");
    afficherDepartement(e.departement);
    printf("\nFilière: ");
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
    printf("%-5s %-10s\t%-30s\t%-30s\t%-10s\t%-12s\t%-8s\t%-35s\n", "Num", "Matricule", "Nom", "Prenom", "Date_Nais", "Region", "Sexe", "Filiere");
    for (int i = 0; i < nbEtudiants; i++) {
        printf("%-3d. [%-10s]\t%-30s\t%-30s\t%02d/%02d/%d\t",  
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
                // afficherDepartement(etudiants[i].departement);
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
    
    printf("Modification terminée.\n");
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
    Date datejour;
    time_t t = time(NULL);
    struct tm now = *localtime(&t);
    datejour.jour = now.tm_mday;
    datejour.mois = now.tm_mon + 1;
    datejour.annee = now.tm_year + 1900;
    if (datejour.mois > date_naissance.mois) {
        return datejour.annee - date_naissance.annee;
    }
    else if (datejour.mois < date_naissance.mois) {
        return datejour.annee - date_naissance.annee - 1;
    }
    else {
        if (datejour.jour < date_naissance.jour) {
            return datejour.annee - date_naissance.annee - 1;
        }
        else {
            return datejour.annee - date_naissance.annee;
        }
    }
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


