#include <stdio.h>
#include <stdlib.h>

int main()
{
    int saisieUtilisateur = 0;

    do {
        printf("entrez un chiffre : ");
        scanf("%d", saisieUtilisateur);
        printf("saisie uti : %d", saisieUtilisateur);
    } while (saisieUtilisateur != 9);

    return 0;
}
