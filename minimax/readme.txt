ensemble de fonctions pour permettre de faire du minimax sur un jeu.

dependences:
	ma lib pour les listes chainées (node.h)
	un main.h définissant entre autre le type board_t. ce type doit correspondre a ce qui est utiliser pour stocker l'état du jeu

fonctions:
	vertex_t *makeTree(
    		board_t startBoard,
    		int targetDepth,
    		board_t *(*nextBoard)(board_t board, int *size),
    		int(*evaluate)(board_t board)
	);

	int freeTree(vertex_t *tree);

	vertex_t chooseBestChild(vertex_t parent);
detail:
	makeTree : retourne un pointeur sur un arbre de profondeur targetDepth contenant coups possibles selon nextBoard (prend un etat du jeu et un entier puis renvoie un tableau des états possible au tour 			suivant et met size au nombre d'états possible) depuis la position startBoard. les feuilles de l'arbres sont évaluées avec evaluate (prend un état du jeu et renvoie son score) et les autre 			nœuds en remontant l'arbre selon minimax. Retourne le pointeur NULL en cas d'erreur
	
	freeTree : libères toute les zones mémoires allouées pour stocker tree.

	chooseBestChild	retourne un sous arbre de parent dont la racine est l'enfant direct de parent avec le meilleur score. Retourne parent si parent n'a pas d'enfant