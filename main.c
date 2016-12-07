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

void buscarNome(Produto *produto,int numProdutos){ //Função para buscar produtos por nome
    char nomeProduto[50];
    int i,naoExiste = 0;
    printf("Digite o nome do produto desejado: \n");
    fflush(stdin);
    gets(nomeProduto);
    for(i = 0; i < numProdutos; i++) {
        if(strncmp(nomeProduto,produto[i].nome,strlen(nomeProduto)) == 0) {
            printf("Produto: %sPreço: R$%.2f\n",produto[i].nome,produto[i].preco);
        }else {
            naoExiste = naoExiste + 1;
        }
    }
    if(naoExiste == numProdutos) {
        printf("O produto não existe no registro \n");
    }
}

void buscarFabricante(Produto *produto,int numProdutos) { //Função para buscar produtos por fabricante
    char nomeFabricante[50];
    int i,naoExiste = 0;
    printf("Digite o fabricante do produto: \n");
    fflush(stdin);
    gets(nomeFabricante);
    for(i = 0; i < numProdutos; i++) {
        if(strncmp(nomeFabricante,produto[i].fabricante,strlen(nomeFabricante)) == 0) {
            printf("Produto: %sPreço:%.2f Fabricante: %s\n",produto[i].nome,produto[i].preco,produto[i].fabricante);
        }else {
            naoExiste = naoExiste + 1;
        }
    }
    if(naoExiste == numProdutos) {
        printf("O produto não existe no registro \n");
    }
}

void ordenarPreco(Produto *produto,int numProdutos){  //Funcao para ordenar os produtos do menor para o maior preço
    int i,j;
    Produto aux;
    for(i = 0; i < numProdutos; i++) { //Ordenando os produtos de acordo com o preço
        for(j = i + 1; j < numProdutos; j++) {
            if(produto[i].preco > produto[j].preco){
                aux = produto[i];
                produto[i] = produto[j];
                produto[j] = aux;
            }
        }
    }
    for(i = 0; i < numProdutos; i++) { //Mostrando os produtos ja ordenados de acordo com o preço
        printf("Produto: %sPreço: R$%.2f \n",produto[i].nome,produto[i].preco);
    }
}

void ordenarQtdEstoque(Produto *produto,int numProdutos) { //Funcao para ordenar os produtos da menor para a maior quantidade no estoque
    int i,j;
    Produto aux;
    for(i = 0; i < numProdutos; i++) { //Ordenando os produtos de acordo com a quantidade no estoque
        for(j = i + 1; j < numProdutos; j++) {
            if(produto[i].qtdestoque > produto[j].qtdestoque) {
                aux = produto[i];
                produto[i] = produto[j];
                produto[j] = aux;
            }
        }
    }
    for(i = 0; i < numProdutos; i++) {  //Mostrando os produtos ja ordenados de acordo com a quantidade no estoque
        printf("Produto: %sQuantidade no estoque: %i\n",produto[i].nome,produto[i].qtdestoque);
    }
}

void ordemAlfabetica(Produto *produto,int numProdutos) { //Função para ordenar os produtos em ordem alfabetica
    int i,j;
    Produto aux;
    for(i = 0; i < numProdutos; i++) { // Ordenando os produtos
        for(j = 0; j < numProdutos; j++) {
            if(strcmp(produto[i].nome,produto[j].nome) < 0) {
                aux = produto[i];
                produto[i] = produto[j];
                produto[j] = aux;
            }
        }
    }
    for(i = 0; i < numProdutos; i++) { //Mostrando os produtos em ordem alfabetica
        printf("Produto: %sPreço: R$%.2f\n",produto[i].nome,produto[i].preco);
    }
}

void ordenarCategoria(Produto *produto,int numProdutos) { //Função para ordenar os produtos por categoria
    int i,j;
    Produto aux;
    for(i = 0; i < numProdutos; i++) { //Ordenando os produtos por categoria
        for(j = 0; j < numProdutos; j++) {
            if(produto[i].categoria > produto[j].categoria) {
                aux = produto[i];
                produto[i] = produto[j];
                produto[j] = aux;
            }
        }
    }
    for(i = 0; i < numProdutos; i++) { //Mostrando os produtos ordenados de acordo com a catergoria
        if(produto[i].categoria == 1) {
            printf("Produto: %sPreço: R$%.2f Categoria: Limpeza\n",produto[i].nome,produto[i].preco);
        } else if(produto[i].categoria == 2) {
            printf("Produto: %sPreço: R$%.2f Categoria: Alimento Perecível\n",produto[i].nome,produto[i].preco);
        } else if(produto[i].categoria == 3) {
            printf("Produto: %sPreço: R$%.2f Categoria: Alimento Não Perecível\n",produto[i].nome,produto[i].preco);
        } else {
            printf("Produto: %sPreço: R$%.2f Categoria: Eletrônico\n",produto[i].nome,produto[i].preco);
        }
    }
}

