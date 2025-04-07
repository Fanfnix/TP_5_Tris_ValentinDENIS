#include "header.h"

Medic * creerMedic(int id, int date_fabriquation) {
    Medic * medicament = malloc(sizeof(Medic));
    if (medicament != NULL) {
        medicament->code = id;
        sprintf(medicament->nom, "Medicament_%d", id);
        medicament->date_fabriquation = date_fabriquation;
        medicament->date_peremption = date_fabriquation + 5+rand()%10;
        medicament->prix_unitaire = 5+rand()%10;
        medicament->nb_vendues = rand()%2000;
        medicament->nb_stock = rand()%1000;
        return medicament;
    } else {
        printf("ERR : creerMedic(%d) failed\n", id);
        return NULL;
    }
}


void ajouterMedic(Medic ** liste_medic, Medic * medicament, int * nb_medic) {
    if (liste_medic != NULL && medicament != NULL) {
        // liste_medic = realloc(liste_medic, ((*nb_medic+1)*2)*sizeof(Medic *));
        liste_medic[*nb_medic] = medicament;
        (*nb_medic)++;
    } else {
        printf("ERR : ajout medicament failed\n");
        return;
    }
}


Medic * demanderMedic(int id) {
    Medic * medicament = malloc(sizeof(Medic));
    if (medicament != NULL) {
        medicament->code = id;
        // Nom
        printf("Entrez nom medicament : ");
        scanf("%s", medicament->nom);
        // Date fabriquation
        printf("Entrez date fabrication [AAAA] : ");
        scanf("%d", &medicament->date_fabriquation);
        // Date peremption
        do {
            printf("Entrez date peremption [AAAA] : ");
            scanf("%d", &medicament->date_peremption);
        } while (medicament->date_peremption < medicament->date_fabriquation);
        // Prix unitaire
        printf("Entrez prix unitaire : ");
        scanf("%f", &medicament->prix_unitaire);
        // Nb vendues
        printf("Entrez nombre vendues : ");
        scanf("%d", &medicament->nb_vendues);
        // Nb stock
        printf("Entrez nombre stock : ");
        scanf("%d", &medicament->nb_stock);
        return medicament;
    } else {
        printf("ERR : creerMedic(%d) failed\n", id);
        return NULL;
    }
}


void afficherMedic(Medic * medoc) {
    printf("%d. %s (%d / %d) | PU: %.2f€ | NB_VENDUES: %d | NB_STOCK: %d\n", medoc->code, medoc->nom, medoc->date_fabriquation, medoc->date_peremption, medoc->prix_unitaire, medoc->nb_vendues, medoc->nb_stock);
}


void afficherListeMedic(Medic ** liste_medic, int nb_medic) {
    printf("----< Liste Medicaments >----\n");
    for (int i = 0; i < nb_medic; i++) {
        afficherMedic(liste_medic[i]);
    }
}


void tri_a_bulle_optimise(Medic ** liste_medic, int nb_medic) {
    int swapped;
    for (int i = nb_medic-1; i > 0; i--) {
        swapped = 0;
        for (int j = 0; j < i; j++) {
            if (liste_medic[j+1]->date_fabriquation < liste_medic[j]->date_fabriquation) {
                Medic * tmp = liste_medic[j+1];
                liste_medic[j+1] = liste_medic[j];
                liste_medic[j] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}