#include <stdio.h>
#include <stdlib.h>
#include "criador.h"
#include "fazenda.h"
#include "animal.h"

struct endereco{
	char cidade[50], estado[2], logradouro[200];
};

struct fazenda{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda;//lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho; // ponteiro para uma lista (verificar no .h do animal que lista é)
	//ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Fazenda *criarListaEncadeadaCircularFazendas() { return NULL; }
 
Fazenda *cadastrarFazenda(Fazenda *fazendas) {
	Fazenda *no = (Fazenda *) malloc(sizeof(Fazenda)), *aux = fazendas;

	no->id_fazenda = rand() % 100000;
	printf("\nInsira novamente seu ID de criador: "); scanf("%d", &no->id_criador);
	printf("Insira o nome da fazenda: "); scanf("%s", no->nome);
	printf("Insira a cidade: "); scanf("%s", no->localizacao.cidade);
	printf("Insira o estado: "); scanf("%s", no->localizacao.estado);
	printf("Insira o logradouro: "); scanf("%s", no->localizacao.logradouro);
	no->rebanho = criaListaEncadeadaSimplesAnimais();
	// Crio uma lista circular
	if (listaVaziaFazenda(fazendas)) {
		no->prox = no;
		return no;
	}
	while (aux->prox != fazendas) aux = aux->prox;

	aux->prox = no; // insere no início
	no->prox = fazendas;
	return no;
}

Fazenda *removerFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas, *aux2;

	if(!listaVaziaFazenda(fazendas)){ // verifica vazia
		printf("\nLista vazia\n");
		return fazendas;
	}

	if(!buscarFazenda(fazendas, id)){ // buscar a fazenda
		printf("\nFazenda nao cadastrada!\n");
		return fazendas;
	}

	if(aux->id_fazenda == id){

		if(listaVaziaAnimal(aux->rebanho)){ // condição
			printf("\nNao eh possivel remover fazenda com rebanho!\n");
			return fazendas;
		}

		if(aux->prox == aux){ // só um elemnto (início)
			return NULL;
		}

		while(aux->prox != fazendas){ // mais de um (meio e fim)
			aux = aux->prox;
		}

		aux->prox = fazendas;
		free(fazendas); // remove

		return aux->prox;
	}

	while(aux->prox != fazendas && aux->prox->id_fazenda != id){ // ids diferentes
		aux = aux->prox; // proximo
	}

	if(aux->prox == fazendas){
		printf("\nFazenda nao cadastrada!\n");
		return fazendas;
	}

	if(!listaVaziaAnimal(aux->rebanho)){
		printf("\nNao eh possivel remover fazenda com rebanho!\n");
		return fazendas;
	}
	

	aux2 = aux->prox;
	aux->prox = aux->prox->prox; // circular (restrições)
	free(aux2);

	return fazendas;
}

Fazenda *alterarFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas;

	if(listaVaziaFazenda(fazendas)){
		printf("\nLista vazia!\n");
		return fazendas;
	}

	if(buscarFazenda(fazendas, id)){

		while(aux->id_fazenda != id){
			aux = aux->prox;
		}

		printf("\nInsira o novo nome da fazenda: "); scanf("%s", aux->nome);
		printf("\nInsira seu Estado: "); scanf("%s", aux->localizacao.estado);
		printf("\nInsira sua cidade: "); scanf("%s", aux->localizacao.cidade);
		printf("\nInsira seu logradouro: "); scanf("%s", aux->localizacao.logradouro);
	}else{
		printf("\nFazenda inexistente!\n");
	}

	return fazendas; // alterada
}

int buscarFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas;

	if(listaVaziaFazenda(fazendas)){
		printf("\nSem fazendas registradas!\n");
		return 0;
	}

	if(aux->id_fazenda == id){
		return 1; // igual
	}

	while(aux->prox != fazendas && aux->prox->id_fazenda != id){
		aux = aux->prox;
	}

	return aux->prox == fazendas ? 0 : 1;
}

