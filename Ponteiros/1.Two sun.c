int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* indices = (int*)malloc(2 * sizeof(int)); // cria um ponteiro de inteiros com tamanho 2
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(*(nums + i) + *(nums + j) == target) {
                *(indices + 0) = i; // armazena o valor de i na posição 0 do array
                *(indices + 1) = j; // armazena o valor de j na posição 1 do array
                *returnSize = 2; // define o tamanho do array como 2
                return indices; // retorna o ponteiro de inteiros
            }
        } 
    }
    free(indices); // libera a memória alocada para o array caso não tenha encontrado os índices
    return NULL; // retorna NULL caso não tenha encontrado os índices
}
