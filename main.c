#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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
    Produto aux;
    for(i = 0; i < 10; i++) { //Ordenando os produtos de acordo com o preço
        for(j = i + 1; j < 10; j++) {
            if(produto[i].preco > produto[j].preco){
                aux = produto[i];
                produto[i] = produto[j];
                produto[j] = aux;
            }
        }
    }
    for(i = 0; i < 10; i++) { //Mostrando os produtos ja ordenados de acordo com o preço
        printf("Produto: %s Preço: R$%.2f \n",produto[i].nome,produto[i].preco);
    }
}

void buscarQtdEstoque(Produto *produto) { //Funcao para ordenar os produtos da menor para a maior quantidade no estoque
    int i,j;
    Produto aux;
    for(i = 0; i < 10; i++) { //Ordenando os produtos de acordo com a quantidade no estoque
        for(j = i + 1; j < 10; j++) {
            if(produto[i].qtdestoque > produto[j].qtdestoque) {
                aux = produto[i];
                produto[i] = produto[j];
                produto[j] = aux;
            }
        }
    }
    for(i = 0; i < 10; i++) {  //Mostrando os produtos ja ordenados de acordo com a quantidade no estoque
        printf("Produto: %s Quantidade no estoque: %i\n",produto[i].nome,produto[i].qtdestoque);
    }
}

void ordemAlfabetica(Produto *produto) { //Função para ordenar os produtos em ordem alfabetica
    int i,j;
    Produto aux;
    for(i = 0; i < 10; i++) { // Ordenando os produtos
        for(j = 0; j < 10; j++) {
            if(strcmp(produto[i].nome,produto[j].nome) > 0) {
                aux = produto[i];
                produto[i] = produto[j];
                produto[j] = aux;
            }
        }
    }
    for(i = 0; i < 10; i++) { //Mostrando os produtos em ordem alfabetica
        printf("Produto: %s Preço: R$%.2f\n",produto[i].nome,produto[i].preco);
    }
}