int listaVaziaFazenda(Fazenda *fazendas) { return fazendas == NULL ? 1 : 0; }

void mostrarFazendas(Fazenda *fazendas) {
	Fazenda *aux = fazendas;
	if (listaVaziaFazenda(fazendas)) {
		printf("\nNao ha fazendas registradas desse criador!\n");
		return;
	}
	// Com a função a cima, eu já garanto que tenha ao menos uma opc
	printf("\nFazendas-\n");
	do{	
		printf("\nID: %d\n", aux->id_fazenda);
		printf("Nome: %s\n", aux->nome);
		printf("Estado: %s\n", aux->localizacao.estado);
		printf("Cidade: %s\n", aux->localizacao.cidade);
		printf("Logradouro: %s\n", aux->localizacao.logradouro);
		aux = aux->prox;
	} while(aux != fazendas);
}

Fazenda *getFazenda(Fazenda *fazendas, int id) { // endereço da fazenda
	Fazenda *aux = fazendas;

	if (listaVaziaFazenda(fazendas)) {
		printf("\nSem fazendas registradas!\n");
		return fazendas;
	}
	if (aux->id_fazenda == id) return aux;
	
	while(aux->prox != fazendas && aux->prox->id_fazenda != id) aux = aux->prox;

	return aux->prox == fazendas ? NULL : aux->prox;
}
// lincagem
void cadastrarFazendaRebanho(Fazenda *fazenda){ fazenda->rebanho = cadastrarAnimal(fazenda->rebanho); }
// lincagem
void mostrarFazendaAnimais(Fazenda *fazenda) { mostrarAnimais(fazenda->rebanho); }

void removerFazendaAnimal(Fazenda *fazenda) {
	int id;
	printf("\nInsira o ID do animal: "); scanf("%d", &id);
	if (buscarAnimal(fazenda->rebanho, id)) {
		fazenda->rebanho = removerAnimal(fazenda->rebanho, id);
	} else {
		printf("\nAnimal nao cadastrado!\n");
	}
}

void permutaFazendaAnimal(Fazenda *fazenda1, Fazenda *fazenda2) {
	int id;
	printf("\nInsira o ID do animal: "); scanf("%d", &id);
	if (buscarAnimal(fazenda1->rebanho, id)) {
		fazenda1->rebanho = permutasAnimais(fazenda1->rebanho, fazenda2->rebanho, id);
	} else {
		printf("\nAnimal nao cadastrado!\n");
	}
}

int quantSexoAnimais(Fazenda *fazenda, char sexo) { return countAnimais(fazenda->rebanho, sexo); }

void arrobaTotal(Fazenda *fazendas) {
	int id;
	printf("\nInsira o ID da fazenda: "); scanf("%d", &id);
	Fazenda *fazenda = getFazenda(fazendas, id);
	if (fazenda) {
		printf("Total de arrobas: %.2f\n", countArroba(fazenda->rebanho));
	} else {
		printf("\nFazenda inexistente\n");
	}
}

void valorTotal(Fazenda *fazenda) {
	printf("Valor total da fazenda: %.2f reais\n", countArroba(fazenda->rebanho) * 267.5);
}

void listaStatusAnimais(Fazenda *fazenda) { printStatus(fazenda->rebanho); }

void liberarFazendas(Fazenda *fazendas) {
	Fazenda *aux = fazendas, *aux2;
	aux2 = NULL;
	while(fazendas->prox != aux) {
		aux2 = fazendas;
		liberarMemoriaAnimal(aux->rebanho);
		fazendas = fazendas->prox;
		free(aux2);
	}
	free(fazendas);
}

float calularPatrimonio(Fazenda *fazendas) { // atualizado
	Fazenda *aux = fazendas;
	float soma = 0;
	do{
		soma += countArroba(aux->rebanho) * 267.5;
		aux = aux->prox;
	}while(aux != fazendas);
	return soma;
}