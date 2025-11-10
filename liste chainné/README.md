ensemble de fonctions pour permettre d'utiliser des listes chainnées

# dependences:
aucune

# fonctions:
- int addBegin(node_t **ph, void *data);
- int addEnd(node_t **ph, void *data);
- int popBegin(node_t **ph);
- int popEnd(node_t **ph);
- node_t *get(node_t **ph, int index);
- int lenght(node_t **ph);
# detail:
- addBegin : alloue de la mémoire pour un maillon, le place au debut de la chaine pointer par ph et y stocke data. Retourne -1 en cas d'erreur, 1 sinon

- addEnd : similaire a addBegin mais place le maillon a la fin de la liste pointée par ph

- popBegin : libere le premier maillon de la chaine liste pointée par ph et modifie ph pour qu'il pointe sur le nouveau premier maillon. Retourne -1 en cas d'erreur, 1 sinon

- popEnd : libere le dernier maillon de la chaine pointée par ph. Retourne -1 en cas d'erreur, 1 sinon

- get : revoie le maillon d'indice index de la chaine pointée par ph. Renvoie le pointeur NULL en cas d'erreur

- lenght : renvoie la taille de la chaine pointée par ph. revoie -1 en cas d'erreur

