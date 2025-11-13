ensemble de fonctions pour permettre d'utiliser des listes chainnées

# dependences:
ma lib pour les reseau de neurones (network.h)

# fonctions:
- int switchPlayer(char *player)
- int updateBoard(board_t board, int pos, char player)
- void showBoard(board_t board)
- void initBoard(board_t board)     
- char whoWins(board_t board)
- int convertPos(int x, int y)
# detail:
- switchPlayer : alterne la valeur de player entre P1 ('X') et P2('O')
    ## Parametres: 
        player : adresse de la variable a modifer
    ## Valeurs de retour
        success (1) en cas de succes
        ERROR_playerPointerIsNULL (-3) si le player est le pointeur NULL
- updateBoard : met a jour le board en placant une piece de player a la position pos si ce coups est valide
     ## Parametres: 
        board : plateau ( : board_t) a modfier
        pos : position encoder en considerant 0 comme la case en haut a droite, et en ajoutant le nombre de decalage a gauche + le nombre de decalage vers le bas * la taille d'une ligne
        player : caractere ( : char) representant le joueur (peut prendre 2 valeur definie par des constantes : P1 ('X') et P2 ('O'))
    ## Valeurs de retour
        success (1) en cas de succes
        ERROR_positionAlreadyFilled (-1) si la position indiquée est deja occupée par une piece
        ERROR_positionOutOfBounds (-2) si la position indiquée sort des limites du plateau ( : board_t)
- showBoard : affiche board de maniere formatée
    ## Parametres: 
        board : plateau ( : board_t) a affichée
- initBoard : met chaque case de board a nobody ('_')
    ## Parametres: 
        board : plateau ( : board_t) a initialisé
- whoWins : determine quel joueur gagne sur board
    ## Parametres: 
        board : plateau ( : board_t) sur lequel se joue la partie de laquelle whoWins doit detrminé le vainqueur
    ## Valeurs de retour
        nobody ('_') si personne ne gagne
        P1 ('X') si le joueur representé par P1 ('X') a gagné
        P2 ('O') si le joueur representé par P2 ('O') a gagné
- convertPos : convertit une des coordonée x,y en un entier corespondant dans un board_t
    ## Parametres: 
        x : indice de la ligne selectionnée
        y : indice de la collone selectionnée
    ## Valeurs de retour
        l'entier x + LENLINE (3) * y