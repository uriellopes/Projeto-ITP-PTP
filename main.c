#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{ //Registo para armazenar a data de validade
    int dia;
    int mes;
    int ano;
}Data;

typedef struct { //Registo para armazenar as informações do produto
    char nome[50];
    int categoria;
    int codigo;
    float preco;
    char descricao[100];
    char fabricante[50];
    Data validade;
    int corredor;
    int prateleira;
    int qtdestoque;
}Produto;

typedef struct{ //Registro para armazenar os itens do carrinho
    char nome[50];
    float preco;
    int quantidade;
}Carrinho;

void buscarNome(Produto *produto){ //Função para buscar produtos por nome
    char nomeProduto[50];
    int i;
    printf("Digite o nome do produto desejado: \n");
    scanf("%s",nomeProduto);
    for(i = 0; i < 10; i++) {
        if(strcmp(nomeProduto,produto[i].nome) == 0) {
            printf("Produto: %s Preço: R$%.2f\n",produto[i].nome,produto[i].preco);
        }
    }
}

void buscarFabricante(Produto *produto) { //Função para buscar produtos por fabricante
    char nomeFabricante[50];
    int i;
    printf("Digite o fabricante do produto: \n");
    scanf("%s",nomeFabricante);
    for(i = 0; i < 10; i++) {
        if(strcmp(nomeFabricante,produto[i].fabricante) == 0) {
            printf("Produto: %s Preço:%.2f Fabricante: %s\n",produto[i].nome,produto[i].preco,produto[i].fabricante);
        }
    }
}

void buscarPreco(Produto *produto){  //Funcao para ordenar os produtos do menor para o maior preço
    int i,j;
    float aux;
    for(i = 0; i < 10; i++) { //Ordenando os produtos de acordo com o preço
        for(j = i + 1; j < 10; j++) {
            if(produto[i].preco > produto[j].preco){
                aux = produto[i].preco;
                produto[i].preco = produto[j].preco;
                produto[j].preco = aux;
            }
        }
    }
    for(i = 0; i < 10; i++) { //Mostrando os produtos ja ordenados de acordo com o preço
        printf("Produto: %s Preço: R$%.2 \n",produto[i].nome,produto[i].preco);
    }
}

void buscarQtdEstoque(Produto *produto) { //Funcao para ordenar os produtos da menor para a maior quantidade no estoque
    int i,j,aux;
    for(i = 0; i < 10; i++) { //Ordenando os produtos de acordo com a quantidade no estoque
        for(j = i + 1; j < 10; j++) {
            if(produto[i].qtdestoque > produto[j].qtdestoque) {
                aux = produto[i].qtdestoque;
                produto[i].qtdestoque = produto[j].qtdestoque;
                produto[j].qtdestoque = aux;
            }
        }
    }
    for(i = 0; i < 10; i++) {  //Mostrando os produtos ja ordenados de acordo com a quantidade no estoque
        printf("Produto: %s Quantidade no estoque: %i\n",produto[i].nome,produto[i].qtdestoque);
    }
}

void ordemAlfabetica(Produto *produto) { //Função para ordenar os produtos em ordem alfabetica
    int i,j;
    char aux[50];
    for(i = 0; i < 10; i++) { // Ordenando os produtos
        for(j = 0; j < 10; j++) {
            if(strcmp(produto[i].nome,produto[j].nome) > 0) {
                strcpy(aux,produto[i].nome);
                strcpy(produto[i].nome,produto[j].nome);
                strcpy(produto[j].nome,aux);
            }
        }
    }
    for(i = 0; i < 10; i++) { //Mostrando os produtos em ordem alfabetica
        printf("Produto: %s Preço: R$%.2f\n",produto[i].nome,produto[i].preco);
    }
}

void ordenarCategoria(Produto *produto) { //Função para ordenar os produtos por categoria
    int i,j,aux;
    for(i = 0; i < 10; i++) { //Ordenando os produtos por categoria
        for(j = 0; j < 10; j++) {
            if(produto[i].categoria > produto[j].categoria) {
                aux = produto[i].categoria;
                produto[i].categoria = produto[j].categoria;
                produto[j].categoria = aux;
            }
        }
    }
    for(i = 0; i < 10; i++) { //Mostrando os produtos ordenados de acordo com a catergoria
        if(produto[i].categoria == 1) {
            printf("Produto: %s Preço: R$%.2f Categoria: Limpeza\n",produto[i].nome,produto[i].preco);
        } else if(produto[i].categoria == 2) {
            printf("Produto: %s Preço: R$%.2f Categoria: Alimento Perecível\n",produto[i].nome,produto[i].preco);
        } else if(produto[i].categoria == 3) {
            printf("Produto: %s Preço: R$%.2f Categoria: Alimento Não Perecível\n",produto[i].nome,produto[i].preco);
        } else {
            printf("Produto: %s Preço: R$%.2f Categoria: Eletrônico\n",produto[i].nome,produto[i].preco);
        }
    }
}

void menuBuscar(Produto *produto) { //Menu de busca
    int escolha;
    do {
        printf("Escolha uma opção de busca\n");
        printf("1 - Buscar por preço\n");
        printf("2 - Buscar por quantidade no estoque\n");
        printf("0 - Sair\n");
        scanf("%i",&escolha);
        switch (escolha) {
        case 1:
            buscarPreco(produto); //Chamando a função para buscar os produtos de acordo com o preço
            break;
        case 2:
            buscarQtdEstoque(produto); //Chamando a funcção para buscar os produtos de acordo com a quantidade no estoque
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções possiveis\n");
        }
    }while(escolha != 0);
}

