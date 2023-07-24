#include <stdio.h>
#include <stdlib.h>
#include "fazenda.h"
#include "animal.h"

struct animal{
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca 
	struct animal *prox;
};

Animal *criaListaEncadeadaSimplesAnimais() { return NULL; }

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Animal *cadastrarAnimal(Animal *rebanho) {
    Animal *no = (Animal*)malloc(sizeof(Animal)), *auxiliary = rebanho;

    no->id_animal = rand() % 1000;
    printf("ID FAZENDA: "); scanf("%i", &no->id_fazenda);
    limparBuffer();
    printf("SEXO: "); scanf("%c", &no->sexo);
    limparBuffer();
    printf("PESO: "); scanf("%f", &no->peso);
    limparBuffer();
    printf("STATUS: "); scanf("%i", &no->status);
    limparBuffer();

    // ñ tem animais na minha fazenda
    if (auxiliary == NULL) {
        // Indica que é meu ultimo elemento e que ele aponta pra NULL, indicando o fim da lista
        no->prox = NULL;
        // Retorno o meu dado
        return no;
    }   
    no->prox = auxiliary;
    return no;
}

int animalPresente(Animal *rebanho, int id_animal) {
    while (rebanho != NULL) {
        if (rebanho->id_animal == id_animal) {
            return 1;
        }
        rebanho = rebanho->prox;
    }
    return 0;
}

Animal *moverAnimal(Animal *RebanhoOrigem, Animal *ReabanhoDestino, int id_animal) {
    Animal *auxiliary = RebanhoOrigem, *aux2 = ReabanhoDestino;

    if (auxiliary->id_animal == id_animal) {
        while (aux2->prox != NULL) aux2 = aux2->prox;

        aux2->prox = auxiliary;
        RebanhoOrigem = RebanhoOrigem->prox;
        auxiliary->prox = NULL;

        return RebanhoOrigem;
    }

    while (auxiliary->prox != NULL && auxiliary->prox->id_animal != id_animal) {
        auxiliary = auxiliary->prox;
    }

    if (auxiliary->prox == NULL) {
        printf("\nAnimal de origem nao encontrado!\n");
        return RebanhoOrigem;
    }

    while (aux2->prox != NULL) aux2 = aux2->prox;

    aux2->prox = auxiliary->prox;
    auxiliary->prox = auxiliary->prox->prox;
    aux2->prox->prox = NULL;

    return RebanhoOrigem;
}

void atualizarAnimal(Animal *animal, int id_fazenda, int status) {
    animal->id_fazenda = id_fazenda;
    animal->status = status + 1;
}

Animal *permutasAnimais(Animal *RebanhoOrigem, Animal *ReabanhoDestino, int id_animal) {
    int status, id_fazenda;
    Animal *auxiliary = RebanhoOrigem, *aux2 = ReabanhoDestino;

    printf("Qual o tipo de permuta:\n1 - Venda\n2 - Troca\n- ");
    scanf("%d", &status);

    if (listaVaziaAnimal(RebanhoOrigem) || listaVaziaAnimal(ReabanhoDestino)) {
        printf("\nUm dos reabanhos vazios!\nCadastre pelo menos um animal para permutar!\n");
        return RebanhoOrigem;
    }

    if (!animalPresente(RebanhoOrigem, id_animal)) {
        printf("\nAnimal nao cadastrado!\n");
        return RebanhoOrigem;
    }

    RebanhoOrigem = moverAnimal(RebanhoOrigem, ReabanhoDestino, id_animal);

    while (aux2->prox != NULL) aux2 = aux2->prox;
    
    atualizarAnimal(aux2, aux2->id_fazenda, status);

    return RebanhoOrigem;
}

Animal *removerAnimal(Animal *rebanho, int id_animal) { // lista encadeada simples
	Animal *auxiliary = rebanho, *aux2;

	if (listaVaziaAnimal(rebanho)) {
		printf("\nLista vazia\n");
		return rebanho;
	}

	if (!buscarAnimal(rebanho, id_animal)) {
		printf("\nAnimal nao cadastrado!\n");
		return rebanho;
	}
	// Se o id estiver no primeiro
	if (auxiliary->id_animal == id_animal) {
		rebanho = auxiliary->prox;
		free(auxiliary);
		return rebanho;
	}
	// Se ñ estiver no 1º no
	while(auxiliary->prox->id_animal != id_animal) auxiliary = auxiliary->prox;
	
	aux2 = auxiliary->prox;
	auxiliary->prox = aux2->prox;
	free(aux2);

	return rebanho;
}

int listaVaziaAnimal(Animal *animais) { return animais == NULL ? 1 : 0; }

void mostrarAnimais(Animal *animais) {
	Animal *auxiliary = animais;

	if(listaVaziaAnimal(auxiliary)) {
		printf("\nNao ha animais nesta fazenda!\n");
		return;
	}

	printf("\n-ANIMAIS\n");
	while(auxiliary != NULL){
		printf("\nID ANIMAL: %d\n", auxiliary->id_animal); 
		printf("ID FAZENDA: %d\n", auxiliary->id_fazenda); 
		printf("SEXO: %c\n", auxiliary->sexo); 
		printf("PESO: %.2f\n", auxiliary->peso); 
		printf("STATUS: %d\n", auxiliary->status);

		auxiliary = auxiliary->prox; 
	}
	printf("\n");
}

int buscarAnimal(Animal *rebanho, int id) {
	Animal *auxiliary = rebanho;

	if (listaVaziaAnimal(rebanho)) return 0;

	while (auxiliary != NULL && auxiliary->id_animal != id) auxiliary = auxiliary->prox;

	return auxiliary == NULL ? 0 : 1;
}

void liberarMemoriaAnimal(Animal *animais) {
	Animal *auxiliary = animais;
	while(auxiliary != NULL){
		auxiliary = auxiliary->prox;
		free(animais);
		animais = auxiliary;
	}
	free(animais);
}

// não altera o ponteiro original, porque n estou retornando ele no final da função, entao as alterações permanecem somente aq
int countAnimais(Animal *animais, char sexo){
	int count = 0;
	while (animais != NULL) {
		if(animais->sexo == sexo) count++;
		
		animais = animais->prox;
	}
	return count;
}

float countArroba(Animal *animais) {
	float soma = 0;
	while (animais != NULL) {
		soma += animais->peso;
		animais = animais->prox;
	}
	// Convere quilogramas para arroba
	return soma / 15;
}

void printStatus(Animal *animais) {
	Animal *auxiliary = animais;
	// 1 nascimento na propria fazenda, 2 venda, 3 troca
	for (int i = 1; i <= 3; i++) {
		auxiliary = animais;
		printf("\n------------Status %d--------------\n", i);
		while (auxiliary != NULL){
			if(auxiliary->status == i){
				printf("\nID ANIMAL: %d\n", auxiliary->id_animal); 
				printf("ID FAZENDA: %d\n", auxiliary->id_fazenda); 
				printf("SEXO: %c\n", auxiliary->sexo); 
				printf("PESO: %.2f\n", auxiliary->peso); 
				printf("STATUS: %d\n", auxiliary->status);
			}
			auxiliary = auxiliary->prox;
		}
	}
}