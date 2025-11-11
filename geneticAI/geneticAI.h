#ifndef GENETICAI
#define GENETICAI
#include "neuralNetwork.h"

#define weightMutationUpperBound 1.0
#define weightMutationLowerBound -1.0
#define mutationProbaUpperBound 1000000
#define mutationProbaLowerBound 0

#define success 1
#define ERROR_generationPointeurIsNULL -201
#define ERROR_entityPointeurIsNULL -202
#define ERROR_emptyGeneration -203
#define ERROR_generationSizeIsNegative -204
#define ERROR_mutationProbaOutOfBound -205
#define ERROR_failedToReallocateMemory -206
#define ERROR_destinationPointeurIsNULL -207
#define ERROR_layerToAvrageHaveNotTheSameSize; -208

typedef struct entity_s{
    neuralNetwork_t genes;
    float score;
}entity_t;
typedef struct generation_s{
    entity_t *membres;
    int size;
}generation_t;

int tournament(generation_t gen, float (*match(neuralNetwork_t, neuralNetwork_t)));
int concours (generation_t gen, float (*match(neuralNetwork_t)));

int mutateWeight(entity_t *entity, int mutationProba, float mutationIntensity);
int mutateNeurons(entity_t *entity, int mutationProba);
int mutateLayer(entity_t *entity, int mutationProba);
int averageEntities(entity_t dest, entity_t src1, entity_t src2);

#endif