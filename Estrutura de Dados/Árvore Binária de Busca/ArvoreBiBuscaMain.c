#include<stdio.h>
#include <locale.h>
#include"ArvoreBiBusca.c"

void main(){
    setlocale (LC_ALL, "Portuguese_Brazil");
    ARVORE_BINARIA *ArvoreTitulo;
    ARVORE_VOTOS *ArvoreVoto;
    NO *votin;
    VOTOS *votin2, *votin3;
    int busca1, busca2, busca3, busca4, itemm, tit, teste, teste2, valor, valor1, voto;

        ArvoreTitulo = criar_arvore();
        ArvoreVoto = criar_arvoreVoto();


        printf("Insira 10 títulos de eleitor:");
        for(int i = 0; i<10; i++){
            printf("\nInsira o %d título:", i+1);
            scanf("%d", &itemm);
            inserir(ArvoreTitulo, itemm);
            fflush(stdin);
        }

        do
        {
            printf("\n...------------------------------------------------...\n");
            printf("MENU\n");
            printf("Digite 1 para VOTAR \n");
            printf("Digite 2 para RETIRAR O VOTO\n");
            printf("Digite 3 para SAIR do programa.\n");
            printf("...------------------------------------------------...\n");
            scanf("%d", &valor);
            fflush(stdin);

            switch(valor)
            {
                case 1:

                    printf("Insira um título válido para votar:\n");
                    scanf("%d", &tit);
                    fflush(stdin);
                    votin = busca_aux(ArvoreTitulo->raiz, tit);
                    if(votin != NULL)
                    {
                        votin2 = buscaVoto_aux(ArvoreVoto->raiz, tit);
                        if(votin2  != NULL){
                             printf("Erro:Remova o voto e tente outra vez ou insira um título que ainda não votou.");
                        }else{
                            printf("\nInsira o voto para os candidatos:\n");
                            scanf("%d", &voto);
                            inserirVoto(ArvoreVoto, tit, voto);
                            teste = incrementa_voto(ArvoreTitulo->raiz, voto);
                        }
                    }else{
                        printf("Erro:Titulo inválido.");
                    }

                break;


                case 2:

                    printf("Insira um título válido para remover\n");
                    scanf("%d", &tit);
                    fflush(stdin);
                    votin3 = buscaVoto_aux(ArvoreVoto->raiz, tit);
                    if(votin3 != NULL)
                    {
                        valor1 = votin3->voto;
                        busca4 = remove_voto(ArvoreVoto, tit);
                        if( busca4 == 1)
                        {

                            teste2 = decrementa_voto(ArvoreTitulo->raiz, valor1);
                            printf("O voto foi removido com sucesso!\n");
                        }else{
                            printf("ERRO: o voto não foi removido");
                        }
                    }else{
                        printf("ERRO: o voto não foi encontrado\n");
                    }
                break;

            }
        }while(valor != 3);

         printf("\n\n");
         emordem(ArvoreTitulo);
         int maior = MostraMaior(ArvoreVoto->raiz);
         int menor = MostraMenor(ArvoreVoto->raiz);
         printf("\n\n");
         printf("Maior título que votou:%d\nMenor título que votou:%d", maior, menor);
         printf("\n\n");
         printf("\nLista de todos os números de títulos que votaram:\n");
         emordemm(ArvoreVoto);
         ArvoreTitulo = deletarArvoreTitulo(ArvoreTitulo);
         ArvoreVoto = deletarArvoreVoto(ArvoreVoto);
         printf("Programa encerrado.");



}
