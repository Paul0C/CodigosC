#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_MAX_REG 130

void atualizaCabeca(int cabeca){
    FILE *arqTopo;
    int led = cabeca;
    arqTopo = fopen("dados.dat", "rb+");
    fseek(arqTopo, 0, SEEK_SET);
    fwrite(&led, sizeof(int), 1, arqTopo);
    fclose(arqTopo);
}

int topoled(){
    FILE *arqTopo;
    int led;
    arqTopo = fopen("dados.dat", "rb");
    fseek(arqTopo, 0, SEEK_SET);
    fread(&led, sizeof(int), 1, arqTopo);

    fclose(arqTopo);
    return led;
}

void imprimir_led(){
    FILE *arqLed;
    int offset, byte;

    arqLed = fopen("dados.dat", "rb");
    offset = topoled();
    if(offset == -1){
        printf("\nA Led está vazia.");
    }else{
        printf("\nOffsets disponíveis:\n");
        printf("%d, ", offset);
        fseek(arqLed, (offset + 1), SEEK_SET);
        fread(&offset, sizeof(int), 1, arqLed);
        while(offset != -1){
            printf("%d, ", offset);
            fseek(arqLed, (offset + 1), SEEK_SET);
            fread(&offset, sizeof(int), 1, arqLed);
        }
    }

    fclose(arqLed);
}

void atualizaLedIns(int anterior, int prox){
    FILE *arqLed;
    int reg, topo, tam, ant, tell, aux, proximo, teste;
    ant = anterior;
    proximo = prox;
    arqLed = fopen("dados.dat", "rb+");
    fseek(arqLed, (anterior + 1), SEEK_SET);
    tell = ftell(arqLed);
    fwrite(&proximo, sizeof(int), 1, arqLed);
    fseek(arqLed, -4, SEEK_CUR);
    fread(&teste, sizeof(int), 1, arqLed);

    fclose(arqLed);
}

void atualizaLed(int led){
    FILE *arqLed;
    int reg;
    reg = led;
    arqLed = fopen("dados.dat", "rb+");
    fseek(arqLed, 0, SEEK_SET);
    fwrite(&reg, sizeof(int), 1, arqLed);
    fclose(arqLed);
}

int retornaAnt(int tamanhoReg){
    FILE *arqBusca;
    int topo, tam, tell, byteoff, ant;
    short offSet;
    char registro[130];
    arqBusca = fopen("dados.dat", "rb");
    topo = topoled();
    fseek(arqBusca, (topo - 2), SEEK_SET);
    fread(&offSet, sizeof(short), 1, arqBusca);
    tell = ftell(arqBusca);
    fseek(arqBusca, (topo + 1), SEEK_SET);
    ant = ftell(arqBusca);
    fread(&byteoff, sizeof(int), 1, arqBusca);
    while(offSet < tamanhoReg && byteoff != -1){
        fseek(arqBusca, (byteoff - 2), SEEK_SET);
        fread(&offSet, sizeof(short), 1, arqBusca);
        tell = ftell(arqBusca);
        fseek(arqBusca, (byteoff + 1), SEEK_SET);
        fread(&byteoff, sizeof(int), 1, arqBusca);

        if(offSet < tamanhoReg){
             ant = tell;
        }
    }
    fclose(arqBusca);
    return ant - 1;
}

int verificaLed(int tamanhoReg){
    FILE *arqBusca;
    int topo, tam, tell, byteoff, ant;
    short offSet;
    char registro[130];
    arqBusca = fopen("dados.dat", "rb");
    topo = topoled();
    fseek(arqBusca, (topo - 2), SEEK_SET);
    fread(&offSet, sizeof(short), 1, arqBusca);
    tell = ftell(arqBusca);
    fseek(arqBusca, (topo + 1), SEEK_SET);
    fread(&byteoff, sizeof(int), 1, arqBusca);
    while(offSet < tamanhoReg && byteoff != -1){
        ant = byteoff;
        fseek(arqBusca, (byteoff - 2), SEEK_SET);
        fread(&offSet, sizeof(short), 1, arqBusca);
        tell = ftell(arqBusca);
        fseek(arqBusca, (byteoff + 1), SEEK_SET);
        fread(&byteoff, sizeof(int), 1, arqBusca);
        /*
        if(offSet < tamanhoReg){
            fseek(arqBusca, 1, SEEK_CUR);
            fread(&tam, sizeof(int), 1, arqBusca);
            printf("TAM %d", tam);
            fseek(arqBusca, (tam - 2), SEEK_SET);
            printf("TAM %d", tam);
        }*/
    }

    if(tam == -1){
        printf("Não foi possível encontrar espaço disponível na LED.\n");
        printf("\n");
        fclose(arqBusca);
        return 0;
    }
    fclose(arqBusca);
    return tell;

}

