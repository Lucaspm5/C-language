#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "criador.h"
#include "fazenda.h"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;//Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; //esse valor deve ser constantemente modificado para que o valor esteja atualizado	
	struct criador *prox, *ant; //lista dupla encadeada, nao é necessário ser circular
};

Criador *criarListaDuplaCriadores() { return NULL; }

Criador *cadastrarCriador(Criador *criadores) {
	Criador *no = (Criador *) malloc(sizeof(Criador)), *aux = criadores;

	no->id_criador = rand() % 100000;
	printf("\nInsira o nome: "); 
	scanf("%s", no->nome);
	no->fazendas = criarListaEncadeadaCircularFazendas();
	no->patrimonio = 0;

	no->ant = NULL;

	if(listaVaziaCriador(criadores)) {
		no->prox = NULL;
		return no;
	}
	aux->ant = no;
	no->prox = aux;
	return no;
}

Criador *removerCriador(Criador *criadores, int id){ // msm processo
	Criador *aux = criadores, *aux2;

	if(listaVaziaCriador(criadores)){
		printf("\nA lista esta vazia!\n");
		return criadores;
	}
	// Verifico o primeiro no
	if(aux->id_criador == id){
		// significa que ñ ha fazendas cadastradas
		if(listaVaziaFazenda(aux->fazendas)){
			// verifico se é o unico criador cadasrado
			if(aux->prox == NULL)return NULL;
			// ñ é o único criador
			aux->prox->ant = NULL;
			criadores = aux->prox;
			free(aux);
			return criadores;
		}
		printf("\nNao eh possivel remover um criador com fazendas!\n");
		return criadores;
	}
	// Indico que o id ñ foi encontrado no 1º no
	while(aux->prox != NULL && aux->prox->id_criador != id) aux = aux->prox;
	
	// Verificação de segurança
	if (aux->prox == NULL) {
		printf("\nCriador nao existe!\n");
		return criadores;
	}
	// Se ñ tiver fazendas cadastradas com o id desse criador
	if (listaVaziaFazenda(aux->prox->fazendas)) {
		aux2 = aux->prox;
		aux->prox = aux->prox->prox;
		free(aux2);

		if (aux->prox == NULL) return criadores;
		// atribuição de garantia
		aux->prox->ant = aux;
		return criadores;
	} else {
		printf("\nNao eh possivel remover um criador com fazendas!\n");
		return criadores;
	}	
}

int buscarCriador(Criador *criadores, int id) {
	Criador *aux = criadores;

	while(aux != NULL && aux->id_criador != id) {
		aux = aux->prox;
	}

	return aux == NULL ? 0 : 1;
}

void mostrarCriadores(Criador *criadores) {
	Criador *aux = criadores;
	// verificação de segurança
	if (listaVaziaCriador(criadores)) {
		printf("\nNao existem criadores registrados!\n");
		return;
	}
	do{
		printf("\nID: %d\n", aux->id_criador);
		printf("Nome: %s\n", aux->nome);
		printf("Patrimonio: %.2f\n", aux->patrimonio);
		aux = aux->prox;
	} while(aux != NULL );
}

int listaVaziaCriador(Criador *lista) { return lista == NULL ? 1 : 0; }
// Verifica se o id foi cadastrado
Criador *getCriador(Criador *criadores, int id) {
    Criador *aux = criadores;
    while(aux != NULL && aux->id_criador != id) aux = aux->prox;

    return (aux == NULL) ? NULL : aux;
}

void liberarMemoriaFull(Criador *criadores) {
	Criador *aux = criadores;

	while (aux != NULL) {
		liberarFazendas(aux->fazendas);
		aux = aux->prox;
		free(criadores);
		criadores = aux;
	}
}

void cadastrarFazendas(Criador *criadores, int id) {
	Criador *criador = getCriador(criadores, id);
	if (criador) {
		criador->fazendas = cadastrarFazenda(criador->fazendas);
	} else {
		printf("\nCriador inexistente!\n");
	}
}