void carrinhoDeCompras(Produto *produto){ //Funcao do Carrinho de Compras
    Carrinho carrinho[10];
    char nomeProduto[50];
    int escolha,j,i;
    float subtotal;
    for(i = 0; i < 10; i++) { //Limpando o carrinho
        carrinho[i].preco = 0;
    }
    do{
        j = 0;
        for(i = 0; i < 10; i++) { //Confirmando onde está vazio no carrinho
            if(carrinho[i].preco == 0) {
                j = j + 1;
            }
        }
        if(j == 10) { //Confirmando se o carrinho está completamente vazio, se não, mostrar os produtos que tem nele
            printf("O carrinho está vazio\n");
        } else {
            for(i = 0; i < 10; i++){
                subtotal = 0;
                if(carrinho[i].preco != 0) {
                    printf("Produto: %s Quantidade: %i Preço: R$%.2f\n",carrinho[i].nome,carrinho[i].quantidade,carrinho[i].preco);
                    subtotal = subtotal + carrinho[i].preco; //Calculando o valor dos produtos no carrinho
                }
            }
            printf("Subtotal: %.2f\n",subtotal); //Mostrando o valor dos produtos que estão no carrinho
        }
        printf("Escolha uma opção: \n");
        printf("1 - Inserir produto no carrinho\n");
        printf("2 - Retirar produto do carrinho\n");
        printf("3 - Fechar Compra\n");
        printf("0 - Sair\n");
        scanf("%i",&escolha);
        switch (escolha) {
        case 1:
            for(i = 0; i < 10; i++) { //Vendo uma posição vazia do carrinho
                if(carrinho[i].preco == 0) {
                    printf("Digite o nome do produto desejado: \n"); //Pegando o nome do produto que quer inserir no carrinho
                    scanf("%s",nomeProduto);
                    for(j = 0; j < 10; j++) { //Verificando se o produto existe no registro
                        if(strcmp(nomeProduto,produto[j].nome) == 0){
                            strcpy(carrinho[i].nome,nomeProduto); //Salvando produto na posição vazia que foi encontrada
                            printf("Digite a quantidade desejada do produto: \n"); //Pegando a quantidade do produto que deseja inserir
                            scanf("%i",carrinho[i].quantidade);
                            carrinho[i].preco = produto[j].preco * carrinho[i].quantidade; //Salvando o preço ja multiplicado pela quantidade do produto
                            break; //Parando o for para ele não continuar armazenando nos espaços vazios
                        }
                    }
                    break; //Parando o outro for para não continuar armazenando nos espaços vazios
                }
            }
            break;
        case 2:
            printf("Digite o nome do produto que deseja remover: \n"); //Pegando o produto para remover
            scanf("%s",nomeProduto);
            for(i = 0; i < 10; i++) { //Verificando se o produto está no carrinho
                if(strcmp(nomeProduto,carrinho[i].nome) == 0) { //Confirmando se ele está no carrinho e deletando caso esteja
                    strcpy(carrinho[i].nome,"0");
                    carrinho[i].preco = 0;
                    carrinho[i].quantidade = 0;
                }
            }
            break;
        case 3:
            printf("Compra realizada com sucesso\n"); //Fechando as compras e mostrando o valor total
            printf("TOTAL: R$%.2f",subtotal);
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções disponiveis\n");
        }
    }while (escolha != 0);
}

void menuCliente(Produto *produto){ //Função do menu do cliente
    int escolha;
    do {
        printf("Escolha uma opção: \n");
        printf("1 - Buscar produto\n");
        printf("2 - Carrinho de Compras\n");
        printf("0 - Sair\n");
        scanf("%i",&escolha);
        switch(escolha) {
        case 1:
            menuBuscar(produto); //Chamando a funcao do menu de busca
            break;
        case 2:
            carrinhoDeCompras(produto); //Chamando a funcao do carrinho de Compras
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções possiveis\n");
        }
    }while(escolha != 0);
}

void menuFuncionario(){ //Função do menu do funcionario
}

int main()
{
    int i,escolha;
    Produto produto[10];
    FILE *arquivo = fopen("produtos.txt","r"); //Abringo o arquivo como leitura
    if(arquivo == NULL) { //Testando se abriu o arquivo corretamente
        printf("Erro na abertura do arquivo\n");
    } else {
        for(i = 0;i < 10; i++) { //Pegando as informações ja salvas no arquivo
            fscanf(arquivo,"%s",produto[i].nome);
            fscanf(arquivo,"%f",&produto[i].preco);
            fscanf(arquivo,"%i",&produto[i].qtdestoque);
            fscanf(arquivo,"%i",&produto[i].validade.dia);
            fscanf(arquivo,"%i",&produto[i].validade.mes);
            fscanf(arquivo,"%i",&produto[i].validade.ano);
            fscanf(arquivo,"%s",produto[i].fabricante);
            fscanf(arquivo,"%i",produto[i].categoria);
        }
    }
    fclose(arquivo);
    do { // Escolhendo entre o menu de cliente e funcionario
        printf("Escolha uma opção: \n");
        printf("1 - Cliente\n");
        printf("2 - Funcionario\n");
        printf("0 - Sair\n");
        scanf("%i",&escolha);
        switch (escolha) {
        case 1:
            menuCliente(produto); //Chamando a função do menu do cliente
            break;
        case 2:
            menuFuncionario(); //Chamando a função do menu do funcionario
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções disponiveis\n");
        }
    }while (escolha != 0);

    return 0;
}
