#ifndef HEADER
#define HEADER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Medicament {
    char nom[50];
    int code;
    int date_fabriquation, date_peremption;
    float prix_unitaire;
    int nb_vendues, nb_stock;
} Medic;

typedef struct Chaine {
    Medic medic;
    Medic * suivant;
} Chaine;

Medic * creerMedic(int id, int date_fabriquation);
void ajouterMedic(Medic ** liste_medic, Medic * medicament, int * nb_medic);
Medic * demanderMedic(int id);

void afficherMedic(Medic * medoc);
void afficherListeMedic(Medic ** liste_medic, int nb_medic);

void tri_a_bulle_optimise(Medic ** liste_medic, int nb_medic);
int comp(const void * a, const void * b);
void dichotomie(Medic ** liste_medic, int nb_medic);
void prixMax(Medic ** liste_medic, int nb_medic);
void tauxVente(Medic ** liste_medic, int nb_medic);

void triChaine(Chaine * premier);

#endif