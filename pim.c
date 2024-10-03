#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX_ITENS 100 //definindo arrey de 100 para adicionar itens na mesma variavel

typedef struct
{
    int codigo;
    char nome[50];
    float preco;
    float desconto;
    int quantidade;
}item; // nessa estrutura eu declarei todos os componentes de um produto


item inventario[MAX_ITENS];// nosso inventario pode ter até 100 itens
int quant_iten = 0;

void adicionar_iten()
{
    if(quant_iten >= MAX_ITENS)//confere se o inventario está cheio
    {
        printf("inventario cheio!!!!");
    }

    item novo_item;
    printf("codigo do item:");
    scanf("%i", &novo_item.codigo);
    printf("nome do item:");
    scanf(" %[^\n]", &novo_item.nome);// " %[^\n]" serve para ele le até dar enter
    printf("preço do item:");
    scanf("%f", &novo_item.preco);
    printf("quantidade do item:");
    scanf("%i", &novo_item.quantidade);

    inventario[quant_iten] = novo_item; // adiciona o item no array
    quant_iten ++ ;
    printf("item adicionado \n");
}

void atualizar_iten()
{
    int codigo;
    int encontrado = -1;
    printf("digite o codigo do produto:");
    scanf("%d", &codigo);
    for(int i = 0; i < quant_iten; i += 1)
    {
        if(inventario[i].codigo == codigo)//ele vai passar por cada iten da lista e comparar com o codigo
        {
         encontrado = i;
         break;   
        }
    }   
    if (encontrado == -1)
    {
        printf("nenhum item encontrado com esse codigo");
        return;
    }
    if (encontrado != -1)
    {
        printf("nome do item:");
        scanf(" %[^\n]", &inventario[encontrado].nome);// " %[^\n]" serve para ele le até dar enter
        printf("preço do item:");
        scanf("%f", &inventario[encontrado].preco);
        printf("quantidade do item:");
        scanf("%i", &inventario[encontrado].quantidade);
    }
    
}
void ver_iten()
{
    int codigo;
    int encontrado = -1 ; 
    printf("digite o codigo do produto:");
    scanf("%d", &codigo);
    for (int i = 0; i < quant_iten; i++)
    {
        if (inventario[i].codigo == codigo)
        {
            encontrado = i;
            break;
        }
    }
    if (encontrado == -1)
    {
        printf("nenhum iten encotrado com esse codigo");
        return;
    }
    if (encontrado != -1)
    {
        printf("o codigo do iten: %d \n", codigo);
        printf("nome do produto: %s \n", inventario[encontrado].nome);
        printf("o preço do iten: %.2f \n", inventario[encontrado].preco);
        printf("temos no estoque: %d \n", inventario[encontrado].quantidade);
    }
    
}
int main(void)
{

    int continuar = 1;
    setlocale(LC_ALL,"portuguese");// resolver isso o quanto antes para a escrita não bugar
    while ( continuar == 1 )
    {
        int opcao;
        printf("----sistema hortifruit---- \n");
        printf("(1)adicionar iten \n");
        printf("(2)atualizar iten \n");
        printf("(3)ver itens cadastrados\n");
        printf("(4)caixa\n");
        printf("(5)sair\n");
        printf("digite a opção:");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
                printf("adicionar iten \n");
                adicionar_iten();
                break;
            case 2:
                printf("(2)atualizar iten \n");
                atualizar_iten();
                break;
            case 3:
                printf("ver iten \n");
                ver_iten();
                break;
            case 4:
                printf("caixa");
                break;
            case 5:
                printf("saindo do programa");
                continuar = 0;
                break;
            default:
                printf("opção invalida");
                break;
        }
    }
    return 0;
}