void menuBuscar(Produto *produto,int numProdutos) { //Menu de busca
    int escolha;
    do {
        printf("Escolha uma opção de busca\n");
        printf("1 - Buscar por nome\n");
        printf("2 - Buscar por fabricante\n");
        printf("3 - Buscar por preço\n");
        printf("4 - Buscar por quantidade no estoque\n");
        printf("5 - Ordenar por ordem alfabetica\n");
        printf("6 - Ordenar por categoria\n");
        printf("0 - Sair\n");
        scanf("%i",&escolha);
        system ("cls");
        switch (escolha) {
        case 1:
            buscarNome(produto,numProdutos); //Chamando a função para buscar produto por nome
            break;
        case 2:
            buscarFabricante(produto,numProdutos); //Chamando a função para buscar por fabricante
            break;
        case 3:
            ordenarPreco(produto,numProdutos); //Chamando a função para ordenar os produtos de acordo com o preço
            break;
        case 4:
            ordenarQtdEstoque(produto,numProdutos); //Chamando a funcção para ordenar os produtos de acordo com a quantidade no estoque
            break;
        case 5:
            ordemAlfabetica(produto,numProdutos); //Chamando a função para ordenar por ordem alfabética
            break;
        case 6:
            ordenarCategoria(produto,numProdutos); //Chamando a funcão para ordenar por categoria
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções possiveis\n");
        }
    }while(escolha != 0);
}

void carrinhoDeCompras(Produto *produto,int numProdutos){ //Funcao do Carrinho de Compras
    Carrinho carrinho[numProdutos];
    char nomeProduto[50];
    int escolha,j,i,naoExiste;
    float subtotal = 0;
    for(i = 0; i < numProdutos; i++) { //Limpando o carrinho
        carrinho[i].preco = 0;
    }
    do{
        j = 0;
        for(i = 0; i < numProdutos; i++) { //Confirmando onde está vazio no carrinho
            if(carrinho[i].preco == 0) {
                j = j + 1;
            }
        }
        if(j == numProdutos) { //Confirmando se o carrinho está completamente vazio, se não, mostrar os produtos que tem nele
            printf("O carrinho está vazio\n");
        } else {
            subtotal = 0;
            for(i = 0; i < numProdutos; i++){
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
            for(i = 0; i < numProdutos; i++) { //Vendo uma posição vazia do carrinho
                if(carrinho[i].preco == 0) {
                    printf("Digite o nome do produto desejado: \n"); //Pegando o nome do produto que quer inserir no carrinho
                    fflush(stdin);
                    gets(nomeProduto);
                    naoExiste = 0;
                    for(j = 0; j < numProdutos; j++) { //Verificando se o produto existe no registro
                        if(strncmp(nomeProduto,produto[j].nome,strlen(nomeProduto)) == 0){
                            strcpy(carrinho[i].nome,nomeProduto); //Salvando produto na posição vazia que foi encontrada
                            printf("Digite a quantidade desejada do produto: \n"); //Pegando a quantidade do produto que deseja inserir
                            scanf("%i",&carrinho[i].quantidade);
                            carrinho[i].preco = produto[j].preco * carrinho[i].quantidade; //Salvando o preço ja multiplicado pela quantidade do produto
                            naoExiste = 0; //Definindo um valor para uma variavel para poder sair do for e parar de armazenar em espaços vazios
                            break; //Parando o for para ele não continuar armazenando nos espaços vazios
                        }else {
                            naoExiste = naoExiste + 1; //Contador para saber se o produto existe no registro
                        }
                        if(naoExiste == numProdutos) {
                            printf("O produto não existe no mercado\n"); // Se o produto não existir exibira uma mensagem dizendo que não tem no registro
                        }
                    }
                }
                if(naoExiste == 0) {  //Saindo do for caso a variavel tenha um valor 0 que é definido quando um produto é cadastrado
                    break;
                }
            }
            break;
        case 2:
            printf("Digite o nome do produto que deseja remover: \n"); //Pegando o produto para remover
            fflush(stdin);
            gets(nomeProduto);
            naoExiste = 0;
            for(i = 0; i < numProdutos; i++) { //Verificando se o produto está no carrinho
                if(strncmp(nomeProduto,carrinho[i].nome,strlen(nomeProduto)) == 0) { //Confirmando se ele está no carrinho e deletando caso esteja
                    strcpy(carrinho[i].nome,"0");
                    carrinho[i].preco = 0;
                    carrinho[i].quantidade = 0;
                }else {
                    naoExiste = naoExiste + 1; //Contador para saber se o produto existe no carrinho
                }
            }
            if(naoExiste == numProdutos) {
                printf("O produto não está no carrinho\n"); //Se o produto não estiver no carrinho irá exibir uma mensagem avisando
            }
            break;
        case 3:
            printf("Compra realizada com sucesso\n"); //Fechando as compras e mostrando o valor total e o que foi comprado
            for(i = 0; i < numProdutos; i++){
                if(carrinho[i].preco != 0) {
                    printf("Produto: %s Quantidade: %i Preço: %.2f\n",carrinho[i].nome,carrinho[i].quantidade,carrinho[i].preco);
                    produto[i].qtdestoque = produto[i].qtdestoque - carrinho[i].quantidade;
                }
            }
            printf("TOTAL: R$%.2f\n",subtotal);  //Valor total dos produtos que estão no carrinho
            for(i = 0; i < numProdutos; i++) { //Limpando o carrinho
                carrinho[i].preco = 0;
            }
            subtotal = 0; //Limpando o valor do subtotal
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções disponiveis\n");
        }
    }while(escolha != 0);
}

void menuCliente(Produto *produto,int numProdutos){ //Função do menu do cliente
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
            menuBuscar(produto,numProdutos); //Chamando a funcao do menu de busca
            break;
        case 2:
            carrinhoDeCompras(produto,numProdutos); //Chamando a funcao do carrinho de Compras
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções possiveis\n");
        }
    }while(escolha != 0);
}

