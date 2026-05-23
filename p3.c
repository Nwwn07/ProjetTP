// Projet C , partie 3 : Rangement optimal.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nom[50];
    int poids;
    int valeur_tactique;
} Item;

#define nombre_items 8
#define capacite_max 40 // poids max , 40kg dcp

Item inventaire[nombre_items] = {
    {"Bandes a pointes", 12, 85},
    {"Barriere portable", 20, 70},
    {"Drone tactique", 5, 90},
    {"Brouilleur de signal", 10, 60},
    {"Trousse medical", 3, 30},
    {"Gaz lacrymo Lanceur", 8, 50},
    {"Robuste Treuil", 15, 40},
    {"Scanner Portable", 2, 25}};

int meilleure_valeur_tactique = 0;
int meilleure_selection[nombre_items]; // tableau qui sert a stocké la meilleur selection trouvé

void prendre_la_best_selection(int valeur_tactique, int selection[]) // selection = tableau qui indique les items selectionnes (1 pour selectionne , 0 pour non selectionne)
{
    if (valeur_tactique > meilleure_valeur_tactique) // si la valeur tacttiqque de la combinaison actuelle est > a la meilleur v.T trouvée jusqu'a présent on remplace.
    {

        meilleure_valeur_tactique = valeur_tactique;

        for (int i = 0; i < nombre_items; i++)
        {
            meilleure_selection[i] = selection[i]; // on prend la meilleur combinaison possible ( on copie le tableau de selection actuel dans le tableau de la meilleur selection)
        }
    }
}

void parcourir_liste_items(int index, int poids_restant, int valeur_tactique, int selection[]) // index = postion dans la liste d'item ( on commence a 0) , valeur_tactique = compteur qui augemente (la valeur tactique)
{

    // On traite tous les items

    if (index == nombre_items)
    {
        prendre_la_best_selection(valeur_tactique, selection); // on verifie si la combinaison actuelle est meilleur que la meilleur combinaison trouvé jusqu'a présent
        return;
    }

    // On traite la selection de l'item actuel ( on a 2 choix : soit on le prend , soit on le prend pas)

    // Casn°1 : on en prend pas l'item actuel

    selection[index] = 0;                                                        // on ne selectionne pas l'item actuel
    parcourir_liste_items(index + 1, poids_restant, valeur_tactique, selection); // on passe a l'item suivant

    // Casn°2 : on prend l'item actuel (si le poids n'est pas suppérieurs a 40kg)

    if (inventaire[index].poids <= poids_restant)
    {
        selection[index] = 1;
        parcourir_liste_items(index + 1, poids_restant - inventaire[index].poids, valeur_tactique + inventaire[index].valeur_tactique, selection);

        selection[index] = 0; // reset a 0 pour l'item suivant car on n'a pas encore traité son cas
    }
}

void parcourir_liste_items_avec__item_obligatoire(int index, int poids_restant, int valeur_tactique, int selection[], int item_obligatoire) // index = postion dans la liste d'item ( on commence a 0) , valeur_tactique = compteur qui augemente (la valeur tactique)
{

    // On traite tous les items

    if (index == nombre_items)
    {
        prendre_la_best_selection(valeur_tactique, selection); // on verifie si la combinaison actuelle est meilleur que la meilleur combinaison trouvé jusqu'a présent
        return;
    }

    if (index == item_obligatoire) // si on est a l'item obligatoire , on le prend forcement
    {
        selection[index] = 1;                                                                                                 // on selectionne l'item obligatoire
        parcourir_liste_items_avec__item_obligatoire(index + 1, poids_restant, valeur_tactique, selection, item_obligatoire); // on passe a l'item suivant
        return;                                                                                                               // on retourne pour ne pas traiter les autres cas
    }

    // On traite la selection de l'item actuel ( on a 2 choix : soit on le prend , soit on le prend pas)

    // Casn°1 : on en prend pas l'item actuel

    selection[index] = 0;                                                                                                 // on ne selectionne pas l'item actuel
    parcourir_liste_items_avec__item_obligatoire(index + 1, poids_restant, valeur_tactique, selection, item_obligatoire); // on passe a l'item suivant

    // Casn°2 : on prend l'item actuel (si le poids n'est pas suppérieurs a 40kg)

    if (inventaire[index].poids <= poids_restant)
    {
        selection[index] = 1;
        parcourir_liste_items_avec__item_obligatoire(index + 1, poids_restant - inventaire[index].poids, valeur_tactique + inventaire[index].valeur_tactique, selection, item_obligatoire);

        selection[index] = 0; // reset a 0 pour l'item suivant car on n'a pas encore traité son cas
    }
}

