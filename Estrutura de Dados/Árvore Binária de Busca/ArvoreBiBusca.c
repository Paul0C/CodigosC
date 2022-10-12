#include<stdio.h>
#include<stdlib.h>
#include"ArvoreBiBusca.h"
#define FILHO_ESQ 0
#define FILHO_DIR 1

ARVORE_BINARIA *criar_arvore() {
ARVORE_BINARIA *arv;
arv = (ARVORE_BINARIA *)malloc(sizeof(ARVORE_BINARIA));

if (arv != NULL) {
arv->raiz = NULL;
}
return arv;
}

NO *criar_raiz(ARVORE_BINARIA *arvore, int item) {

arvore->raiz = (NO *) malloc(sizeof (NO));

if (arvore->raiz != NULL) {
arvore->raiz->filhodir = NULL;
arvore->raiz->filhoesq = NULL;
arvore->raiz->item = item;
}
return arvore->raiz;
}

ARVORE_VOTOS *criar_arvoreVoto() {
    ARVORE_VOTOS *arv;
    arv = (ARVORE_VOTOS *)malloc(sizeof(ARVORE_VOTOS));

    if (arv != NULL) {
        arv->raiz = NULL;
    }
    return arv;
}

VOTOS *criar_raizVoto(ARVORE_VOTOS *arvore, int item, int v0to) {

    arvore->raiz = (VOTOS *) malloc(sizeof (VOTOS));

    if (arvore->raiz != NULL) {
        arvore->raiz->filhodir = NULL;
        arvore->raiz->filhoesq = NULL;
        arvore->raiz->titulo = item;
        arvore->raiz->voto = v0to;
    }
    return arvore->raiz;
}

int vazia(ARVORE_BINARIA *arvore){

    return (arvore->raiz == NULL);
}

int vaziaVoto(ARVORE_VOTOS *arvore){

    return (arvore->raiz == NULL);
}

int deletarArvoreTitulo(ARVORE_BINARIA *arvore){

    free(arvore);
    return NULL;
}

int deletarArvoreVoto(ARVORE_VOTOS *arvore){

    free(arvore);
    printf("\nAs árvores foram deletadas com sucesso!\n");
    return NULL;
}

void imprimir_item(int tit, int vot){
    printf("Candidato %d:%d votos\n", tit, vot);
}

void imprimir_itemm(int titul0){
    printf("Título:%d\n", titul0);
}

void emordem_aux(NO *raiz) {
    if (raiz != NULL) {
        emordem_aux(raiz->filhoesq);
        imprimir_item(raiz->item, raiz->num_votos);
        emordem_aux(raiz->filhodir);
    }
}

void emordem(ARVORE_BINARIA *arvore){
    emordem_aux(arvore->raiz);
}

void emordem_auxx(VOTOS *raiz) {
    if (raiz != NULL) {
        emordem_auxx(raiz->filhoesq);
        imprimir_itemm(raiz->titulo);
        emordem_auxx(raiz->filhodir);
    }
}

void emordemm(ARVORE_VOTOS *arvore){
    emordem_auxx(arvore->raiz);
}


int MostraMaior(VOTOS *raiz){
     if(raiz != NULL){
        if(raiz->filhodir == NULL){
            return raiz->titulo;
        }else{
            MostraMaior(raiz->filhodir);
        }
    }

}

int MostraMenor(VOTOS *raiz){
    if(raiz != NULL){
        if(raiz->filhoesq == NULL){
            return raiz->titulo;
        }else{
            MostraMenor(raiz->filhoesq);
        }
    }

}

int incrementa_voto(NO *raiz, int Titulo){

    if(raiz == NULL){
        return 0;
    }else if(raiz->item < Titulo){
        incrementa_voto(raiz->filhodir, Titulo);
    }else if(raiz->item > Titulo){
        incrementa_voto(raiz->filhoesq, Titulo);
    }else{
        raiz->num_votos++;
        return raiz->num_votos;
    }

}

