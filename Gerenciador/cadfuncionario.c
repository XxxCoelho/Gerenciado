#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "cadfuncionario.h"

void escolher_cargo(struct Funcionario vetor[100], int pos){
    int op;

    fflush(stdin);
    do{
        printf("\nProfiss�es:\n");
        printf("\t [1] - Desenvolvedor(a)\n");
        printf("\t [2] - Estagi�rio(a)\n");
        printf("\t [3] - Recepcionista\n");
        printf("Escolha uma op��o: ");
        scanf("%i", &op);
        fflush(stdin);
        switch(op){
            case 1: strcpy(vetor[pos].cargo, "Desenvolvedor(a)");
                    vetor[pos].salario = 3300.00;
                    break;
            case 2: strcpy(vetor[pos].cargo, "Estagi�rio(a)");
                    vetor[pos].salario = 1200.00;
                    break;
            case 3: strcpy(vetor[pos].cargo, "Recepcionista");
                    vetor[pos].salario = 1800.00;
                    break;
            default: printf("\nEscolha a op��o certa dos cargos");
                     sleep(1);
                     system("cls");
        }
    }while(op != 1 && op != 2 && op != 3);

};

int cad_funcionario(struct Funcionario cadastro[100], int posicao){

    setlocale(LC_ALL, "Portuguese");

    int pos;
    char resp;

    fflush(stdin);
    do{
        if(posicao < 100){
            printf("=====/ CADASTRO DO(A) %i� FUNCION�RIO(A) /======\n\n", posicao +1);
            printf("=====/ Informa��es Pessoais /======\n\n");
            printf("Nome e sobrenome do(a) %i� funcion�rio(a): ", posicao+1);
            gets(cadastro[posicao].nome);
            printf("\nEndere�o: ");
            gets(cadastro[posicao].endereco);
            printf("\nBairro: ");
            gets(cadastro[posicao].bairro);
            printf("\nTelefone: ");
            gets(cadastro[posicao].telefone);
            printf("\nCPF: ");
            gets(cadastro[posicao].cpf);
            printf("\nG�nero: ");
            gets(cadastro[posicao].sexo);
            printf("\nData de nascimento: ");
            gets(cadastro[posicao].data_nasc);
            printf("\n\n=====/ Informa��es da profiss�o /======\n\n");
            escolher_cargo(cadastro, posicao);
            printf("\nDigite nome para login: ");
            gets(cadastro[posicao].user);
            printf("\nDigite uma senha de 6 d�gitos: ");
            gets(cadastro[posicao].password);
            fflush(stdin);
            printf("\n\n=====/ CADASTRO REALIZADO /=====\n");
            printf("Deseja continuar cadastrando (s/n)? ");
            resp = getche();
            resp = tolower(resp);
            posicao++;
            pos = posicao;
            sleep(1);
            system("cls");
        } else {
            printf("\nSua lista de funcion�rios est� lotada!\n\n ");
            resp = 'n';
            sleep(2);
            system("cls");
        }
    }while(resp =='s' && posicao< 100);
    printf("\nVoltando a tela inicial");
    carregar(3, "VOLTANDO");
    return pos;
};
void listar_funcionarios(struct Funcionario vetor[100], int pos){
    int i;
    carregar(3, "BUSCANDO");
    printf("=====/ INFORMA��ES /=====");
    for(i=0; i < pos; i++){
        printf("\nFuncion�rio(a): %s", vetor[i].nome);
        printf("\nInforma��es:");
        printf("\n\tData de nascimento: %s", vetor[i].data_nasc);
        printf("\n\tG�nero: %s", vetor[i].sexo);
        printf("\n\tEndere�o: %s", vetor[i].endereco);
        printf("\n\tBairro: %s", vetor[i].bairro);
        printf("\n\tTelefone: %s", vetor[i].telefone);
        printf("\n\tCPF: %s", vetor[i].cpf);
        printf("\n====/ INFORMA��ES DA CONTA /====\n");
        printf("User: %s", vetor[i].user);
        printf("\nCargo: %s", vetor[i].cargo);
        printf("\nSal�rio: R$ %.2f", vetor[i].salario);
        printf("\n\n");
    }
    system("pause");
    system("cls");

};

void carregar(int seg, char msg[10]){
    int i;

    printf("\n%s ", msg);

    for(i=0; i<seg; i++ ){
        printf("|||");
        sleep(1);
    }

    system("cls");
};

