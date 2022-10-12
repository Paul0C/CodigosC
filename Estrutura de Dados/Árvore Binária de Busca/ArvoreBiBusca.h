typedef struct arvore_binaria ARVORE_BINARIA;
typedef struct no NO;
typedef struct votos VOTOS;
typedef struct arvoreBi_votos ARVORE_VOTOS;


struct no {
    int item;
    int num_votos;
    NO *filhoesq;
    NO *filhodir;
};

struct arvore_binaria {
    NO *raiz;
};

struct votos {
    int titulo;
    int voto;
    VOTOS *filhoesq;
    VOTOS *filhodir;
};

struct arvoreBi_votos{
    VOTOS *raiz;
};

ARVORE_BINARIA *criar_arvore();
ARVORE_VOTOS *criar_arvoreVoto();
NO *criar_raiz(ARVORE_BINARIA *arvore, int item);
VOTOS *criar_raizVoto(ARVORE_VOTOS *arvore, int item, int v0to);
NO *inserir_filho(int filho, NO *no, int item);
VOTOS *inserir_filhoVoto(int filho, VOTOS *no, int item, int v0to);
int inserirVoto(ARVORE_VOTOS *arvore, int item, int v0to);
int inserir_auxVoto(VOTOS *raiz, int itemNovo, int votoNovo);
int altura_arvore_aux(NO *no);
int altura_arvore(ARVORE_BINARIA *arvore);
int inserir_aux(NO *raiz, int itemNovo);
int inserir(ARVORE_BINARIA *arvore, int item);
int remove_abb_aux(ARVORE_BINARIA *arv, NO *prem, NO *pant, int chave);
int remove_abb(ARVORE_BINARIA *arv, int chave);
int remove_voto(ARVORE_VOTOS *arv, int chave);
int remove_voto_aux(ARVORE_VOTOS *arv, VOTOS *prem, VOTOS *pant, int chave);
void troca_maxVoto_esq(VOTOS *ptroca, VOTOS *prem, VOTOS *pant);
int vazia(ARVORE_BINARIA *arvore);
int vaziaVoto(ARVORE_VOTOS *arvore);
int MostraMaior(VOTOS *raiz);
int MostraMenor(VOTOS *raiz);
void troca_max_esq(NO *ptroca, NO *prem, NO *pant);
void emordem(ARVORE_BINARIA *arvore);
void emordem_aux(NO *raiz);
void emordemm(ARVORE_VOTOS *arvore);
void emordem_auxx(VOTOS *raiz);
void imprimir_item(int tit, int vot);
void imprimir_itemm(int titul0);
int incrementa_voto(NO *raiz, int Titulo);
int decrementa_voto(NO *raiz, int Titulo);
void busca(ARVORE_BINARIA *arvore, int titulo);
void buscaVoto(ARVORE_VOTOS *arvore, int titulo);
NO *busca_aux(NO *raiz, int titulo);
VOTOS *buscaVoto_aux(VOTOS *raiz, int titul0);
int deletarArvoreTitulo(ARVORE_BINARIA *arvore);
int deletarArvoreVoto(ARVORE_VOTOS *arvore);