void mostrarTodasFazendas(Criador *criador) { mostrarFazendas(criador->fazendas); }

void removerFazendas(Criador *criador) {
	int id;
	printf("\nInsira o ID da fazenda: "); scanf("%d", &id);
	criador->fazendas =  removerFazenda(criador->fazendas, id);
	criador->patrimonio = calularPatrimonio(criador->fazendas);
}

void alterarFazendas(Criador *criador) {
	int id;
	printf("\nInsira o ID da fazenda: "); scanf("%d", &id);
	criador->fazendas = alterarFazenda(criador->fazendas, id);
}

void cadastrarCriadorFazendaRebanho(Criador *criador) {
	int id;
	printf("\nInsira o ID da fazenda: "); scanf("%d", &id);
	Fazenda *fazenda = getFazenda(criador->fazendas, id);

	if (fazenda) {
		cadastrarFazendaRebanho(fazenda);
		criador->patrimonio = calularPatrimonio(criador->fazendas);
	} else {
		printf("\nFazenda inexistente!\n");
	}
}

void mostrarCriadorFazendaAnimais(Criador *criador) {
	int id;
	printf("\nInsira o ID da fazenda: "); scanf("%d", &id);
	Fazenda *fazenda = getFazenda(criador->fazendas, id);

	if (fazenda) {
		mostrarFazendaAnimais(fazenda);
	} else {
		printf("\nFazenda inexistente!\n");
	}
}

void removerCriadorFazendaAnimal(Criador *criador) {
	int id;
	printf("\nInsira o ID da fazenda: "); scanf("%d", &id);
	Fazenda *fazenda = getFazenda(criador->fazendas, id);

	if (fazenda) {
		removerFazendaAnimal(fazenda);
		criador->patrimonio = calularPatrimonio(criador->fazendas);
	} else {
		printf("\nFazenda inexistente!\n");
	}
}

void permutarCriadorFazendaAnimal(Criador *criador1, Criador *criador2) {
	int id, id_destino;
	printf("\nInsira o ID da fazenda de origem: "); scanf("%d", &id);
	printf("Insira o ID da fazenda de destino: "); scanf("%d", &id_destino);
	Fazenda *fazenda1 = getFazenda(criador1->fazendas, id), *fazenda2 = getFazenda(criador2->fazendas, id_destino);

	if (fazenda1 && fazenda2) {
		permutaFazendaAnimal(fazenda1, fazenda2);
		criador1->patrimonio = calularPatrimonio(criador1->fazendas);
		criador2->patrimonio = calularPatrimonio(criador2->fazendas);
	} else {
		printf("\nAlguma fazenda inexistente!\n");
	}
}

void quantSexoCriadorAnimais(Criador *criador) {
	int id;
	printf("\nInsira o ID da fazenda: "); scanf("%d", &id);
	Fazenda *fazenda = getFazenda(criador->fazendas, id);
	if (fazenda) {
		printf("----------------Numero de animais por sexo----------------\n");
		printf("\nSexo M: %d\n", quantSexoAnimais(criador->fazendas, 'M'));
		printf("Sexo F: %d\n", quantSexoAnimais(criador->fazendas, 'F'));
		printf("----------------------------------------------------------\n");
	} else {
		printf("\nFazenda inexistente!\n");
	}
}

void printValorTotal(Criador *criador) {
	int id;
	printf("\nInsira o ID da fazenda: "); scanf("%d", &id);
	Fazenda *fazenda = getFazenda(criador->fazendas, id);

	if (fazenda) {
		valorTotal(fazenda);
	} else {
		printf("\nFazenda inexistente!\n");
	}
}

void printListaStatusAnimais(Criador *criador) {
	int id;
	printf("\nInsira o ID da fazenda: "); scanf("%d", &id);
	Fazenda *fazenda = getFazenda(criador->fazendas, id);
	if (fazenda) {
		listaStatusAnimais(fazenda);
	} else{ 
		printf("\nFazenda inexistente!\n");
	}
}

float patrimonioCriador(Criador *criador) { return calularPatrimonio(criador->fazendas); }