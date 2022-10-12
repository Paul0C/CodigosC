#include<stdio.h>
#include<stdlib.h>
#include"TadLista.c"

void main(){

AGENDA *Agenda;
int valor;
REGISTRO elemento;

 do
 {

        printf("Digite 1 para Criar uma agenda.\n");
        printf("Digite 2 para Inserir um usuário na agenda.\n");
        printf("Digite 3 para remover um usuário da agenda\n");
        printf("Digite 4 para buscar um usuário na agenda.\n");
        printf("Digite 5 para deletar a agenda.\n");
        printf("Digite 6 para imprimir a agenda.\n");
        printf("Digite 7 para Sair do programa.\n");
        scanf("%d", &valor);
        fflush(stdin);

        switch (valor)
        {

        case 1:
            Agenda = criar_agenda(Agenda);

            break;

        case 2:

            printf("Insira o nome da pessoa\n");
            gets(elemento.nome);
            fflush(stdin);
            printf("Insira o telefone\n");
            scanf("%d", &elemento.telefone);
            fflush(stdin);
            printf("Insira o endereco\n");
            gets(elemento.endereco);
            fflush(stdin);


            inserir(Agenda, elemento);

            break;

        case 3:
            printf("Insira o nome da pessoa que deseja remover.\n");
            gets(elemento.nome);
            remover(Agenda, elemento);

            break;

        case 4:
            printf("Insira o nome da pessoa que você deseja buscar.\n");
            gets(elemento.nome);
            buscar(Agenda, elemento);

            break;

        case 5:
            Agenda =  deletar(Agenda);
            break;

        case 6:
            imprimir(Agenda);
            break;

        case 7:
            exit(1);

        default:
            printf("opcao invalida, favor escolher uma das opcoes validas\n\n");
        }
    } while (valor != 7);



}
