#include "header.h"

int main() {
    int nb_medic = 0;
    Medic ** liste_medic = malloc(21*sizeof(Medic*));
    if (liste_medic == NULL) {
        printf("ERR : liste_medic NULL\n");
        return 0;
    }

    int compteur = 0;
    ajouterMedic(liste_medic, demanderMedic(compteur), &nb_medic);
    compteur++;
    for (int i = 0; i < 20; i++) {
        ajouterMedic(liste_medic, creerMedic(compteur, 1980+rand()%50), &nb_medic);
        compteur++;
    }

    afficherListeMedic(liste_medic, nb_medic);

    tri_a_bulle_optimise(liste_medic, nb_medic);

    afficherListeMedic(liste_medic, nb_medic);

    qsort(liste_medic, nb_medic, sizeof(Medic *), comp);

    afficherListeMedic(liste_medic, nb_medic);

    dichotomie(liste_medic, nb_medic);

    prixMax(liste_medic, nb_medic);

    if (liste_medic != NULL) {
        for (int i = 0; i < nb_medic; i++) {
            if (liste_medic[i] != NULL) {
                free(liste_medic[i]);
                liste_medic[i] = NULL;
            }
        }
        free(liste_medic);
        liste_medic = NULL;
    }

    return 0;
}