struct Funcionario{
    char nome[30], endereco[100], bairro[80], telefone[15], sexo[10], cpf[15], user[10], password[6], data_nasc[15], cargo[25];
    float salario;
};

int cad_funcionario(struct Funcionario vetor[100], int posicao);
void esqueci_senha(struct Funcionario vetor[100], int posicao);
void listar_funcionarios(struct Funcionario vetor[100], int pos);
void atualizar_Funcionario(struct Funcionario vetor[100], int pos);
void escolher_cargo(struct Funcionario vetor[100], int pos);
void carregar(int seg, char msg[10]);
