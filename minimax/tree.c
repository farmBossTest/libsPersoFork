#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"
#include "tree.h"
#include "node.h"

#define SENTINELLE 0 // a redefinir avec une meilleur valeur si possible 


static int makeTree_aux(
        vertex_t *parent,
        int targetDepth,
        board_t *(*nextBoard)(board_t, int *)
){
    if (parent->depth == targetDepth) return 0;

    int nbChildren = procreation(parent,nextBoard);
    if (parent->children != NULL && nbChildren > 0 /* ne fait rien si procreation retourne -1 meme si certain enfant on deja été declaré */ ){    

        int i = 0;
        int result = 0;
        for(node_t *child = parent->children; child != NULL && i < nbChildren && result >= 0 /*  arrete la boucle si procreation a retourer -1 dans un apelle plus profond */; child = child->next){
            result = makeTree_aux(child->data, targetDepth, nextBoard);
            i++;
        }
    }
    return nbChildren;
}

vertex_t *makeTree(
    board_t startBoard,
    int targetDepth,
    board_t *(*nextBoard)(board_t, int *),
    int(*evaluate)(board_t)
){
    vertex_t *root = NULL;
    if ( (root = malloc(sizeof(vertex_t))) == NULL){
        fprintf(stderr, "ERROR: allocation failed in makeTree\n");
        return NULL;
    }
    root->board = startBoard;
    root->depth = 0;
    root->score = SENTINELLE;
    root->children = NULL;
    root->parent = NULL;

    makeTree_aux(root, targetDepth, nextBoard);
    setScores(root,targetDepth,evaluate);
    return root;
    
}




static int procreation/*createChildrens*/(vertex_t *parent, board_t *(*nextBoard)(board_t, int *)){
    int size; 
    board_t *childrenBoards = nextBoard(parent->board, &size);
    vertex_t *child = NULL;
    for(int i=0; i<size; i++){
        if( (child = malloc(sizeof(vertex_t))) == NULL){
            fprintf(stderr,"ERROR : failed to allocate memory in createChildrens\n");
            free(childrenBoards);
		    return -1;
        }
        child->board = childrenBoards[i];
        child->depth = parent->depth+1;
        child->score = SENTINELLE;
        child->children = NULL;
        child->parent = parent;
        addBegin(&(parent->children),child);
    }
    free(childrenBoards);
    return size;
}

static int setScores(const vertex_t *parent, int targetDepth, int(*evaluate)(board_t)){
    if (parent->depth == targetDepth || parent->children == NULL) return evaluate(parent->board);   // ces deux condition sont equivalentes si tout va bien mais je checke les 2 car la premiere empeche les recurtion infinie et la deuxieme empeche les seg fault

    int score = (parent->depth % 2 == 1) ? INT_MIN : INT_MAX;
    int childScore;
    for(node_t *child = parent->children; child!= NULL; child = child->next){
            childScore = setScores(child->data, targetDepth, evaluate);

            if (parent->depth % 2 == 1){ // si c'est a l'adversaire de jouer
                if (childScore < score) score = childScore;
            }
            else {
                if (childScore > score) score = childScore;
            }
        }
    return score;

    
}

int freeTree(vertex_t *tree){
    if (tree->children == NULL) {
        free(tree);
        return 0;
    }

    node_t *subTree = tree->children;
    while (subTree != NULL){
        freeTree(subTree->data);
        popBegin(&subTree);
    }
    free(tree);
    return 0;
}


vertex_t chooseBestChild(vertex_t parent){
    if (parent.children == NULL){
        fprintf(stderr,"ERROR : childless tree is an invalide argument for chooseBestChild\n");
        return parent;
    }

    node_t *childList = parent.children;
    vertex_t *child = childList->data;
    vertex_t *bestChild = child;
    int bestScore = child->score;
    int currentScore;

    for(childList = childList; childList != NULL; childList = childList->next){
        child = childList->data;
        currentScore = child->score;
        if (currentScore > bestScore){
            bestScore = currentScore;
            bestChild = child;
        }
        childList = childList->next;
    }

    return *bestChild;

}