#include <stdio.h>
#include "etudiant.h"
#include <stdlib.h>

int main() {
    printf("..........................................\n");
    printf("  BIENVENUE SUR NOTRE APPLICATION DE      \n");
    printf("      GESTION DES ETUDIANTS               \n");
    printf("..........................................\n\n");

        // Demander le nombre d'étudiants
    int nbEtudiantsMax;
    
    do {
        printf("Combien d'etudiants voulez-vous enregistrer ? (max %d) : ", MAX_ETUDIANTS);
        scanf("%d", &nbEtudiantsMax);
        viderBuffer();
        
        if (nbEtudiantsMax <= 0 || nbEtudiantsMax > MAX_ETUDIANTS) {
            printf("Veuillez entrer un nombre entre 1 et %d !\n", MAX_ETUDIANTS);
        }
    } while (nbEtudiantsMax <= 0 || nbEtudiantsMax > MAX_ETUDIANTS);
    
    printf("\n Preparation d'un tableau pour %d etudiants...\n", nbEtudiantsMax);

     Etudiant etudiants[MAX_ETUDIANTS];
    int nbEtudiantsActuels = 0;

    int choix;
    
    do {
        afficherMenu();
        printf("\nVotre choix : ");
        scanf("%d", &choix);
        viderBuffer();
        
        switch(choix) {
            case 1: // Enregistrer
                enregistrerEtudiant(etudiants, &nbEtudiantsActuels, nbEtudiantsMax);
                break;
                
            case 2: // Modifier
                if (nbEtudiantsActuels == 0) {
                    printf("Aucun etudiant a modifier !\n");
                } else {
                    char matricule[MAX_MATRICULE];
                    printf("Entrez le matricule de l'etudiant a modifier : ");
                    scanf("%s", matricule);
                    viderBuffer();
                    
                    int index = rechercherParMatricule(etudiants, nbEtudiantsActuels, matricule);
                    if (index != -1) {
                        modifierEtudiant(&etudiants[index]); // Utilisation de pointeur
                    } else {
                        printf("Etudiant non trouve !\n");
                    }
                }
                break;
                
            case 3: // Rechercher par matricule
                if (nbEtudiantsActuels == 0) {
                    printf("Aucun etudiant enregistre !\n");
                } else {
                    char matricule[MAX_MATRICULE];
                    printf("Entrez le matricule a rechercher : ");
                    scanf("%s", matricule);
                    viderBuffer();
                    
                    int index = rechercherParMatricule(etudiants, nbEtudiantsActuels, matricule);
                    if (index != -1) {
                        afficherEtudiant(etudiants[index]);
                    } else {
                        printf("Etudiant non trouve !\n");
                    }
                }
                break;
                
            case 4: // Supprimer
                if (nbEtudiantsActuels == 0) {
                    printf("Aucun etudiant a supprimer !\n");
                } else {
                    char matricule[MAX_MATRICULE];
                    printf("Entrez le matricule de l'etudiant a supprimer : ");
                    scanf("%s", matricule);
                    viderBuffer();
                    
                    supprimerEtudiant(etudiants, &nbEtudiantsActuels, matricule);
                }
                break;
                 
            
            case 5:// TRIER ALPHABÉTIQUE
                if (nbEtudiantsActuels < 2) {
                    printf("Pas assez d'etudiants pour trier !\n");
                } else {
                    trierAlphabetique(etudiants, nbEtudiantsActuels);
                    printf("\n✅ Liste triée. Voici le résultat :\n");
                    afficherTousEtudiants(etudiants, nbEtudiantsActuels);
                }
                break;
                
            case 6:// RECHERCHE DICHOTOMIQUE
                if (nbEtudiantsActuels == 0) {
                    printf("Aucun étudiant enregistre !\n");
                } else {
                    char nom[MAX_NOM];
                    printf("Entrez le nom a rechercher : ");
                    scanf("%s", nom);
                    viderBuffer();
                    
                    int index = rechercherDichotomique(etudiants, nbEtudiantsActuels, nom);
                    if (index != -1) {
                        printf("\n ETUDIANT TROUVE :\n");
                        afficherEtudiant(etudiants[index]);
                    } else {
                        printf("Etudiant non trouve !\n");
                    }
                }
                break;
                
            case 7:// CALCULER L'ÂGE 
                if (nbEtudiantsActuels == 0) {
                    printf("Aucun étudiant enregistre !\n");
                } else {
                    char matricule[MAX_MATRICULE];
                    printf("Entrez le matricule : ");
                    scanf("%s", matricule);
                    viderBuffer();
                    
                    int index = rechercherParMatricule(etudiants, nbEtudiantsActuels, matricule);
                    if (index != -1) {
                        int age = calculerAge(etudiants[index].date_naissance);
                        printf("\n🎂 L'étudiant %s %s a %d ans\n", 
                               etudiants[index].nom, 
                               etudiants[index].prenom, 
                               age);
                    } else {
                        printf("Etudiant non trouve !\n");
                    }
                }
                break;
                
            case 8://TRIER PAR FILIÈRE
                if (nbEtudiantsActuels < 2) {
                    printf("Pas assez d'etudiants pour trier !\n");
                } else {
                    trierParFiliere(etudiants, nbEtudiantsActuels);
                    printf("\nListe triee par filiere. Voici le resultat :\n");
                    afficherTousEtudiants(etudiants, nbEtudiantsActuels);
                }
                break;
             
            case 9: // Afficher tous les étudiants
                afficherTousEtudiants(etudiants, nbEtudiantsActuels);
                break;
                
            case 0: // Quitter
                printf("\n========================================\n");
                printf("      MERCI D'AVOIR UTILISE NOTRE\n");
                printf("      APPLICATION DE GESTION DES ETUDIANTS\n");
                printf("========================================\n");
                break;
                
            default:
                printf("Choix invalide ! Veuillez choisir entre 0 et 9.\n");
        }
        
        // Pause pour voir les résultats
        if (choix != 0) {
            printf("\nAppuyez sur ENTREE pour continuer...");
            getchar();
        }
        
    } while (choix != 0);
    
    return 0;
}
                  

    
    

 