void ordenarCategoria(Produto *produto) { //Função para ordenar os produtos por categoria
    int i,j;
    Produto aux;
    for(i = 0; i < 10; i++) { //Ordenando os produtos por categoria
        for(j = 0; j < 10; j++) {
            if(produto[i].categoria > produto[j].categoria) {
                aux = produto[i];
                produto[i] = produto[j];
                produto[j] = aux;
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
        system ("cls");
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
    int escolha,j,i,naoExiste;
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
        system ("cls");
        switch (escolha) {
        case 1:
            for(i = 0; i < 10; i++) { //Vendo uma posição vazia do carrinho
                if(carrinho[i].preco == 0) {
                    printf("Digite o nome do produto desejado: \n"); //Pegando o nome do produto que quer inserir no carrinho
                    scanf("%s",nomeProduto);
                    naoExiste = 0;
                    for(j = 0; j < 10; j++) { //Verificando se o produto existe no registro
                        if(strcmp(nomeProduto,produto[j].nome) == 0){
                            strcpy(carrinho[i].nome,nomeProduto); //Salvando produto na posição vazia que foi encontrada
                            printf("Digite a quantidade desejada do produto: \n"); //Pegando a quantidade do produto que deseja inserir
                            scanf("%i",carrinho[i].quantidade);
                            carrinho[i].preco = produto[j].preco * carrinho[i].quantidade; //Salvando o preço ja multiplicado pela quantidade do produto
                            break; //Parando o for para ele não continuar armazenando nos espaços vazios
                        }else {
                            naoExiste = naoExiste + 1; //Contador para saber se o produto existe no registro
                        }
                        if(naoExiste == 10) {
                            printf("O produto não existe no mercado\n"); // Se o produto não existir exibira uma mensagem dizendo que não tem no registro
                        }
                    }
                    break; //Parando o outro for para não continuar armazenando nos espaços vazios
                }
            }
            break;
        case 2:
            printf("Digite o nome do produto que deseja remover: \n"); //Pegando o produto para remover
            scanf("%s",nomeProduto);
            naoExiste = 0;
            for(i = 0; i < 10; i++) { //Verificando se o produto está no carrinho
                if(strcmp(nomeProduto,carrinho[i].nome) == 0) { //Confirmando se ele está no carrinho e deletando caso esteja
                    strcpy(carrinho[i].nome,"0");
                    carrinho[i].preco = 0;
                    carrinho[i].quantidade = 0;
                }else {
                    naoExiste = naoExiste + 1; //Contador para saber se o produto existe no carrinho
                }
            }
            if(naoExiste == 10) {
                printf("O produto não está no carrinho\n"); //Se o produto não estiver no carrinho irá exibir uma mensagem avisando
            }
            break;
        case 3:
            printf("Compra realizada com sucesso\n"); //Fechando as compras e mostrando o valor total e o que foi comprado
            for(i = 0; i < 10; i++){
                if(carrinho[i].preco != 0) {
                    printf("Produto: %s Quantidade: %i Preço: %.2f\n",carrinho[i].nome,carrinho[i].quantidade,carrinho[i].preco);
                }
            }
            printf("TOTAL: R$%.2f\n",subtotal);  //Valor total dos produtos que estão no carrinho
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
        system ("cls");
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

void reporEstoque(Produto *produto) { //Função para repor o estoque dos produtos
    int i,naoExiste,novoEstoque;
    char nomeProduto[50];
    printf("Digite o produto que deseja repor: \n");  //Pegando o nome do produto que deseja repor
    scanf("%s",nomeProduto);
    naoExiste = 0;
    for(i = 0; i < 10; i++) { //Verificando se ele existe no estoque, se não, aumentar o contador de que ele não existe
            if(strcmp(nomeProduto,produto[i].nome) == 0){
                printf("Digite a quantas unidades deseja adicionar ao estoque: \n");
                scanf("%i",&novoEstoque);
                produto[i].qtdestoque = produto[i].qtdestoque + novoEstoque;
            }else {
                naoExiste = naoExiste + 1;
            }
            if(naoExiste == 10) {
                printf("O produto não existe no estoque"); //Caso o produto não exista, exibir a mensagem avisando
            }
    }
}

void inserirProduto(Produto *produto) { //Função para inserir novos produtos no registro
    int i,registroCheio = 0;
    for(i = 0; i < 10; i++) { //Verificando se tem algum lugar livre para adicionar produto novo, se não tiver , aumentar o contador
        if(produto[i].qtdestoque == 0) { //Caso tenho um lugar livre, receber informações do produto
            printf("Digite o nome do novo produto: \n");
            getchar();
            scanf("%[^\n]s",produto[i].nome);
            printf("Digite o preço do novo produto: \n");
            scanf("%f",&produto[i].preco);
            printf("Digite o codigo do novo produto: \n");
            scanf("%i",&produto[i].codigo);
            printf("Digite o numero referente a categoria do produto: \n");
            printf("1-Limepeza  2-Alimento Perecível  3-Alimento Não Perecível  4-Eletrônico\n");
            scanf("%i",&produto[i].categoria);
            printf("Digite a descrição do produto: \n");
            getchar();
            scanf("%[^\n]s",produto[i].descricao);
            printf("Digite o nome do fabricante:\n");
            getchar();
            scanf("%[^\n]s",produto[i].fabricante);
            printf("Digite a data de validade(DD MM AAAA):\n");
            scanf("%i %i %i",&produto[i].validade.dia,&produto[i].validade.mes,&produto[i].validade.ano);
            printf("Digite a quantidade do estoque:\n");
            scanf("%i",&produto[i].qtdestoque);
            printf("Digite o nº do corredor e o da prateleira onde localizar o produto:\n");
            scanf("%i %i",&produto[i].corredor,&produto[i].prateleira);
            break;
        }else {
            registroCheio = registroCheio + 1;
        }
        if(registroCheio == 10) {
            printf("O mercado está cheio, retire algum produto para adicionar um novo");  //Se o registro estiver cheio, mostrar mensagem avisando
        }
    }
}

void menuFuncionario(Produto *produto){ //Função do menu do funcionario
    int i,dia,mes,ano,escolha;

    printf("Digite o dia mes e ano(DD MM AAAA): \n"); //Recebendo a data atual
    scanf("%i %i %i",&dia,&mes,&ano);
    for(i = 0; i < 10; i++) { //Pecorrendo o registro para saber os produtos que estão com o estoque baixo ou fora da validade
        if(produto[i].qtdestoque < 20) { //Verificando quais produtos estão com o estoque baixo
            printf("O produto %s está com o estoque baixo. Apenas %i unidades\n",produto[i].nome,produto[i].qtdestoque);
        }
        if(produto[i].validade.ano < ano) { // Verificando a validade dos produtos
            printf("O produto %s está fora da validade\n",produto[i].nome);
        }else if(produto[i].validade.mes < mes) {
            printf("O produto %s está fora da validade\n",produto[i].nome);
        }else if(produto[i].validade.dia < dia){
            printf("O produto %s está fora da validade\n",produto[i].nome);
        }
    }
    do {
        printf("Escolha uma das opções: \n");
        printf("1 - Inserir novos produtos\n");
        printf("2 - Repor estoque\n");
        printf("3 - Buscar produto\n");
        printf("0 - Sair\n");
        scanf("%i",&escolha);
        system ("cls");
        switch(escolha) {
        case 1:
            inserirProduto(produto); //Chamando a função para inserir novos produtos
            break;
        case 2:
            reporEstoque(produto); //Chamando a função para repor estoque
            break;
        case 3:
            menuBuscar(produto); //Chamando a função do menu de busca
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções disponiveis\n");
        }

    }while(escolha != 0);
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    system ("color f0");

    int i,escolha;
    Produto produto[10];
    FILE *arquivo = fopen("produtos.txt","r"); //Abringo o arquivo como leitura
    if(arquivo == NULL) { //Testando se abriu o arquivo corretamente
        printf("Erro na abertura do arquivo\n");
    } else {
        for(i = 0;i < 10; i++) { //Pegando as informações ja salvas no arquivo
            fscanf(arquivo,"%[^\n]s \n",produto[i].nome);
            fscanf(arquivo,"%i \n",&produto[i].categoria);
            fscanf(arquivo,"%i \n",&produto[i].codigo);
            fscanf(arquivo,"%f \n",&produto[i].preco);
            fscanf(arquivo,"%[^\n]s \n",produto[i].descricao);
            fscanf(arquivo,"%[^\n]s \n",produto[i].fabricante);
            fscanf(arquivo,"%i %i %i \n",&produto[i].validade.dia,&produto[i].validade.mes,&produto[i].validade.ano);
            fscanf(arquivo,"%i \n",&produto[i].corredor);
            fscanf(arquivo,"%i \n",&produto[i].prateleira);
            fscanf(arquivo,"%i \n",&produto[i].qtdestoque);
        }
    }
    fclose(arquivo); //Fechando arquivo

    do { // Escolhendo entre o menu de cliente e funcionario
        printf("Escolha uma opção: \n");
        printf("1 - Cliente\n");
        printf("2 - Funcionario\n");
        printf("0 - Sair\n");
        scanf("%i",&escolha);
        system ("cls");
        switch (escolha) {
        case 1:
            menuCliente(produto); //Chamando a função do menu do cliente
            break;
        case 2:
            menuFuncionario(produto); //Chamando a função do menu do funcionario
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções disponiveis\n");
        }
    }while (escolha != 0);

    arquivo = fopen("produtos.txt","w"); //Abrindo arquivo para escrita
    if(arquivo == NULL) { //Verificando se o arquivo abriu corretamente
        printf("Erro na abertura do arquivo\n");
    }else {
        for(i = 0; i < 10; i++) { //Gravando os dados no arquivo
            fprintf(arquivo,"%s \n",produto[i].nome);
            fprintf(arquivo,"%i \n",produto[i].categoria);
            fprintf(arquivo,"%i \n",produto[i].codigo);
            fprintf(arquivo,"%f \n",produto[i].preco);
            fprintf(arquivo,"%s \n",produto[i].descricao);
            fprintf(arquivo,"%s\n",produto[i].fabricante);
            fprintf(arquivo,"%i %i %i \n",produto[i].validade.dia,produto[i].validade.mes,produto[i].validade.ano);
            fprintf(arquivo,"%i \n",produto[i].corredor);
            fprintf(arquivo,"%i \n",produto[i].prateleira);
            fprintf(arquivo,"%i \n",produto[i].qtdestoque);
        }
    }
    fclose(arquivo); //Fechando arquivo com os novos dados salvos

    return 0;
}