int decrementa_voto(NO *raiz, int Titulo){

    if(raiz == NULL){
        return 0;
    }else if(raiz->item < Titulo){
        decrementa_voto(raiz->filhodir, Titulo);
    }else if(raiz->item > Titulo){
        decrementa_voto(raiz->filhoesq, Titulo);
    }else{
        raiz->num_votos--;
        return raiz->num_votos;
    }

}

NO *busca_aux(NO *raiz, int Titulo){

    if(raiz == NULL){
        return NULL;
    }else if(raiz->item < Titulo){
        busca_aux(raiz->filhodir, Titulo);
    }else if(raiz->item > Titulo){
        busca_aux(raiz->filhoesq, Titulo);
    }else{
        printf("\nO título eh valido");
        printf("\nTitulo:%d", raiz->item);
        return raiz;
    }

}

void busca(ARVORE_BINARIA *arvore, int titulo){
    busca_aux(arvore->raiz, titulo);

}

VOTOS *buscaVoto_aux(VOTOS *raiz, int titul0){
     if(raiz == NULL){
        return NULL;
    }else if(raiz->titulo < titul0){
        buscaVoto_aux(raiz->filhodir, titul0);
    }else if(raiz->titulo > titul0){
        buscaVoto_aux(raiz->filhoesq, titul0);
    }else{
        printf("\nO título ja votou");
        printf("\nTitulo:%d", raiz->titulo);
        return raiz;
    }
}

void buscaVoto(ARVORE_VOTOS *arvore, int titulo){
    buscaVoto_aux(arvore->raiz, titulo);

}


NO *inserir_filho(int filho, NO *no, int item) {
    NO *pnovo = (NO *) malloc(sizeof (NO));
    if (pnovo != NULL) {
    pnovo->filhodir = NULL;
    pnovo->filhoesq = NULL;
    pnovo->item = item;
    pnovo->num_votos = 0;
    if (filho == FILHO_ESQ) {
        no->filhoesq = pnovo;
    }else {
        no->filhodir = pnovo;
    }
}

return pnovo;
}

VOTOS *inserir_filhoVoto(int filho, VOTOS *no, int item, int v0to) {
    VOTOS *pnovo = (VOTOS *) malloc(sizeof (VOTOS));
    if (pnovo != NULL) {
        pnovo->filhodir = NULL;
        pnovo->filhoesq = NULL;
        pnovo->titulo = item;
        pnovo->voto = v0to;
    if (filho == FILHO_ESQ) {
        no->filhoesq = pnovo;
    }else {
        no->filhodir = pnovo;
    }
}

return pnovo;
}

int altura_arvore_aux(NO *no) {
if (no == NULL) return -1;
int esq = altura_arvore_aux(no->filhoesq);
int dir = altura_arvore_aux(no->filhodir);
return ((esq > dir) ? esq : dir) + 1;
}

int altura_arvore(ARVORE_BINARIA *arvore) {
return altura_arvore_aux(arvore->raiz);
}

int inserir_aux(NO *raiz, int itemNovo){
    if(raiz->item > itemNovo){
        if(raiz->filhoesq != NULL){
            return inserir_aux(raiz->filhoesq, itemNovo);

        }else{
            return(inserir_filho(FILHO_ESQ, raiz, itemNovo) != NULL);
        }
    }

    if(raiz->item < itemNovo){
        if(raiz->filhodir != NULL){
            return inserir_aux(raiz->filhodir, itemNovo);
        }else{
            return (inserir_filho(FILHO_DIR, raiz, itemNovo) != NULL);
            }
        }else{
            return 0;
            }
}

