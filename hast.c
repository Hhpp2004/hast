#include <stdio.h>
#include <stdlib.h>

typedef struct hast
{
    int valor;
    struct hast *prox;
}hast;

typedef struct tabela
{
    int tam;
    hast **vetor;
}tabela;

tabela *cria_tabela(int tam)
{
    tabela *table = (tabela *)malloc(sizeof(tabela));
    table->tam = tam;
    table->vetor = (hast **)malloc(tam * sizeof(hast *));
    for(int i = 0;i < tam;i++)
    {
        table->vetor[i] = NULL;
    }
    return table;
}

void desaloca(tabela *t)
{
    hast *aux = NULL;
    hast *aux_2 = NULL;
    for(int i = 0;i < t->tam;i++)
    {
        aux = t->vetor[i];
        while(aux != NULL)
        {
            aux_2 = aux->prox;
            free(aux);
            aux = aux_2;
        }
    }
    free(t->vetor);
    free(t);
}

int posicao(int valor,int tam)
{
    return valor%tam;
}

void entrada(tabela *table,int valor)
{
    hast *aux = NULL;
    int pos = posicao(valor,table->tam);
    hast *novo = (hast *)malloc(sizeof(hast));
    novo->valor = valor;
    novo->prox = NULL;
    if(table->vetor[pos] == NULL)
    {
        table->vetor[pos] = novo;
    }
    else
    {
        aux = table->vetor[pos];
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void saida(tabela *table)
{
    hast *aux = NULL;
    for(int i = 0;i < table->tam;i++)
    {
        printf("%i -> ",i);
        aux = table->vetor[i];
        while(aux != NULL)
        {
            printf(" %i -> ",aux->valor);
            aux = aux->prox;
        }
        printf(" \\\n");
    }
}

int main()
{
    int casos_teste;
    int qtd_enderecos;
    int qtd_valores;
    int valores;   
    tabela *table = NULL;

    scanf("%i", &casos_teste);

    for(int i = 0;i < casos_teste;i++)
    {
        scanf("%i",&qtd_enderecos);
        scanf("%i",&qtd_valores);        
        table = cria_tabela(qtd_enderecos);
        for(int j = 0;j < qtd_valores;j++)
        {
            scanf("%i",&valores);            
            entrada(table,valores);
        }
        printf("\n");
        saida(table);
        desaloca(table);
        if(i < casos_teste - 1)
        {
            printf("\n");
        }
    }
    printf("\n");

    return 0;

}