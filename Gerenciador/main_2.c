#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "cadfuncionario.h"
#include "cadcliente.h"

void main(){
    setlocale(LC_ALL, "Portuguese");

    struct Cliente cliente_cadastro[100];
    struct Funcionario funcionario_cadastro[100];
    char user[15], password[8];
    int op, op_2, posi_func = 0, posi_clie = 0,  i = 0, tenta_logar;
    bool login_sucess;

    do{
        printf("====/ TELA INCIAL /====\n\n");
        printf("[1] - Login\n");
        printf("[2] - Cadastrar Funcionario\n");
        printf("[3] - Esqueci a senha\n\n");
        printf("[0] - Sair\n");
        printf("Opção: ");
        scanf("%i", &op);
        fflush(stdin);
        tenta_logar = 1;
        system("cls");

        switch(op){
            case 1: do{
                        system("cls");
                        login_sucess = false;
                        printf("======/ LOGIN /======");
                        printf("\nUser: ");
                        gets(user);
                        printf("\nPassword: ");
                        gets(password);

                        if(posi_func == 0){
                            printf("\nNão a ninguém cadastrado no sistema!\n");
                            carregar(3, "VOLTANDO");
                        }else {
                            system("cls");
                            for(i=0; i < posi_func && login_sucess == false; i++){
                                if(strcmp(user, funcionario_cadastro[i].user) == 0 && strcmp(password, funcionario_cadastro[i].password) == 0){
                                    login_sucess = true;
                                    carregar(3, "CARREGANDO");
                                    do{
                                        printf("\n\a====/ LOGIN SUCCESS /====\n\n");
                                        printf("Funcionário(a): %s\n", funcionario_cadastro[i].nome);
                                        printf("\n[1] - Cadastra cliente\n");
                                        printf("[2] - Listar Clientes\n");
                                        printf("[3] - Listar Funcionarios\n");
                                        printf("[4] - Alterar dados do cliente\n");
                                        printf("[5] - Alterar dados do funcionário\n");
                                        printf("[6] - Relátorios\n");
                                        printf("[0] - Deslogar\n");
                                        printf("\nOpção: ");
                                        scanf("%i", &op_2);
                                        fflush(stdin);
                                        system("cls");

                                        switch(op_2){
                                            case 1: posi_clie = cad_cliente(cliente_cadastro, posi_clie);
                                                    break;
                                            case 2: listar_cliente(cliente_cadastro, posi_clie);
                                                    break;
                                            case 3: listar_funcionarios(funcionario_cadastro, posi_func);
                                                    break;
                                            case 4: atualizar_cliente(cliente_cadastro, posi_clie);
                                                    break;
                                            case 5: atualizar_Funcionario(funcionario_cadastro, posi_func);
                                                    break;
                                            case 6: relatorios(cliente_cadastro, funcionario_cadastro,posi_clie, posi_func);
                                                    break;
                                            case 0: carregar(3, "SAINDO");
                                                    break;
                                        }
                                    }while(op_2 != 0);
                                }
                            }
                            if(login_sucess == false){
                                printf("Usuario ou senha invalido\n");
                                tenta_logar ++;
                                sleep(1);
                                if(tenta_logar == 3){
                                    printf("\nVocê tentou logar 2 vezes\n");
                                    carregar(3, "VOLTANDO");
                                }
                            }
                         }

                    }while(login_sucess == false && posi_func != 0 && tenta_logar <= 2);
                    break;

            case 2: carregar(3, "CARREGANDO");
                    posi_func = cad_funcionario(funcionario_cadastro, posi_func);
                    break;
            case 3: carregar(3, "CARREGANDO");
                    esqueci_senha(funcionario_cadastro, posi_func);
                    break;
            case 0: carregar(3, "SAINDO DO SISTEMA");
                    break;
            default: printf("Opção invalida! Tente novamente...\n");
        };

    }while(op != 0);
}
void relatorios(struct Cliente vetor[100], struct Funcionario vetor_2[100], int pos_cli, int pos_func){
    char resp;
    int op, i, qtd_m = 0, qtd_e = 0, qtd_dev = 0, qtd_ana = 0, qtd_recep = 0, qtd_estag = 0;
    float total_m = 0, total_e = 0, total_s = 0, despesa = 0, receita = 0, insumos = 0,cont_agua = 0, cont_luz= 0, contas=0, aluguel = 0;

    printf("Informe os valores das contas:");
    printf("\nValor da conta de água R$: ");
    scanf("%f", &cont_agua);
    printf("\nValor da conta de luz R$: ");
    scanf("%f", &cont_luz);
    printf("\nValor do aluguel R$: ");
    scanf("%f", &aluguel);
    printf("\nHouve outras despesas (s/n)? \n");
    resp = getche();
    resp = tolower(resp);
    contas = cont_agua + cont_luz + aluguel;

    if(resp=='s'){
        printf("\nQual foi o valor da despesa? R$: ");
        scanf("%f", &insumos);
        contas = contas + insumos;
    }

    for(i = 0; i < pos_cli; i++){
        if(strcmp(vetor[i].plano, "Evolution") == 0){
            qtd_e++;
            total_e += 1300;
        }
        if(strcmp(vetor[i].plano, "Master") == 0){
                    qtd_m++;
                    total_m += 1800;
        }
    }
    receita = total_e + total_m;
    for (i = 0; i < pos_func; i++){
        total_s += vetor_2[i].salario;

        if(strcmp(vetor_2[i].cargo, "Desenvolvedor(a)") == 0)
            qtd_dev++;
        if(strcmp(vetor_2[i].cargo, "Estagiário(a)") == 0)
            qtd_estag++;
        if(strcmp(vetor_2[i].cargo, "Recepcionista") == 0)
            qtd_recep++;
    }

    despesa = total_s + contas;
    carregar(3, "CALCULANDO");
    printf("========/ RELATORIO /=========\n\n");
    printf("Aluguel mensal da empresa R$: %.2f \n", aluguel);
    printf("Conta de água e energia : R$: %.2f \n", cont_agua+cont_luz);
    printf("\n========/ Clientes /=========\n\n");
    printf("Total de clientes atuais: %i \n", pos_cli);
    printf("Quantidade de planos assinados:\n");
    printf("\tPacote Web Evolution: %i \n", qtd_e);
    printf("\tGanhos: R$: %.2f\n\n", total_e);
    printf("\tPacote Web Master: %i\n", qtd_m);
    printf("\tGanhos: R$: %.2f\n", total_m);
    printf("\n========/ Funcionários /=========\n\n");
    printf("Total de funcionários atuais na empresa: %i\n", pos_func);
    printf("\n\tTotal de Desenvolvedores(as): %i", qtd_dev);
    printf("\n\tTotal de Estagiário(a): %i", qtd_estag);
    printf("\n\tTotal de Recepcionista: %i \n\n", qtd_recep);
    if(despesa > receita){
        printf("No momento,a empresa está tendo um prejuizo.\n");
        printf("Déficit: R$ %.2f \n", despesa - receita);
    } else if(despesa < receita){
            printf("No momento, a empresa está tendo um lucro.\n");
            printf("Superavit: R$ %.2f \n", receita - despesa);
       }

    system("pause");
    system("cls");

};
