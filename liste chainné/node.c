#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int addBegin(node_t **ph, void *data)
{
	if (ph == NULL){ 
		fprintf(stderr,"ERROR : invalid argument for addBegin\n");
		return -1;
	}

	node_t *head = NULL;
	if ( ( head = malloc(sizeof(node_t)) ) == NULL) {
		fprintf(stderr,"ERROR : failed to add a new node at the beggining\n");
		return -1;
	}

	head->data = data;
	head->next = *ph;
	*ph = head;
    return 1;

}

int addEnd(node_t **ph, void *data)
{
	if (ph == NULL){ 
		fprintf(stderr,"ERROR : invalid argument for addEnd\n");
		return -1;
	}
	
	node_t *tail = NULL;
	if ( ( tail = malloc(sizeof(node_t)) ) == NULL) {
		fprintf(stderr,"ERROR : failed to add a new node at the end\n");
		return -1;
	}	

	tail->data = data;
	tail->next = NULL;
	
	if (*ph == NULL) *ph = tail;
	else{	
		node_t *node = *ph;
		while (node->next != NULL){
			node = node->next;
		}
		node->next = tail;
	}
    return 1;
}

int popBegin(node_t **ph)
{
	if (ph == NULL){ 
		fprintf(stderr,"ERROR : invalid argument for popBegin\n");
		return -1;
	}
	if (*ph == NULL){
		fprintf(stderr,"ERROR : trying to remove a node at the beginning of an empty list\n");
		return -1;
	}

	node_t *node = *ph;
	*ph = node->next;
	free(node);
    return 1;
	
}

int popEnd(node_t **ph)
{
	if (ph == NULL){ 
		fprintf(stderr,"ERROR : invalid argument for popEnd\n");
		return -1;
	}
	if (*ph == NULL){
		fprintf(stderr,"ERROR : trying to remove a node at the end of an empty list\n");
		return -1;
	}

	node_t *node = *ph;
	if (node->next ==NULL) {
		*ph = NULL;
		free(node);
	}
	else{
		while ( (node->next)->next != NULL){
			node = node->next;
		}
		free (node->next);
		node->next = NULL;
	}
    return 1;
}

node_t *get(node_t **ph, int index){
    if (ph == NULL){ 
		fprintf(stderr,"ERROR : invalid argument for get\n");
		return NULL;
	}
	if (*ph == NULL){
		fprintf(stderr,"ERROR : trying to get a node from an empty list\n");
		return NULL;
	}

    node_t *node = *ph;
    for(int i = 0; i < index; i++){
        if (node->next == NULL){
            fprintf(stderr,"ERROR : trying to access an element out of range\n");
		    return NULL;
        }
        node = node->next;
    }
    return node;
}

int lenght(node_t **ph){
     if (ph == NULL){ 
		fprintf(stderr,"ERROR : invalid argument for lenght\n");
		return -1;
	}
    if (*ph == NULL) return(0);
    int index = 0;
    node_t *node = *ph;
    while (node->next != NULL){
        node = node->next;
        index++;
    }
    return index;
}