void inserirProduto(Produto *produto,int numProdutos) { //Função para inserir novos produtos no registro
    int i,novo = 0,qtdNovoProduto = 0;
    char novoProduto[50];
    printf("Digite o nome do novo produto: \n"); //Recebendo o nome do novo produto
    fflush(stdin);
    gets(novoProduto);
    for(i = 0; i < numProdutos; i++) { //Verificando se ele existe no registro, caso não exista, aumentar o contador
        if(strncmp(novoProduto,produto[i].nome,strlen(novoProduto)) == 0) {
            printf("O produto ja está registrado\n");
            break;
        }else {
            novo = novo + 1; //Contador caso o produto não exista no registro
        }
    }
    if(novo == numProdutos) { //Se o produtor não existir , cadastrar o novo produto
        FILE *novoArquivo = fopen("novoproduto.txt","r"); //Verificando se existe arquivo com produtos ja salvos, caso não exista, criar um novo vazio
        if(novoArquivo == NULL) {
            novoArquivo = fopen("novoproduto.txt","w");
            fprintf(novoArquivo,"Quandotidade de produtos novos: %i",qtdNovoProduto);
        }else {
            fscanf(novoArquivo,"Quandotidade de produtos novos: %i",&qtdNovoProduto);
            fclose(novoArquivo);
        }
        Produto novosProdutos[qtdNovoProduto + 1]; //Variavel para armazenar os valores dos novos produtos
        novoArquivo = fopen("novoproduto.txt","r");
        for(i = 0; i < qtdNovoProduto; i++){ //Lendo os valores dos produtos ja armazenados caso ja existam
            fscanf(novoArquivo,"%s",novosProdutos[i].nome);
            fscanf(novoArquivo,"Categoria: %i\n",&novosProdutos[i].categoria);
            fscanf(novoArquivo,"Codigo: %i\n",&novosProdutos[i].codigo);
            fscanf(novoArquivo,"Preço: %f\n",&novosProdutos[i].preco);
            fscanf(novoArquivo,"%s",novosProdutos[i].descricao);
            fscanf(novoArquivo,"%s",novosProdutos[i].fabricante);
            fscanf(novoArquivo,"Data de validade: %i / %i / %i\n",&novosProdutos[i].validade.dia,&novosProdutos[i].validade.mes,&novosProdutos[i].validade.ano);
            fscanf(novoArquivo,"Corredor: %i\n",&novosProdutos[i].corredor);
            fscanf(novoArquivo,"Prateleira: %i\n",&novosProdutos[i].prateleira);
            fscanf(novoArquivo,"Quantidade no estoque: %i\n",&novosProdutos[i].qtdestoque);
        }
        fclose(novoArquivo);
        strcpy(novosProdutos[qtdNovoProduto].nome,novoProduto);  //Recebendo os valores do novo produto que está sendo adicionado
        printf("Digite o número referente a categoria do novo produto: 1-Limpeza, 2-Alimento Perecível, 3-Alimento Não Perecível, 4 - Eletrônico\n");
        scanf("%i",&novosProdutos[qtdNovoProduto].categoria);
        printf("Digite o codigo do novo produto: \n");
        scanf("%i",&novosProdutos[qtdNovoProduto].codigo);
        printf("Digite o preço do novo produto: \n");
        scanf("%f",&novosProdutos[qtdNovoProduto].preco);
        printf("Digite a descrição do novo produto: \n");
        fflush(stdin);
        gets(novosProdutos[qtdNovoProduto].descricao);
        printf("Digite o fabricante do novo produto: \n");
        fflush(stdin);
        gets(novosProdutos[qtdNovoProduto].fabricante);
        printf("Digite a data de validade do novo produto(DD MM AAAA): \n");
        scanf("%i %i %i",&novosProdutos[qtdNovoProduto].validade.dia,&novosProdutos[qtdNovoProduto].validade.mes,&novosProdutos[qtdNovoProduto].validade.ano);
        printf("Digite o corredor e a prateleira onde encontrar o novo produto: \n");
        scanf("%i %i",&novosProdutos[qtdNovoProduto].corredor,&novosProdutos[qtdNovoProduto].prateleira);
        printf("Digite a quantidade do estoque do novo produto: \n");
        scanf("%i",&novosProdutos[qtdNovoProduto].qtdestoque);
        novoArquivo = fopen("novoproduto.txt","w");  //Armazenando todos os novos produtos em um arquivo para salva-los e adicionar ao registro principal depois
        fprintf(novoArquivo,"Quandotidade de produtos novos: %i\n",qtdNovoProduto + 1);
        for(i = 0; i < (qtdNovoProduto + 1); i++) {
            fprintf(novoArquivo,"%s \n",novosProdutos[i].nome);
            fprintf(novoArquivo,"Categoria: %i\n",novosProdutos[i].categoria);
            fprintf(novoArquivo,"Codigo: %i\n",novosProdutos[i].codigo);
            fprintf(novoArquivo,"Preço: %f\n",novosProdutos[i].preco);
            fprintf(novoArquivo,"%s \n",novosProdutos[i].descricao);
            fprintf(novoArquivo,"%s \n",novosProdutos[i].fabricante);
            fprintf(novoArquivo,"Data de validade: %i / %i / %i\n",novosProdutos[i].validade.dia,novosProdutos[i].validade.mes,novosProdutos[i].validade.ano);
            fprintf(novoArquivo,"Corredor: %i\n",novosProdutos[i].corredor);
            fprintf(novoArquivo,"Prateleira: %i\n",novosProdutos[i].prateleira);
            fprintf(novoArquivo,"Quantidade no estoque: %i\n",novosProdutos[i].qtdestoque);
        }
        fclose(novoArquivo);
        fflush(stdin);
    }
}

