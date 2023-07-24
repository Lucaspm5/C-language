typedef struct criador Criador;

Criador *criarListaDuplaCriadores();
Criador *cadastrarCriador(Criador *criadores);
Criador *removerCriador(Criador *criadores, int id);//nao é permitido remover criador com fazendas cadastradas
int buscarCriador(Criador *criadores, int id);
void mostrarCriadores(Criador *criadores);
int listaVaziaCriador(Criador *lista);
Criador *getCriador(Criador *criadores, int id);
void liberarMemoriaFull(Criador *criadores);

//Funções necessárias para realizar operações em fazendas.
void cadastrarFazendas(Criador *criadores, int id);
void mostrarTodasFazendas(Criador *criador);
void removerFazendas(Criador *criador);
void alterarFazendas(Criador *criador);

//Funçoes necessárias para realizar operações em rebanho
void cadastrarCriadorFazendaRebanho(Criador *criador);
void mostrarCriadorFazendaAnimais(Criador *criador);
void removerCriadorFazendaAnimal(Criador *criador);
void permutarCriadorFazendaAnimal(Criador *criador1, Criador *criador2);
void quantSexoCriadorAnimais(Criador *criador);
void printValorTotal(Criador *criador);
void printListaStatusAnimais(Criador *criador);
float patrimonioCriador(Criador *criador);


/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado)
- Funcao para mostrar cada criador e todos os seus respectivos atributos
- Funcao para liberar a memoria
*/