void importar(char *argv){
        FILE *arqBase;
        FILE *arqToDat;
        char *registro;
        arqBase = fopen(argv, "r");

        if(arqBase == NULL){
            printf("ERRO ao tentar abrir arquivo ! \n");
            exit(1);
        }else{
            printf("Sucesso ao abrir o arquivo base.\n");
        }

        arqToDat = fopen("dados.dat", "wb");

        if(arqToDat == NULL){
            printf("ERRO ao tentar abrir arquivo %s!\n", arqToDat);
            exit(1);
        }else{
            printf("Sucesso ao abrir o arquivo binário.\n");
        }

        char buffer[TAM_MAX_REG];
        short comp_reg;

        int LED = -1;

        fwrite(&LED, sizeof(LED), 1, arqToDat);
        //Enquanto o arquivo nao chegou no final e sem erro no arquivo
        while(!feof(arqBase) && !ferror(arqBase)){
            //Se fgets diferente de NULL () entao tem linhas para ler
            if(fgets(buffer, TAM_MAX_REG, arqBase) != NULL){

                comp_reg = strlen(buffer);
                fwrite(&comp_reg, sizeof(comp_reg), 1, arqToDat);
                fwrite(buffer, sizeof(char), comp_reg, arqToDat);
            }
        }


        printf("Importação realizada com sucesso!\n");

        fclose(arqBase);
        fclose(arqToDat);

}

void busca(int iden){
    FILE *arqBusca;
    char barra, id[TAM_MAX_REG], *pula, registro[130], *registro2;
    int i = iden, cont, ID, tam;
    arqBusca = fopen("dados.dat", "rb");

    if(arqBusca == NULL){
        printf("Erro ao abrir o arquivo.\n");
    }

    printf("\nBusca pelo registro de chave \"%d\"\n", i);

    fseek(arqBusca, 6, SEEK_SET);
    while(!feof(arqBusca) && ID != i){
            fgets(id, TAM_MAX_REG, arqBusca);
            strcpy(registro, id);
            pula = strtok(id, "|");
            ID = atoi(pula);
            if(ID != i){
                fseek(arqBusca, 2, SEEK_CUR);
            }
    }

    if(ID == i){
        registro2 = strtok(registro, "\n");
        printf("%s", registro2);
        printf(" (%d bytes)\n", strlen(registro2));
    }else{
        printf("Erro:Registro não encontrado\n");
        printf("\n");
    }

    fclose(arqBusca);
}

void remover(int iden){
    FILE *arqBusca;
    int topoLed, comp, offset;
    char barra, id[TAM_MAX_REG], *pula, registro[130], *registro2, *ver;
    int i = iden, cont, ID;
    arqBusca = fopen("dados.dat", "rb+");

    if(arqBusca == NULL){
        printf("Erro ao abrir o arquivo.\n");
    }

    printf("Remoção do registro de chave \"%d\"\n", i);

    fseek(arqBusca, 6, SEEK_SET);
    while((ID != i) &&  ver != NULL){
            ver = fgets(id, TAM_MAX_REG, arqBusca);
            strcpy(registro, id);
            pula = strtok(id, "|");
            ID = atoi(pula);
            if(ID != i){
                fseek(arqBusca, 2, SEEK_CUR);
            }
    }

    if(ID == i){
        comp = strlen(registro);
        registro2 = strtok(registro, "\n");
        int comp1 = strlen(registro2);
        fseek(arqBusca, -comp, SEEK_CUR);
        offset = ftell(arqBusca);
        fputc('*', arqBusca);
        topoLed = topoled();
        fwrite(&topoLed, sizeof(int), 1, arqBusca);
        atualizaLed(offset);
        topoLed = topoled();
        printf("Registro removido! (%d bytes)\n", comp1);
        printf("Local: offset = %d bytes (0x%04hx)\n", offset, offset);
        printf("\n");
    }else{
        printf("Erro: registro não encontrado!\n");
        printf("\n");
    }

    fclose(arqBusca);
}