void reporEstoque(Produto *produto,int numProdutos) { //Função para repor o estoque dos produtos
    int i,naoExiste,novoEstoque;
    char nomeProduto[50];
    printf("Digite o produto que deseja repor: \n");  //Pegando o nome do produto que deseja repor
    fflush(stdin);
    gets(nomeProduto);
    naoExiste = 0;
    for(i = 0; i < numProdutos; i++) { //Verificando se ele existe no estoque, se não, aumentar o contador de que ele não existe
            if(strncmp(nomeProduto,produto[i].nome,strlen(nomeProduto)) == 0){
                printf("Digite a quantas unidades deseja adicionar ao estoque: \n");
                scanf("%i",&novoEstoque);
                produto[i].qtdestoque = produto[i].qtdestoque + novoEstoque;
            }else {
                naoExiste = naoExiste + 1;
            }
            if(naoExiste == numProdutos) {
                printf("O produto não existe no estoque"); //Caso o produto não exista, exibir a mensagem avisando
            }
    }
}

void menuFuncionario(Produto *produto,int numProdutos){ //Função do menu do funcionario
    int i,dia,mes,ano,escolha;

    printf("Digite o dia mes e ano(DD MM AAAA): \n"); //Recebendo a data atual
    scanf("%i %i %i",&dia,&mes,&ano);
    for(i = 0; i < numProdutos; i++) { //Pecorrendo o registro para saber os produtos que estão com o estoque baixo ou fora da validade
        if(produto[i].qtdestoque < 20) { //Verificando quais produtos estão com o estoque baixo
            printf("O produto %s está com o estoque baixo. Apenas %i unidades\n",produto[i].nome,produto[i].qtdestoque);
        }
        if(produto[i].validade.ano < ano) { // Verificando a validade dos produtos
            printf("O produto %s está fora da validade\n",produto[i].nome);
        }
        if(produto[i].validade.mes < mes && produto[i].validade.ano == ano) {
            printf("O produto %s está fora da validade\n",produto[i].nome);
        }
        if(produto[i].validade.dia < dia && produto[i].validade.ano == ano && produto[i].validade.mes == mes){
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
            inserirProduto(produto,numProdutos); //Chamando a função para inserir novos produtos
            break;
        case 2:
            reporEstoque(produto,numProdutos); //Chamando a função para repor estoque
            break;
        case 3:
            menuBuscar(produto,numProdutos); //Chamando a função do menu de busca
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
    int numProdutos = 0,i,escolha,produtoNovo = 0;
    FILE *arquivo = fopen("produtos.txt","r"); //Abringo o arquivo como leitura
    if(arquivo == NULL) {  //Verificando se o arquivo existe, caso não exista, criar um novo arquivo
        arquivo = fopen("produtos.txt","w");
        fprintf(arquivo,"Quandidade de produtos: %i",numProdutos);
        printf("O arquivo não existe ou não é possivel abrir, portanto um novo arquivo foi criado\n");
        fclose(arquivo);
    }else {
        fscanf(arquivo,"Quandidade de produtos: %i",&numProdutos); //Caso o arquivo exista, ler o número de produtos armazenados nele
        fclose(arquivo);
    }
    if(numProdutos == 0) {
        printf("Não tem nenhum produto registrado\n"); //Se o arquivo tiver sido criar ou não tiver nada armazenado, mostrar mensagem avisando
    }
    Produto produto[numProdutos];
    arquivo = fopen("produtos.txt","r");
    if(arquivo == NULL) { //Testando se abriu o arquivo corretamente, se abrir corretamente receber as informações dos produtos armazenados
        printf("Erro na abertura do arquivo\n");
    } else {
        fscanf(arquivo,"Quandidade de produtos: %i\n",&numProdutos);
        for(i = 0; i < numProdutos; i++) { //Lendo os dados do arquivo
            fgets(produto[i].nome,50,arquivo);
            fscanf(arquivo,"Categoria: %i\n",&produto[i].categoria);
            fscanf(arquivo,"Codigo: %i\n",&produto[i].codigo);
            fscanf(arquivo,"Preço: %f\n",&produto[i].preco);
            fgets(produto[i].descricao,100,arquivo);
            fgets(produto[i].fabricante,50,arquivo);
            fscanf(arquivo,"Data de validade: %i / %i / %i\n",&produto[i].validade.dia,&produto[i].validade.mes,&produto[i].validade.ano);
            fscanf(arquivo,"Corredor: %i\n",&produto[i].corredor);
            fscanf(arquivo,"Prateleira: %i\n",&produto[i].prateleira);
            fscanf(arquivo,"Quantidade no estoque: %i\n",&produto[i].qtdestoque);
        }
    }
    fclose(arquivo);
    do { // Escolhendo entre o menu de cliente e funcionario
        printf("Escolha uma opção: \n");
        printf("1 - Cliente\n");
        printf("2 - Funcionario\n");
        printf("0 - Sair\n");
        scanf("%i",&escolha);
        system ("cls");
        switch (escolha) {
        case 1:
            menuCliente(produto,numProdutos); //Chamando a função do menu do cliente
            break;
        case 2:
            menuFuncionario(produto,numProdutos); //Chamando a função do menu do funcionario
            break;
        case 0:
            break;
        default:
            printf("Escolha uma das opções disponiveis\n");
        }
    }while (escolha != 0);

    FILE *novoProduto = fopen("novoproduto.txt","r"); //Lendo arquivo de produtos novos para saber quantos produtos novos tem salvos
    if(novoProduto != NULL) {
        fscanf(novoProduto,"Quandotidade de produtos novos: %i",&produtoNovo);
        fclose(novoProduto);
    }
    arquivo = fopen("produtos.txt","w"); //Abrindo arquivo para escrita
    if(arquivo == NULL) { //Verificando se o arquivo abriu corretamente
        printf("Erro na abertura do arquivo\n");
    }else {
        numProdutos = numProdutos + produtoNovo;
        fprintf(arquivo,"Quandidade de produtos: %i\n",numProdutos);
        for(i = 0; i < (numProdutos - produtoNovo); i++) { //Gravando os dados no arquivo
            fprintf(arquivo,"%s",produto[i].nome);
            fprintf(arquivo,"Categoria: %i\n",produto[i].categoria);
            fprintf(arquivo,"Codigo: %i\n",produto[i].codigo);
            fprintf(arquivo,"Preço: %f\n",produto[i].preco);
            fprintf(arquivo,"%s",produto[i].descricao);
            fprintf(arquivo,"%s",produto[i].fabricante);
            fprintf(arquivo,"Data de validade: %i / %i / %i\n",produto[i].validade.dia,produto[i].validade.mes,produto[i].validade.ano);
            fprintf(arquivo,"Corredor: %i\n",produto[i].corredor);
            fprintf(arquivo,"Prateleira: %i\n",produto[i].prateleira);
            fprintf(arquivo,"Quantidade no estoque: %i\n",produto[i].qtdestoque);
        }
    }
    fclose(arquivo); //Fechando arquivo com os novos dados salvos

    novoProduto = fopen("novoproduto.txt","r"); //Lendo produtos novos salvos no arquivo caso existam
    if(novoProduto != NULL) {
        fscanf(novoProduto,"Quandotidade de produtos novos: %i\n",&produtoNovo);
        Produto novosProdutos[produtoNovo];
        arquivo = fopen("produtos.txt","a");
        for(i = 0; i < produtoNovo; i++) { //Lendo os produtos novos do arquivos de produtos novos e salvando no arquivo do registro principal
            fgets(novosProdutos[i].nome,50,novoProduto);
            fscanf(novoProduto,"Categoria: %i\n",&novosProdutos[i].categoria);
            fscanf(novoProduto,"Codigo: %i\n",&novosProdutos[i].codigo);
            fscanf(novoProduto,"Preço: %f\n",&novosProdutos[i].preco);
            fgets(novosProdutos[i].descricao,100,novoProduto);
            fgets(novosProdutos[i].fabricante,50,novoProduto);
            fscanf(novoProduto,"Data de validade: %i / %i / %i\n",&novosProdutos[i].validade.dia,&novosProdutos[i].validade.mes,&novosProdutos[i].validade.ano);
            fscanf(novoProduto,"Corredor: %i\n",&novosProdutos[i].corredor);
            fscanf(novoProduto,"Prateleira: %i\n",&novosProdutos[i].prateleira);
            fscanf(novoProduto,"Quantidade no estoque: %i\n",&novosProdutos[i].qtdestoque);
            fprintf(arquivo,"%s",novosProdutos[i].nome);
            fprintf(arquivo,"Categoria: %i\n",novosProdutos[i].categoria);
            fprintf(arquivo,"Codigo: %i\n",novosProdutos[i].codigo);
            fprintf(arquivo,"Preço: %f\n",novosProdutos[i].preco);
            fprintf(arquivo,"%s",novosProdutos[i].descricao);
            fprintf(arquivo,"%s",novosProdutos[i].fabricante);
            fprintf(arquivo,"Data de validade: %i / %i / %i\n",novosProdutos[i].validade.dia,novosProdutos[i].validade.mes,novosProdutos[i].validade.ano);
            fprintf(arquivo,"Corredor: %i\n",novosProdutos[i].corredor);
            fprintf(arquivo,"Prateleira: %i\n",novosProdutos[i].prateleira);
            fprintf(arquivo,"Quantidade no estoque: %i\n",novosProdutos[i].qtdestoque);
        }
        fclose(novoProduto);
        novoProduto = fopen("novoproduto.txt","w"); //Limpando o arquivo de produtos novos para não salva-los repetidamente
        produtoNovo = 0;
        fprintf(novoProduto,"Quantidade de produtos novos: %i\n",produtoNovo);
        fclose(novoProduto);
    }
    return 0;
}
