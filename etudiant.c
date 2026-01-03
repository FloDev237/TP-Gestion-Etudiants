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
        case MASCULIN: printf("Masculin"); break;
        case FEMININ: printf("Féminin"); break;
    }
}

// Afficher un enum Département
void afficherDepartement(Departement d) {
    switch(d) {
        case INFOTEL: printf("INFOTEL"); break;
        case GENIE_CIVIL: printf("Genie Civil"); break;
    }
}

// Afficher un enum Filière
void afficherFiliere(Filiere f) {
    switch(f) {
        case DATA_SCIENCE: printf("Data Science"); break;
        case CRYPTOGRAPHIE_SECURITE: printf("Cryptographie et Sécurité"); break;
        case RESEAU_TELECOM: printf("Réseau et Télécom"); break;
        case ROBOTIQUE: printf("Robotique"); break;
        case GENIE_LOGICIEL: printf("Génie Logiciel"); break;
    }
}

// Afficher un enum Région
void afficherRegion(Region r) {
    switch(r) {
        case EXTREME_NORD: printf("Extrême-Nord"); break;
        case NORD: printf("Nord"); break;
        case ADAMAOUA: printf("Adamaoua"); break;
        case EST: printf("Est"); break;
        case SUD: printf("Sud"); break;
        case LITTORAL: printf("Littoral"); break;
        case CENTRE: printf("Centre"); break;
        case OUEST: printf("Ouest"); break;
        case SUD_OUEST: printf("Sud-Ouest"); break;
        case NORD_OUEST: printf("Nord-Ouest"); break;
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
    printf("3: Robotique\n");
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
    printf("✅ Étudiant enregistré!\n");
}

// Afficher un étudiant
void afficherEtudiant(Etudiant e) {
    printf("\n=== FICHE ETUDIANT ===\n");
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
    printf("\nRégion: ");
    afficherRegion(e.region);
    printf("\nÂge: %d ans\n", calculerAge(e.date_naissance));
    printf("======================\n");
}

// Afficher tous les étudiants

void afficherTousEtudiants(Etudiant etudiants[], int nbEtudiants) {
    if (nbEtudiants == 0) {
        printf(" Aucun etudiant enregistre.\n");
        return;
    }
    
    printf("\n=== LISTE DES ETUDIANTS (%d) ===\n", nbEtudiants);
    for (int i = 0; i < nbEtudiants; i++) {
        printf("%d. %s %s [%s] - ", 
               i + 1, 
               etudiants[i].nom, 
               etudiants[i].prenom,
               etudiants[i].matricule);
                afficherFiliere(etudiants[i].filiere);
        printf("\n");
    }

 }
// Modifier un étudiant (avec pointeurs comme demandé)
   void modifierEtudiant(Etudiant *etudiant) {
    printf("\n=== MODIFICATION ÉTUDIANT ===\n");
    printf("Étudiant: %s %s\n", etudiant->nom, etudiant->prenom);
    
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

void trierParFiliere(Etudiant etudiants[], int nbEtudiants) {
    
    printf("Fonction trierParFiliere - A implementer\n");
}