void inseri(char registro[TAM_MAX_REG]){
    FILE *arqIns;
    char reg[TAM_MAX_REG], *id;
    int offSet;
    int cabeca, tell, verir, chave, ant, proxx;

    arqIns = fopen("dados.dat", "rb+");
    strcpy(reg, registro);
    id = strtok(registro, "|");
    chave = atoi(id);
    short tam = strlen(reg);
    printf("\nInserção do registro de chave \"%d\" (%d bytes)\n", chave, (tam - 1));


    if(topoled() == -1){
        fseek(arqIns, 0, SEEK_END);
        fputc('\n', arqIns);
        fwrite(&tam, sizeof(short), 1, arqIns);
        fwrite(&reg, sizeof(char), (strlen(reg)-1), arqIns);
        printf("Local: fim do arquivo\n");
        printf("\n");
    }else{
        offSet = verificaLed(strlen(reg));
        fseek(arqIns, offSet - 2, SEEK_SET);
        short sub;
        fread(&sub, sizeof(short), 1, arqIns);
        if(offSet != 0){
            fseek(arqIns, (offSet + 1), SEEK_SET);
            fread(&verir, sizeof(int), 1, arqIns);
            if(verir == -1){
                fseek(arqIns, (offSet - 2), SEEK_SET);
                fwrite(&tam, sizeof(short), 1, arqIns);
                fwrite(&reg, sizeof(char), (strlen(reg)-1), arqIns);
                atualizaLed(-1);
                cabeca = topoled();
                printf("Tamanho do espaço reutilizado:%d bytes\n", sub - 1);
                printf("Local: offset = %d bytes (0x%04hx)\n", offSet, offSet);
                printf("\n");
            }else if(offSet == topoled()){
                fseek(arqIns, (offSet + 1), SEEK_SET);
                fread(&verir, sizeof(int), 1, arqIns);
                fseek(arqIns, (offSet - 2), SEEK_SET);
                fwrite(&tam, sizeof(short), 1, arqIns);
                fwrite(&reg, sizeof(char), (strlen(reg)-1), arqIns);
                atualizaCabeca(verir);
                cabeca = topoled();
                printf("Tamanho do espaço reutilizado:%d bytes\n", sub -1);
                printf("Local: offset = %d bytes (0x%04hx)\n", offSet, offSet);
                printf("\n");
            }else{
                fseek(arqIns, (offSet + 1), SEEK_SET);
                fread(&proxx, sizeof(int), 1, arqIns);
                ant = retornaAnt(strlen(reg));
                fseek(arqIns, (offSet - 2), SEEK_SET);
                fwrite(&tam, sizeof(short), 1, arqIns);
                fwrite(&reg, sizeof(char), (strlen(reg)-1), arqIns);
                atualizaLedIns(ant, verir);
                cabeca = topoled();
                printf("Tamanho do espaço reutilizado:%d bytes\n", sub - 1);
                printf("Local: offset = %d bytes (0x%04hx)\n", offSet, offSet);
                printf("\n");
            }

        }else{
            fseek(arqIns, 0, SEEK_END);
            fputc('\n', arqIns);
            fwrite(&tam, sizeof(short), 1, arqIns);
            fwrite(&reg, sizeof(char), (strlen(reg)-1), arqIns);
            printf("Local: fim do arquivo\n");
            printf("\n");
        }
    }
    fclose(arqIns);
}

void executar_operacoes(char *argv){

    FILE *arqOp;
    char op, oop[TAM_MAX_REG];
    int id;

    arqOp = fopen(argv, "r");

    while(!feof(arqOp)){
        op = fgetc(arqOp);
        if(op == 'b'){
            fseek(arqOp, 1, SEEK_CUR);
            fgets(oop, TAM_MAX_REG, arqOp);
            id = atoi(oop);
            busca(id);
        }
        if(op == 'i'){
            fseek(arqOp, 1, SEEK_CUR);
            fgets(oop, TAM_MAX_REG, arqOp);
            inseri(oop);
        }
        if(op == 'r'){
            fseek(arqOp, 1, SEEK_CUR);
            fgets(oop, TAM_MAX_REG, arqOp);
            id = atoi(oop);
            remover(id);
        }
    }

    fclose(arqOp);

}


int main(int argc, char *argv[]) {

    if (argc == 3 && strcmp(argv[1], "-i") == 0) {

        printf("Modo de importacao ativado ... nome do arquivo = %s\n", argv[2]);
        importar(argv[2]);

    } else if (argc == 3 && strcmp(argv[1], "-e") == 0) {

        printf("Modo de execucao de operacoes ativado ... nome do arquivo = %s\n", argv[2]);
        executar_operacoes(argv[2]);

    } else if (argc == 2 && strcmp(argv[1], "-p") == 0) {

        printf("Modo de impressao da LED ativado ...\n");
        imprimir_led();

    } else {

        fprintf(stderr, "Argumentos incorretos!\n");
        fprintf(stderr, "Modo de uso:\n");
        fprintf(stderr, "$ %s (-i|-e) nome_arquivo\n", argv[0]);
        fprintf(stderr, "$ %s -p\n", argv[0]);
        exit(EXIT_FAILURE);

    }

    return 0;
}
