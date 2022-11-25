
struct Cliente{
    char nome[30], endereco[100], bairro[80], telefone[15], sexo[10], cpf[15], data_nasc[15], plano[15];
};

int cad_cliente(struct Cliente vetor[100], int posicao);
void listar_cliente(struct Cliente vetor[100], int pos);
void atualizar_cliente(struct Cliente vetor[100], int pos);
void escolher_plano(struct Cliente vetor[100], int pos);


