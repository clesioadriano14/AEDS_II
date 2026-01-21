#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    int idade;
} TipoItem;

typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct
{
    TipoApontador Primeiro,Ultimo;

} TipoLista;

TipoLista Lista;
TipoItem x;
TipoApontador p;
int pos, i, tam =0;

void FLVazia (TipoLista *Lista)
{

    Lista->Primeiro = (TipoApontador)malloc (sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox=NULL;
    tam =0;

}
int Vazia (TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}
void Inserir (TipoItem x, TipoLista *Lista)
{

    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
    tam ++;

}
void Imprimir(TipoLista Lista)
{
    TipoApontador aux;
    aux = Lista.Primeiro->Prox;
    if(Vazia(Lista))
    {
        printf("Sem elementos!");
    }
    else
    {
        while(aux != NULL)
        {
            printf("\nCodigo: %d",aux->Item.cod);
            printf("\nIdade: %d",aux->Item.idade);
            printf("\n--------------------");
            aux = aux->Prox;
        }
    }
}
void RetiraUltimo(TipoLista *Lista, TipoItem *x)
{
    TipoApontador q,z;
    q = Lista->Primeiro->Prox;
    if(Lista->Primeiro == Lista->Ultimo)
    {
        printf("Lista ja esta sem elementos!");
    }
    else
    {
        if(q->Prox == NULL)
        {
            *x = q->Item;
            printf("O elemento retirado foi o de codigo: %d\n",x->cod);
            Lista->Ultimo = Lista->Primeiro;
            Lista->Primeiro->Prox = NULL;
        }
        else
        {
            while(q->Prox != NULL)
            {
                z=q;
                q=q->Prox;
            }
            *x = q->Item;
            printf("O elemento retirado foi o de codigo: %d\n",x->cod);
            Lista->Ultimo = z;
            z->Prox=NULL;
        }
        free(q);
    }
}

int main()
{
    int opcao, resposta;
    FLVazia(&Lista);
    do
    {
        printf("\n\n--------Menu---------\n");
        printf("\nDigite a opcao desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Lista\n");
        printf("2 - Verificar Lista\n");
        printf("3 - Inserir elemento\n");
        printf("4 - Imprimir elementos\n");
        printf("5 - Retirar ultimo elemento\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            printf("PROGRAMA ENCERRADO");
            break;
        case 1:
            FLVazia(&Lista);
            printf("\nLista Esvaziada\n");
            break;
        case 2:
            resposta = Vazia(Lista);
            if(resposta == 1)
                printf("Ta Vazia");
            else
                printf("Nao Vazia");
            break;
        case 3:
            printf("Cod: ");
            scanf("%d",&x.cod);
            printf("Idade: ");
            scanf("%d",&x.idade);
            Inserir(x, &Lista);
            break;
        case 4:
            Imprimir(Lista);
            break;
        case 5:
            RetiraUltimo(&Lista, &x);
            break;
        default:
            printf("\nOpcao invalida\n\n");
        }
        _getch(); // Segura a tela
        system("cls"); // limpa a tela
    }
    while (opcao != 0);

}
