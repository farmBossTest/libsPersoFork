version en recursif de l'algorithme minimax (c'est incroyablement plus simples a faire)
# dependances
    - main.h        : definie un type board_t pour contenir les plateaux de jeu      /!\ ce type doit etre copiable par simple affectation(=) /!\ 

# fonctions
    - int choseBestMove(board_t startBoard, int targetDepth, board_t *(*nextBoard)(board_t board, int *size), int(*evaluate)(board_t board), board_t *dest                                       
);

# details
    - choseBestMove parcours l'arbres des coups possible a partir de startBoard jusqu'a une profondeur de maxDepth et met le meilleur plateau dans la zone memoire pointé par dest.
    ## arguments
        - startBoard : plateau a partir du quel commence l'exploration
        - targetDepth : profondeur maximale de l'eploration de l'arbre
        - nextBoard : fonction qui renvoie un tableau alloué dynamiquement contenant tout les plateau accecible en un coups a partir de board et qui met size au nombres d'element du tableau retourné
        - evaluate : fonction qui renvoie la valeur d'un plateau (plus la valeur est grande meilleur est le plateau)
        - dest : adresse de la zone memoire ou stocker le meilleur plateau