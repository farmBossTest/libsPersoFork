#ifndef GENETICAI
#define GENETICAI
//#include "neuralNetwork.h"


#define success 1
#define ERROR_emptyGeneration -203
#define ERROR_generationSizeIsNegative -204
#define ERROR_layerToAvrageHaveNotTheSameSize -208

typedef struct entity_s{
    neuralNetwork_t genes;
    float score;
}entity_t;
typedef struct generation_s{
    entity_t *membres;
    int size;
}generation_t;

int tournament(generation_t gen, float (*match)(neuralNetwork_t, neuralNetwork_t));                 // evalue chaque entitée de gen en la faisant afronter toute les autre via match, puis reorganise la generation par score croissant. plus la performance du premier reseau est bonne plus la valeur renvoiée par match doit etre élevée
int concours (generation_t gen, float (*match)(neuralNetwork_t));                                   // evalue chaque entitée de gen via evaluate, puis reorganise la generation par score croissant. plus la performance du reseau est bonne plus la valeur renvoiée par evaluate doit etre élevée

int averageEntities(entity_t dest, entity_t src1, entity_t src2);                                   // met chaque poids et bias du reseau de neurones de dest a la moyennes du poid ou bias corespondant de src1 et du  poid ou bias corespondant de src2. les reseau de neurone de dest, src1 et src2 doivent avoir la meme taille

#endif