#include "etudiant.h"
#include <ctype.h>
#include <time.h>
#include <string.h>

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
    while ((c =  getchar()) != '\n' && c != EOF);
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
    printf("Etudiant actuel: %s %s (Matricule: %s)\n", 
           etudiant->nom, etudiant->prenom, etudiant->matricule);
    
    int choix;
    char temp[100];
    
    do {
        printf("\nQue voulez-vous modifier ?\n");
        printf("1. Nom (actuel: %s)\n", etudiant->nom);
        printf("2. Prénom (actuel: %s)\n", etudiant->prenom);
        printf("3. Matricule (actuel: %s)\n", etudiant->matricule);
        printf("4. Date de naissance (actuel: %02d/%02d/%04d)\n", 
               etudiant->date_naissance.jour,
               etudiant->date_naissance.mois,
               etudiant->date_naissance.annee);
        printf("5. Sexe (actuel: ");
        afficherSexe(etudiant->sexe);
        printf(")\n");
        printf("6. Département (actuel: ");
        afficherDepartement(etudiant->departement);
        printf(")\n");
        printf("7. Filière (actuel: ");
        afficherFiliere(etudiant->filiere);
        printf(")\n");
        printf("8. Région (actuel: ");
        afficherRegion(etudiant->region);
        printf(")\n");
        printf("9. TOUT modifier\n");
        printf("0. Terminer les modifications\n");
        printf("\nVotre choix: ");
        scanf("%d", &choix);
        viderBuffer(); // Utilise ta fonction viderBuffer() au lieu de getchar()
        
        switch(choix) {
            case 1: // Nom (char[])
                printf("Nouveau nom: ");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = '\0';
                if(strlen(temp) > 0) {
                    strcpy(etudiant->nom, temp);
                    printf("Nom modifié avec succès.\n");
                }
                break;
                
            case 2: // Prénom (char[])
                printf("Nouveau prénom: ");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = '\0';
                if(strlen(temp) > 0) {
                    strcpy(etudiant->prenom, temp);
                    printf("Prénom modifié avec succès.\n");
                }
                break;
                
            case 3: // Matricule (char[])
                printf("Nouveau matricule: ");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = '\0';
                if(strlen(temp) > 0) {
                    strcpy(etudiant->matricule, temp);
                    printf("Matricule modifié avec succès.\n");
                }
                break;
                
            case 4: { // Date de naissance (Date struct)
                Date nouvelleDate;
                printf("Date de naissance actuelle: %02d/%02d/%04d\n", 
                       etudiant->date_naissance.jour, 
                       etudiant->date_naissance.mois, 
                       etudiant->date_naissance.annee);
                
                do {
                    printf("Nouvelle date de naissance (JJ MM AAAA): ");
                    if (scanf("%d %d %d", &nouvelleDate.jour, &nouvelleDate.mois, &nouvelleDate.annee) != 3) {
                        printf("Format invalide!\n");
                        viderBuffer();
                        continue;
                    }
                    viderBuffer();
                    
                    // Validation de la date (comme dans ta fonction LireDate)
                    if ((nouvelleDate.jour >= 1 && nouvelleDate.jour <= 31) &&
                        (nouvelleDate.mois == 1 || nouvelleDate.mois == 3 ||
                         nouvelleDate.mois == 5 || nouvelleDate.mois == 7 ||
                         nouvelleDate.mois == 8 || nouvelleDate.mois == 10 ||
                         nouvelleDate.mois == 12)) {
                        break;
                    } else if ((nouvelleDate.jour >= 1 && nouvelleDate.jour <= 30) &&
                             (nouvelleDate.mois == 4 || nouvelleDate.mois == 6 ||
                              nouvelleDate.mois == 9 || nouvelleDate.mois == 11)) {
                        break;
                    } else if ((nouvelleDate.jour >= 1 && nouvelleDate.jour <= 29) &&
                             (nouvelleDate.mois == 2) &&
                             ((nouvelleDate.annee % 400 == 0 ||
                               nouvelleDate.annee % 4 == 0) &&
                              (nouvelleDate.annee % 100 != 0))) {
                        break;
                    } else {
                        printf("Date invalide. Veuillez réessayer.\n");
                    }
                } while(1);
                
                etudiant->date_naissance = nouvelleDate;
                printf("Date de naissance modifiée avec succès.\n");
                break;
            }
                
            case 5: // Sexe (ENUM - CORRECTION ICI)
                printf("Sexe actuel: ");
                afficherSexe(etudiant->sexe);
                printf("\n");
                etudiant->sexe = saisirSexe(); // Utilise ta fonction existante
                printf("Sexe modifié avec succès.\n");
                break;
                
            case 6: // Département (ENUM)
                printf("Département actuel: ");
                afficherDepartement(etudiant->departement);
                printf("\n");
                etudiant->departement = saisirDepartement(); // Utilise ta fonction
                printf("Département modifié avec succès.\n");
                break;
                
            case 7: // Filière (ENUM)
                printf("Filière actuelle: ");
                afficherFiliere(etudiant->filiere);
                printf("\n");
                etudiant->filiere = saisirFiliere(); // Utilise ta fonction
                printf("Filière modifiée avec succès.\n");
                break;
                
            case 8: // Région (ENUM)
                printf("Région actuelle: ");
                afficherRegion(etudiant->region);
                printf("\n");
                etudiant->region = saisirRegion(); // Utilise ta fonction
                printf("Région modifiée avec succès.\n");
                break;
                
            case 9: // TOUT modifier
                printf("\n=== MODIFICATION COMPLETE ===\n");
                
                // Matricule
                printf("Matricule: ");
                scanf("%s", etudiant->matricule);
                viderBuffer();
                
                // Nom
                printf("Nom: ");
                fgets(etudiant->nom, MAX_NOM, stdin);
                etudiant->nom[strcspn(etudiant->nom, "\n")] = '\0';
                
                // Prénom
                printf("Prenom: ");
                fgets(etudiant->prenom, MAX_PRENOM, stdin);
                etudiant->prenom[strcspn(etudiant->prenom, "\n")] = '\0';
                
                // Date de naissance
                printf("Date de naissance (JJ MM AAAA): ");
                scanf("%d %d %d", &etudiant->date_naissance.jour, 
                                  &etudiant->date_naissance.mois,
                                  &etudiant->date_naissance.annee);
                viderBuffer();
                
                // Sexe
                etudiant->sexe = saisirSexe();
                
                // Département
                etudiant->departement = saisirDepartement();
                
                // Filière
                etudiant->filiere = saisirFiliere();
                
                // Région
                etudiant->region = saisirRegion();
                
                printf("\nToutes les informations ont été modifiées.\n");
                break;
                
            case 0: // Terminer
                printf("\nModifications terminées.\n");
                break;
                
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
        
        // Afficher les nouvelles informations après chaque modification
        if(choix >= 1 && choix <= 8 && choix != 0) {
            printf("\nNouvel état de l'étudiant:\n");
            printf("Nom: %s\n", etudiant->nom);
            printf("Prénom: %s\n", etudiant->prenom);
            printf("Matricule: %s\n", etudiant->matricule);
        }
        
    } while(choix != 0);
    
    printf("\n=== MODIFICATION TERMINEE ===\n");
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
    
   
    if (*nbEtudiants == 0) {
        printf("Aucun étudiant enregistré !\n");
        return;
    }
    
    int index = rechercherParMatricule(etudiants, *nbEtudiants, matricule);
    
    if (index == -1) {
        printf("Aucun étudiant avec le matricule %s\n", matricule);
        return;
    }
    
    // Afficher un aperçu
    printf("\nÉtudiant trouvé: %s %s [%s]\n",
           etudiants[index].nom,
           etudiants[index].prenom,
           etudiants[index].matricule);
    
    // Demander confirmation simple
    printf("Confirmer la suppression ? (O/N): ");
    char confirmation;
    scanf(" %c", &confirmation);
    viderBuffer();
    
    confirmation = toupper(confirmation);
    
    if (confirmation != 'O') {
        printf("Suppression annulée.\n");
        return;
    }
    
    // Suppression
    for (int i = index; i < *nbEtudiants - 1; i++) {
        etudiants[i] = etudiants[i + 1];
    }
    
    (*nbEtudiants)--;
    printf("Étudiant supprimé avec succès !\n");
    printf("Il reste %d étudiant(s) dans la liste.\n", *nbEtudiants);
}


void trierAlphabetique(Etudiant etudiants[], int nbEtudiants) {
   
    int i, j;
    Etudiant temp;
    for (i = 0; i < nbEtudiants - 1; i++) {
        for (j = 0; j < nbEtudiants - i - 1; j++) {
            if (strcmp(etudiants[j].nom, etudiants[j + 1].nom) > 0) {
                temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }
}

int rechercherDichotomique(Etudiant etudiants[], int nbEtudiants, char nom[]) {
    int gauche = 0;
    int droite = nbEtudiants - 1;
    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;
        int comparaison = strcmp(etudiants[milieu].nom, nom);
        if (comparaison == 0) {
            return milieu;
        } else if (comparaison < 0) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }
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