int main()
{
    int selection[nombre_items] = {0}; // initilisation du tableau de selection a 0 , car on a pas encore selectionné d'item

    // Sans item obligatoire
    printf("Rangement optimal :\n\n");

    printf("Sans item obligatoire :\n\n");

    parcourir_liste_items(0, capacite_max, 0, selection); // on commence a parcourir la liste d'item a partir de l'index 0 , avec une capacite de 40kg et une valeur tactique de 0

    int poids_total = 0;
    for (int i = 0; i < nombre_items; i++) // on parcout la liste d'item pour afficher les items selectionnés et calculer le poids total
    {
        if (meilleure_selection[i] == 1) // si l'item i est selectionné  car on acopié selection dans meilleure_selection. On regarrde dcp ensuite les items qui ont comme valeur 1 ( ceux qqui ont été pris).
        {
            printf("Item : %s, Poids : %d kg, Valeur Tactique : %d\n", inventaire[i].nom, inventaire[i].poids, inventaire[i].valeur_tactique); // on affiche les details de l'item
            poids_total += inventaire[i].poids;                                                                                                // on ajoute le poids de l'item au poids total
        }
    }

    printf("Poids total : %d kg\n", poids_total);                       // on affiche le poids total de la meilleur selection
    printf("Valeur Tactique totale : %d\n", meilleure_valeur_tactique); // on affiche le poids total et la valeur tactique totale de la meilleur selection

    // Reset des variables pour le cas avec item obligatoire
    meilleure_valeur_tactique = 0;
    poids_total = 0;

    for (int i = 0; i < nombre_items; i++)
    {
        meilleure_selection[i] = 0; // reset du tableau de la meilleur selection
        selection[i] = 0;           // reset du tableau de selection
    }

    // Avec 1 item obligatoire
    printf("\nAvec 1 item obligatoire :\n\n");
    printf("Item obligatoire : %s\n\n", inventaire[1].nom); //a modif en fonction de l'item chosis


    int item_obligatoire = 1; // a modifé en fonction de l'item obligatoire que l'on veut de 0 a 7.
    selection[item_obligatoire] = 1;
    int poids_depart = capacite_max - inventaire[item_obligatoire].poids;
    int valeur_depart = inventaire[item_obligatoire].valeur_tactique;

    parcourir_liste_items_avec__item_obligatoire(0, poids_depart, valeur_depart, selection, item_obligatoire); // on commence avec une capacite de 40kg - le poids de l'item obligatoire et la valeur de l'item obligatoire

    for (int i = 0; i < nombre_items; i++) // on parcout la liste d'item pour afficher les items selectionnés et calculer le poids total
    {
        if (meilleure_selection[i] == 1) // si l'item i est selectionné  car on acopié selection dans meilleure_selection. On regarrde dcp ensuite les items qui ont comme valeur 1 ( ceux qqui ont été pris).
        {
            printf("Item : %s, Poids : %d kg, Valeur Tactique : %d\n", inventaire[i].nom, inventaire[i].poids, inventaire[i].valeur_tactique); // on affiche les details de l'item
            poids_total += inventaire[i].poids;                                                                                                // on ajoute le poids de l'item au poids total
        }
    }

    printf("Poids total : %d kg\n", poids_total);                       // on affiche le poids total de la meilleur selection
    printf("Valeur Tactique totale : %d\n", meilleure_valeur_tactique); // on affiche le poids total et la valeur tactique totale de la meilleur selection

    return 0;
}