int inserir_auxVoto(VOTOS *raiz, int itemNovo, int votoNovo){
    if(raiz->titulo > itemNovo){
        if(raiz->filhoesq != NULL){
            return inserir_auxVoto(raiz->filhoesq, itemNovo, votoNovo);

        }else{
            return(inserir_filhoVoto(FILHO_ESQ, raiz, itemNovo, votoNovo) != NULL);
        }
    }

    if(raiz->titulo < itemNovo){
        if(raiz->filhodir != NULL){
            return inserir_auxVoto(raiz->filhodir, itemNovo, votoNovo);
        }else{
            return (inserir_filhoVoto(FILHO_DIR, raiz, itemNovo, votoNovo) != NULL);
            }
        }else{
            return 0;
            }
}


int inserir(ARVORE_BINARIA *arvore, int item){
    if(vazia(arvore)){
            return (criar_raiz(arvore, item) != NULL);

            }else {
                return inserir_aux(arvore->raiz, item);
            }
}

int inserirVoto(ARVORE_VOTOS *arvore, int item, int v0to){
    if(vaziaVoto(arvore)){
            return (criar_raizVoto(arvore, item, v0to) != NULL);

            }else {
                return inserir_auxVoto(arvore->raiz, item, v0to);
            }
}

int remove_abb_aux(ARVORE_BINARIA *arv, NO *prem, NO *pant, int chave){
    if (prem == NULL){
        return 0;
    }else if (prem->item > chave){
        return remove_abb_aux(arv, prem->filhoesq, prem, chave);
    }else if (prem->item < chave){
        return remove_abb_aux(arv, prem->filhodir, prem, chave);
    }else {
        if (prem->filhoesq == NULL || prem->filhodir == NULL){
            NO *pprox = (prem->filhoesq == NULL) ? prem->filhodir : prem->filhoesq;

            if (pant == NULL) arv->raiz = pprox;
            else if (prem == pant->filhoesq) pant->filhoesq = pprox;
            else pant->filhodir = pprox;

            free(prem);
         }else{
            troca_max_esq(prem->filhoesq, prem, prem);
            }
            return 1;
    }

}



int remove_abb(ARVORE_BINARIA *arv, int chave){
    return remove_abb_aux(arv, arv->raiz, NULL, chave);
}


void troca_max_esq(NO *ptroca, NO *prem, NO *pant){
    if(ptroca->filhodir == NULL){
        troca_max_esq(ptroca->filhodir, prem, ptroca);
    }

    if(prem == pant ) pant->filhoesq = ptroca->filhoesq;
    else pant->filhodir = ptroca-> filhoesq;

    prem->item = ptroca->item;
    free(ptroca);
}

int remove_voto(ARVORE_VOTOS *arv, int chave){
    return remove_voto_aux(arv, arv->raiz, NULL, chave);
}

int remove_voto_aux(ARVORE_VOTOS *arv, VOTOS *prem, VOTOS *pant, int chave){
    if (prem == NULL){
        return 0;
    }else if (prem->titulo > chave){
        return remove_voto_aux(arv, prem->filhoesq, prem, chave);
    }else if (prem->titulo < chave){
        return remove_voto_aux(arv, prem->filhodir, prem, chave);
    }else {
        if (prem->filhoesq == NULL || prem->filhodir == NULL){
            VOTOS *pprox = (prem->filhoesq == NULL) ? prem->filhodir : prem->filhoesq;

            if (pant == NULL) arv->raiz = pprox;
            else if (prem == pant->filhoesq) pant->filhoesq = pprox;
            else pant->filhodir = pprox;

            free(prem);
         }else{
            troca_maxVoto_esq(prem->filhoesq, prem, prem);
            }
            return 1;
    }

}

void troca_maxVoto_esq(VOTOS *ptroca, VOTOS *prem, VOTOS *pant){
    if(ptroca->filhodir == NULL){
        troca_maxVoto_esq(ptroca->filhodir, prem, ptroca);
    }

    if(prem == pant ) pant->filhoesq = ptroca->filhoesq;
    else pant->filhodir = ptroca-> filhoesq;

    prem->titulo = ptroca->titulo;
    prem->voto = ptroca->voto;
    free(ptroca);
}
