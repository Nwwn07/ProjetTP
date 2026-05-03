# ProjetTP
Quoikoubeh

Partie 1 : Recherche du chemin le plus court chemin 

Le but de cette partie est de représenter 1 graphe en c, d'y implémenter 1 algorithme qui permet de trouver le plus court chemin et de l'appliquer a un jeu de police voleur afin d'une part de permette de trouver le chemin le plus court entre la police et le voleur et d'autre part, pour le voleur de trouver le chemin de plus rapide jusqu'a son fourgon. 

Fonction a implémenter : 

- Algo du plus court chemin : on va utiliser Dijkstra car par rapport a l'algorihtme A*, il donne toujours le plus court chemin et comme on travail avec des graphes relativemment petits, nous n'avons pas besoin d'utiliser A*.
      - Dijkstra a besoin de struct et d'une fonction qui permet d'identifier le plus court chemin. 

  
  
- Algothime de visualisation du graphe (convertion fichier text --> liste d'adjacence car c'est la plus économe en mémoire et que le parcours des voisins se fait rapidemment.
  définition d'une structure avec le noeud , les voisins du noeud, le poid de ce dernier = "coût d'une route" (poid qui représente le traffic routier, limitation de vitesse...)

Partir 2 :  Surveillance urbaine 

L'objectif de cette partie est de  déterminer le nombre minimal d'intersections où des caméras devraient être
installées afin que chaque rue dans La ville est sous surveillance, pour ce faire nous allons l'utiliser l'algorithme de coloration de welsh powel.

Partie 3 : Logistique des véhicules de police

Dans cette partie, nous avons  a notre disposition une liste d'item avec leurs poids et leus valeur tactique repsectif, le but est de concevoir un système qui maximise la valeur tactique totale que l'on peut avoir tout en restant en dessous de 40kg. Pour ce faire nous allons mettre en place un algorithme 
