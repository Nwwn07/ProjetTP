**Projet TP**


**Partie 1 : Recherche du chemin le plus court**

Le but de cette partie est de représenter un graphe en C, d'y implémenter un algorithme qui permet de trouver le chemin le plus court et de l'appliquer à un jeu de police-voleur, afin d'une part de permettre de trouver le chemin le plus court entre la police et le voleur, et d'autre part, pour le voleur de trouver le chemin le plus rapide jusqu'à son fourgon.
Pour la recherche :

Fonctions à implémenter : 

Création de la liste d'adjacence : deux structs, la plus efficiente en mémoire

Lire le fichier txt
Créer la liste d'adjacence
Fermer le fichier txt


Le plus court chemin : Dijkstra
Car certes plus lent, mais vu qu'on est sur un petit graphe cette contrainte est moins importante. De plus, dans le cas d'une course-poursuite, avoir le chemin le plus court pour rattraper le voleur est primordial, et seul Dijkstra peut garantir d'avoir le chemin le plus court.

Trouver le sommet avec la distance minimale non visité : 

**Partie 2 : Surveillance urbaine**

L'objectif de cette partie est de déterminer le nombre minimal d'intersections où des caméras devraient être installées afin que chaque rue de la ville soit sous surveillance. Pour ce faire, nous allons utiliser l'algorithme de coloration de Welsh-Powell.
Pour la coloration :

Calcul des degrés :

Calcul du D-
Calcul du D+


Tableau struct :

D
Sommet
Couleur


Création des couleurs
Calcul de quelle couleur a le moins d'effectif


**Partie 3 : Logistique des véhicules de police**

Dans cette partie, nous disposons d'une liste d'items avec leurs poids et leurs valeurs tactiques respectives. Le but est de concevoir un système qui maximise la valeur tactique totale tout en restant en dessous de 40 kg. Pour ce faire, nous allons mettre en place un algorithme d'optimisation.

Pour l'optimisation de la charge utile nous allons avoir besoin de 2 algos:

Maximum

Tri par programmation dynamique 
