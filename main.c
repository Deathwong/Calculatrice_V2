#include <stdio.h>
#include <stdbool.h>


int saisieUtilisateurChiffre;
int resultat = 0;
int chiffreOperation;
int n;

void afficherMenu(bool hasResultat) {
    printf("----------Menu----------\n\n");
    printf("1.Addition\n");
    printf("2.Soustraction\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");

    if (hasResultat) {
        printf("5.Resultat\n");
    }

    printf("9.Quittez\n");
    printf("\nVotre choix?\n\n");
}


void operation() {
    switch (saisieUtilisateurChiffre) {

        //Addition
        case 1:
            resultat = resultat + chiffreOperation;
            break;

            //Soustraction
        case 2:
            resultat = resultat - chiffreOperation;
            break;

            //Multiplication
        case 3:
            resultat = resultat * chiffreOperation;
            break;

            //Division
        case 4:
            resultat = resultat / chiffreOperation;
            break;
        default:
            printf("on sort\n");
            break;
    }

}


// On demande à l'utilisateur de saisir un chiffre et on l'affecte à une variable
void saisirChiffre() {
    printf("entrez un chiffre : \n");
}


// Emplacement de l'utilisateur à l'empêcher de saisir 0 en cas d'une division
void differentdezero() {
    while (saisieUtilisateurChiffre == 4 && chiffreOperation == 0) {
        printf("Saisissez un chiffre different de 0 : \n");
        scanf("%d", &chiffreOperation);
    }
}


void recupeChiffreSaisi() {

    do {
        saisirChiffre();
        n = scanf("%d", &chiffreOperation);
        if (n != 1) {
            puts("erreur veuillez taper un chiffre\n");
            getchar();
        }
    } while (n != 1);

}


void recuPsaisieUtilisateurChiffre() {

    do {
        n = scanf("%d", &saisieUtilisateurChiffre);
        if (n != 1) {
            puts("erreur veuillez taper un chiffre\n");
            getchar();
        }
    } while (n != 1);

}


int main() {

    do {

        //On demande et on récupère le chiffre saisi par l'utilisateur
        recupeChiffreSaisi();

        //affectation de la saisie utilisateur
        resultat = chiffreOperation;

        // Affichage du Menu
        afficherMenu(false);

        //On récupère le chiffre correspondant à l'opération saisi par l'utilisateur
        recuPsaisieUtilisateurChiffre();

        //On demande et on récupère le chiffre saisi par l'utilisateur
        recupeChiffreSaisi();

        //emplacement de l'utilisateur à l'empêcher de saisir 0 en cas d'une division
        differentdezero();

        //operation
        operation();

        while (saisieUtilisateurChiffre != 5) {

            // Affichage du Menu (avec l'option résultat)
            afficherMenu(true);

            //On récupère le chiffre correspondant à l'opération saisi par l'utilisateur
            recuPsaisieUtilisateurChiffre();


            if (saisieUtilisateurChiffre != 5){

                //On demande et on récupère le chiffre saisi par l'utilisateur
                recupeChiffreSaisi();

                //emplacement de l'utilisateur à l'empêcher de saisir 0 en cas d'une division
                differentdezero();

                //operation
                operation();

            }

        }

        printf("******* calcul du resultat *******");

        printf("Resultat : %d \n", resultat);

    } while (saisieUtilisateurChiffre != 9 && saisieUtilisateurChiffre != 5);

    return 0;
}
