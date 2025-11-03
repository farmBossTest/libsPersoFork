#ifndef NODE
#define NODE

typedef struct node_s {
    void *data ;
    struct node_s *next ;
} node_t ;

int addBegin(node_t **ph, void *data);
int addEnd(node_t **ph, void *data);
int popBegin(node_t **ph);
int popEnd(node_t **ph);
node_t *get(node_t **ph, int index);
int lenght(node_t **ph);

#endif