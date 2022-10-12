#define MAX 50

typedef struct{
    char nome[25];
    int telefone;
    char endereco[40];

}REGISTRO;

typedef struct {

REGISTRO A[MAX];
int nroElem;

}AGENDA;

AGENDA *criar_agenda(AGENDA *agenda);
int inserir(AGENDA *agenda,  REGISTRO reg);
int cheia(AGENDA *agenda);
int remover(AGENDA *agenda, REGISTRO reg);
int buscar(AGENDA *agenda, REGISTRO reg);
AGENDA *deletar(AGENDA *inicio);
int imprimir(AGENDA *agenda);