void atualizar_Funcionario(struct Funcionario vetor[100], int pos){
    int i, op;
    char cpf[15];
    bool achou = false;

    fflush(stdin);
    printf("Digite o seu CPF: ");
    gets(cpf);
    system("cls");
    carregar(3, "BUSCANDO");

    if(pos != 0){
        for(i=0; i < pos && achou == false; i++){
            if(strcmp(cpf, vetor[i].cpf) == 0){
                achou = true;
                do{
                    printf("\n====/ USU�RIO ENCONTRADO /====\n\n");
                    printf("\nNome: %s", vetor[i].nome);
                    printf("\nInforma��es:");
                    printf("\n\tData de nascimento: %s", vetor[i].data_nasc);
                    printf("\n\tG�nero: %s", vetor[i].sexo);
                    printf("\n\tEndere�o: %s", vetor[i].endereco);
                    printf("\n\tBairro: %s", vetor[i].bairro);
                    printf("\n\tTelefone: %s", vetor[i].telefone);
                    printf("\n\tCPF: %s", vetor[i].cpf);
                    printf("\n====/ INFORMA��ES DA CONTA /====\n");
                    printf("User: %s", vetor[i].user);
                    printf("\nPassoword: %s", vetor[i].password);
                    printf("\nCargo: %s", vetor[i].cargo);
                    printf("\n\n");
                    printf("Gostaria de alterar qual dado: ");
                    printf("\n[1] - Nome");
                    printf("\n[2] - Endere�o");
                    printf("\n[3] - Bairro");
                    printf("\n[4] - Telefone");
                    printf("\n[5] - Genero");
                    printf("\n[6] - Data de nascimento");
                    printf("\n[7] - CPF");
                    printf("\n[8] - Cargo");
                    printf("\n[9] - Usu�rio");
                    printf("\n[10] - Senha");
                    printf("\n[0] - Sair");
                    printf("\nEscolha um op��o: ");
                    scanf("%i", &op);
                    fflush(stdin);
                    system("cls");

                    switch(op){
                        case 1: printf("\nSeu nome atual: %s", vetor[i].nome);
                                printf("\nNovo nome: ");
                                gets(vetor[i].nome);
                                sleep(1);
                                system("cls");
                                break;
                        case 2: printf("\nSeu endere�o atual: %s", vetor[i].endereco);
                                printf("\nNovo endereco: ");
                                gets(vetor[i].endereco);
                                sleep(1);
                                system("cls");
                                break;
                        case 3: printf("\nSeu bairro atual: %s", vetor[i].bairro);
                                printf("Novo bairro: ");
                                gets(vetor[i].bairro);
                                break;
                        case 4: printf("\nSeu telefone atual: %s", vetor[i].telefone);
                                printf("\nNovo telefone com DDD: ");
                                gets(vetor[i].telefone);
                                sleep(1);
                                system("cls");
                                break;
                        case 5: printf("\nSeu sexo atual: %s", vetor[i].sexo);
                                printf("\nNovo sexo: ");
                                gets(vetor[i].sexo);
                                sleep(1);
                                system("cls");
                                break;
                        case 6: printf("\nSua data de nascimento atual: %s", vetor[i].data_nasc);
                                printf("\nNova data: ");
                                gets(vetor[i].data_nasc);
                                sleep(1);
                                system("cls");
                                break;
                        case 7: printf("\nSeu CPF atual: %s", vetor[i].cpf);
                                printf("\nNovo CPF: ");
                                gets(vetor[i].cpf);
                                sleep(1);
                                system("cls");
                                break;
                        case 8: printf("\nSeu cargo atual: %s", vetor[i].cargo);
                                escolher_cargo(vetor, i);
                                gets(vetor[i].cargo);
                                sleep(1);
                                system("cls");
                                break;
                        case 9: printf("\nSeu usu�rio atual: %s", vetor[i].user);
                                printf("\nNovo usuario: ");
                                gets(vetor[i].user);
                                sleep(1);
                                system("cls");
                                break;
                        case 10: printf("\nSua senha atual: %s", vetor[i].password);
                                printf("\nNova senha: ");
                                gets(vetor[i].password);
                                sleep(1);
                                system("cls");
                                break;

                        case 0: carregar(3, "SAINDO");
                                break;
                        default : printf("\nOp��o inv�lida! Tente novamente\n");
                                  sleep(2);
                                  system("cls");
                    }
                }while(op != 0);
            }
        }
        if(achou==false){
            printf("\nO CPF digitado n�o foi encontrado!\n");
            carregar(3, "VOLTANDO");
    }}else {printf("\nN�o h� ningu�m cadastrado\n");
            carregar(3, "VOLTANDO");
     }
};

void esqueci_senha(struct Funcionario vetor[100], int posicao){
    int i;
    char cpf[15];
    bool achou = false;

    fflush(stdin);
    printf("Digite o seu CPF: ");
    gets(cpf);
    system("cls");
    carregar(3, "BUSCANDO");

    if(posicao != 0){
        for(i=0; i < posicao && achou == false; i++){
            if(strcmp(cpf, vetor[i].cpf) == 0){
                achou = true;
                printf("\n====/ USU�RIO ENCONTRADO /====\n\n");
                printf("\nNome: %s", vetor[i].nome);
                printf("\n====/ INFORMA��ES DA CONTA /====\n");
                printf("User: %s \n\n", vetor[i].user);

                printf("Digite a nova senha: ");
                gets(vetor[i].password);
                printf("\nSenha trocada");
                carregar(3,"VOLTANDO");
            }
        }
        if(achou==false){
            printf("\nO CPF digitado n�o foi encontrado!\n");
            carregar(3, "VOLTANDO");
        }
    }else {printf("\nN�o h� ningu�m cadastrado\n");
            carregar(3, "VOLTANDO");
     }
};

