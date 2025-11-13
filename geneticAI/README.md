ensemble de fonctions pour permettre d'utiliser des listes chainnées

# dependences:
ma lib pour les reseau de neurones (network.h)

# fonctions:
- int tournament(generation_t gen, float (*match)(neuralNetwork_t, neuralNetwork_t))
- int concours (generation_t gen, float (*match)(neuralNetwork_t));
- int averageEntities(entity_t dest, entity_t src1, entity_t src2);  
# detail:
- tournament : evalue chaque entitée de gen en la faisant afronter toute les autre via match, puis reorganise la generation par score croissant. 
note : match doit renvoier une valeur d'autant plus grande que la performance du premier reseau passé en argument est bonne
    ## Parametres: 
        gen : generation dont les entitées vont etre classé
        match : fonction prenant deux reseaux de neurones (neuralNetwork_t) et qui renvoie un float d'autant plus grand que la performance du premier reseau passé en argument est bonne
    ## Valeurs de retour
        success (1) en cas de succes
        ERROR_emptyGeneration (-203) si le poiteur sur les membres de gen (gen.membres) est le pointeur NULL
        ERROR_generationSizeIsNegative (-204) le le champs sizes de gen (gen.sizes) a une valeur negative ou nulle
- coucours :// evalue chaque entitée de gen via evaluate, puis reorganise la generation par score croissant. 
note : evaluate doit renvoyer une valeur d'autant plus elevée que la performance du reseau passé en argument est bonne
    ## Parametres: 
        gen : generation dont les entitées vont etre classé
        evaluate : fonction prenant un reseau de neurones (neuralNetwork_t) et qui renvoie un float d'autant plus grand que la reseau passé en argument est bonne
    ## Valeurs de retour
        success (1) en cas de succes
        ERROR_emptyGeneration (-203) si le poiteur sur les membres de gen (gen.membres) est le pointeur NULL
        ERROR_generationSizeIsNegative (-204) le le champs sizes de gen (gen.sizes) a une valeur negative ou nulle
- averageEntities : met chaque poids et bias du reseau de neurones de dest a la moyennes du poid ou bias corespondant de src1 et du  poid ou bias corespondant de src2. 
note : les reseau de neurone de dest, src1 et src2 doivent avoir la meme taille
    ## Parametres: 
        dest : entité (entity_t) a modifer
        src1 : premiere entité (entity_t) dont les poids et bias servirons pour la moyenne
        src1 : deuxieme entité (entity_t) dont les poids et bias servirons pour la moyenne
    ## Valeurs de retour
        success (1) en cas de succes
        ERROR_layerToAvrageHaveNotTheSameSize (-208) si les reseaux de neurones de dest src1 et src2 n'ont pas exactement la meme taille
