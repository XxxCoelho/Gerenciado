#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "cadcliente.h"


void escolher_plano(struct Cliente vetor[100], int pos){
    int op;

    fflush(stdin);
    do{
        printf("\nPlanos disponíveis:\n");
        printf("\t [1] - Plano Web Evolution\n");
        printf("\t [2] - Plano Web Master\nQual foi o plano contratado: ");
        scanf("%i", &op);
        fflush(stdin);
        switch(op){
            case 1: strcpy(vetor[pos].plano, "Evolution");
                    break;
            case 2: strcpy(vetor[pos].plano, "Master");
                    break;
            default: printf("Escolha a opção certa dos planos");
                     sleep(1);
                     system("cls");
        }
    }while(op != 1 && op != 2);
};

int cad_cliente(struct Cliente cadastro[100], int posicao){

    setlocale(LC_ALL, "Portuguese");

    int pos;
    char resp;

    fflush(stdin);
    do{
        if (posicao < 100){
            printf("=====/ CADASTRO DO(A) %iº CLIENTE /======\n\n", posicao +1);
            printf("=====/ Informações Pessoais /======\n\n");
            printf("Nome e sobrenome do(a) %iº cliente: ", posicao+1);
            gets(cadastro[posicao].nome);
            printf("\nEndereço: ");
            gets(cadastro[posicao].endereco);
            printf("\nBairro: ");
            gets(cadastro[posicao].bairro);
            printf("\nTelefone: ");
            gets(cadastro[posicao].telefone);
            printf("\nCPF: ");
            gets(cadastro[posicao].cpf);
            printf("\nGênero: ");
            gets(cadastro[posicao].sexo);
            printf("\nData de nascimento: ");
            gets(cadastro[posicao].data_nasc);
            escolher_plano(cadastro, posicao);
            fflush(stdin);
            printf("\n\n=====/ CADASTRO REALIZADO /=====\n");
            printf("\nDeseja continuar cadastro (s/n)? ");
            resp = getche();
            resp = tolower(resp);
            posicao++;
            pos = posicao;
            sleep(1);
            system("cls");
        } else {
            printf("Sua lista está lotada!\n\n");
            resp = 'n';
            sleep(2);
            system("cls");
         }
    }while(resp =='s');
    printf("\nVoltando a tela inicial");
    carregar(3, "VOLTANDO");
    return pos;

};

void listar_cliente(struct Cliente vetor[100], int pos){
    int i;
    if (pos == 0){
        printf("Lista de clientes vazia!\n");
        printf("Cadastre um cliente\n\n");
        carregar(3, "VOLTANDO");
    }else {
        carregar(3, "BUSCANDO");
        printf("=====/ INFORMAÇÕES /=====");
        for(i=0; i < pos; i++){
            printf("\nNome: %s", vetor[i].nome);
            printf("\nInformações:");
            printf("\n\tData de nascimento: %s", vetor[i].data_nasc);
            printf("\n\tGênero: %s", vetor[i].sexo);
            printf("\n\tEndereço: %s", vetor[i].endereco);
            printf("\n\tBairro: %s", vetor[i].bairro);
            printf("\n\tTelefone: %s", vetor[i].telefone);
            printf("\n\tCPF: %s", vetor[i].cpf);
            printf("\n\tPlano: %s", vetor[i].plano);
            printf("\n\n");
        }
        system("pause");
        system("cls");
     }
};

void atualizar_cliente(struct Cliente vetor[100], int pos){
    int i, op;
    char cpf[15];
    bool achou = false;

    fflush(stdin);
    printf("Digite o CPF do cliente: ");
    gets(cpf);
    system("cls");
    carregar(3, "BUSCANDO");

    if(pos != 0){
        for(i=0; i < pos && achou == false; i++){
            if(strcmp(cpf, vetor[i].cpf) == 0){
                achou = true;
                do{
                    printf("\nUsuário encontrado!\n");
                    printf("\nNome: %s", vetor[i].nome);
                    printf("\nInformações:");
                    printf("\n\tData de nascimento: %s", vetor[i].data_nasc);
                    printf("\n\tGênero: %s", vetor[i].sexo);
                    printf("\n\tEndereço: %s", vetor[i].endereco);
                    printf("\n\tBairro: %s", vetor[i].bairro);
                    printf("\n\tTelefone: %s", vetor[i].telefone);
                    printf("\n\tCPF: %s", vetor[i].cpf);
                    printf("\n\tPlano: %s", vetor[i].plano);
                    printf("\n\n");
                    printf("Gostaria de alterar qual dado: ");
                    printf("\n[1] - Nome");
                    printf("\n[2] - Endereço");
                    printf("\n[3] - Bairro");
                    printf("\n[4] - Telefone");
                    printf("\n[5] - Sexo");
                    printf("\n[6] - Data de nascimento");
                    printf("\n[7] - CPF");
                    printf("\n[8] - Plano");
                    printf("\n[0] - Sair");
                    printf("\nEscolha um opção: ");
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
                        case 2: printf("\nSeu endereço atual: %s", vetor[i].endereco);
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
                        case 5: printf("\nSeu gênero atual: %s", vetor[i].sexo);
                                printf("\nNovo gênero: ");
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
                        case 8: printf("\nSeu plano atual: %s", vetor[i].plano);
                                escolher_plano(vetor, i);
                                sleep(1);
                                system("cls");
                                break;
                        case 0: carregar(3, "SAINDO");
                                break;
                        default : printf("\nOpção inválida! Tente novamente\n");
                                  sleep(2);
                                  system("cls");
                    }
                }while(op != 0);
            }
        }
        if(achou==false){
            printf("\nO CPF digitado não foi encontrado!\n");
            carregar(3, "VOLTANDO");
    }}else {printf("\nNão há ninguém cadastrado\n");
            carregar(3, "VOLTANDO");
     }
};


