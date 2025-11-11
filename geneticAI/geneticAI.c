#include "geneticAI.h"
#include <stdlib.h>

static int compareEntityByScore(const void *pa, const void *pb){
    const entity_t *a = pa;
    const entity_t *b = pb;
    if (a->score < b->score) return -1;
    if (a->score > b->score) return  1;
    return 0;
}

int tournament(generation_t *gen, float (*match)(neuralNetwork_t, neuralNetwork_t)){        // match doit revoier une valeur qui quantifie la perfomance du premier reseau face au segond (plus une valeur est grande meilleur est la performance)
    if (gen == NULL) return ERROR_generationPointeurIsNULL;
    if (gen->membres == NULL) return ERROR_emptyGeneration;
    if (gen->size <= 0) return ERROR_generationSizeIsNegative;

    for (int i = 0; i < gen->size; i++){
        gen->membres[i].score = 0;
        for (int j = 0; j < gen->size; j++){
            if (i == j) continue;
            gen->membres[i].score += match(gen->membres[i].genes, gen->membres[j].genes);
        }
    }
    qsort(gen->membres, gen->size, sizeof(entity_t), compareEntityByScore);
    return success;
}

int concours (generation_t *gen, float (*evaluate)(neuralNetwork_t)){
    if (gen == NULL) return ERROR_generationPointeurIsNULL;
    if (gen->membres == NULL) return ERROR_emptyGeneration;
    if (gen->size <= 0) return ERROR_generationSizeIsNegative;

    for (int i = 0; i<gen->size; i++){
        gen->membres[i].score = evaluate(gen->membres[i].genes);
    }
    qsort(gen->membres, gen->size, sizeof(entity_t), compareEntityByScore);
    return success;
}

int averageEntities(entity_t *dest, entity_t src1, entity_t src2){                  // les reseaux de neurones de dest, src1 et src2 doivent avoir la meme taille
    if (dest == NULL) return ERROR_destinationPointeurIsNULL;
    neuralNetwork_t destNetwork = dest->genes;
    neuralNetwork_t network1 = src1.genes;
    neuralNetwork_t network2 = src2.genes;
    if (destNetwork.nbLayers != network1.nbLayers || destNetwork.nbLayers != network1.nbLayers || network1.nbLayers != network2.nbLayers) return ERROR_layerToAvrageHaveNotTheSameSize;
    int nbLayers = destNetwork.nbLayers;
    for(int LayerIndex = 0; LayerIndex < nbLayers + 1; LayerIndex++){
        if (destNetwork.layerSizes[LayerIndex] != network1.layerSizes[LayerIndex] || destNetwork.layerSizes[LayerIndex] != network1.layerSizes[LayerIndex] || network1.layerSizes[LayerIndex] != network2.layerSizes[LayerIndex]) return ERROR_layerToAvrageHaveNotTheSameSize;
    }
    for(int LayerIndex = 0; LayerIndex < nbLayers; LayerIndex++){
        int currentLayerSize = destNetwork.layerSizes[LayerIndex + 1];
        int currentNeuronSize = destNetwork.layerSizes[LayerIndex + 1];
        for(int neuronIndex = 0; neuronIndex < currentLayerSize; neuronIndex++){
            destNetwork.network[LayerIndex][neuronIndex].bias = 0.5 * (network1.network[LayerIndex][neuronIndex].bias + network2.network[LayerIndex][neuronIndex].bias);
            for(int weightIndex = 0; weightIndex < currentNeuronSize; weightIndex++){
                destNetwork.network[LayerIndex][neuronIndex].weights[weightIndex] = 0.5 * (network1.network[LayerIndex][neuronIndex].weights[weightIndex] + network2.network[LayerIndex][neuronIndex].weights[weightIndex]);
            }
        }
    }
    return success;
}

