#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"TadLista.h"

 AGENDA *criar_agenda(AGENDA *agenda){
    agenda = (AGENDA*) malloc(sizeof(AGENDA));
    if(agenda != NULL){
        agenda->nroElem = 0;
        printf("A agenda foi criada com sucesso.\n");
        return agenda;
    }else{
        printf("ERRO:Agenda não criada");
    }
 }

 int cheia(AGENDA *agenda){
    if(agenda->nroElem == 50){
        return 1;
    }else{
        return 0;
    }
 }

 int inserir(AGENDA *agenda,  REGISTRO reg){
     int comp, nun;
     nun = agenda->nroElem;
        if(cheia(agenda) == 0){
            comp = strcmp(agenda->A[nun - 1].nome, reg.nome);
            while(comp > 0){
                strcpy(agenda->A[nun].nome, agenda->A[nun - 1].nome);
                agenda->A[nun].telefone = agenda->A[nun - 1].telefone;
                strcpy(agenda->A[nun].endereco, agenda->A[nun - 1].endereco);
                nun--;
                comp = strcmp(agenda->A[nun - 1].nome, reg.nome);
            }
            strcpy(agenda->A[nun].nome, reg.nome);
            agenda->A[nun].telefone = reg.telefone;
            strcpy(agenda->A[nun].endereco, reg.endereco);
            agenda->nroElem++;
            return 1;
        }
        return 0;
 }

 /*
 int remover(AGENDA *agenda, int telefone){
        int i = 0;

        for(i; agenda->A[i].telefone != telefone; i++){
            printf("%d", i);
        }


        while(i < agenda->nroElem){
            printf("%d", i);
            strcpy(agenda->A[i].nome, agenda->A[i+1].nome);
            agenda->A[i].telefone = agenda->A[i + 1].telefone;
            i++;
        }

        return 1;
 }*/

 int remover(AGENDA *agenda, REGISTRO reg){
    int comp, k, i = 0;
    if(agenda == NULL) return 0;
    if(agenda->nroElem == 0) return 0;

    comp = strcmp(agenda->A[i].nome, reg.nome);
    while((i < agenda->nroElem) &&  (comp != 0 )){
        i++;
        comp = strcmp(agenda->A[i].nome, reg.nome);
    }
    if (i == agenda->nroElem) return 0;

    for(k = i; k < agenda->nroElem-1; k++){
        strcpy(agenda->A[k].nome, agenda->A[k+1].nome);
        agenda->A[k].telefone = agenda->A[k+1].telefone;
        strcpy(agenda->A[k].endereco, agenda->A[k+1].endereco);
    }
    agenda->nroElem--;
    return 1;


 }

 int buscar(AGENDA *agenda, REGISTRO reg){
    int comp, i = 0;

    comp = strcmp(agenda->A[i].nome, reg.nome);
    while((i < agenda->nroElem) &&  (comp != 0 )){
        i++;
        comp = strcmp(agenda->A[i].nome, reg.nome);
    }
    if(i >= agenda->nroElem){
        printf("O usuário não está na lista.");
        return 0;
    }else{
        printf("Nome:%s\n", agenda->A[i].nome);
        printf("Telefone:%d\n", agenda->A[i].telefone);
        printf("Endereço:%s\n", agenda->A[i].endereco);

    }


 }


AGENDA* deletar(AGENDA *inicio){

    int i = 0;
    AGENDA *temp;
    temp = inicio->A[i];

    while(temp != NULL)
    {

        free(temp);
        i++;
        temp = inicio->A[i];
    }
    return inicio;

}



int imprimir(AGENDA *agenda){

        if(agenda->nroElem == 0){
            printf("\nA agenda está vazia.\n");
            return 0;
        }

        if(agenda == NULL){
            printf("A agenda não foi criada.");
            return 0;
        }

        for(int i = 0; i < agenda->nroElem; i++){
            printf("Nome:%s\n", agenda->A[i].nome);
            printf("Telefone:%d\n", agenda->A[i].telefone);
            printf("Endereço:%s\n", agenda->A[i].endereco);
        }
        return 1;

}
