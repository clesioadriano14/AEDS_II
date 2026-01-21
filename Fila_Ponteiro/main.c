#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    TipoApontador Frente, Tras;
} TipoFila;

TipoFila Fila;
TipoItem x;

void FFVazia (TipoFila *Fila)
{
    Fila->Frente = (TipoApontador)malloc(sizeof(TipoCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox=NULL;
}
int Vazia(TipoFila Fila)
{
    return(Fila.Tras == Fila.Frente);
}

void Enfileira(TipoItem x, TipoFila *Fila)
{
    Fila->Tras->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
    //TAM ++;
}

void Imprime(TipoFila Fila)
{
    TipoApontador aux;
    aux = Fila.Frente->Prox;
    while(aux != NULL)
    {
        printf("\nCodigo: %d",aux->Item.cod);
        printf("\nIdade: %d",aux->Item.idade);
        aux = aux->Prox;
    }
}

void Retira (TipoFila *Fila)
{
    if(Vazia(*Fila))
    {
        printf("Fila Vazia!!");
    }
    else
    {

        TipoApontador aux;
        aux = (TipoApontador)malloc(sizeof(TipoCelula));
        aux = Fila->Frente;
        Fila->Frente = aux->Prox;
        free(aux);
    }
}
void Procura(TipoFila Fila, TipoItem x)
{
    TipoApontador t;
    bool encontrou = false;
    if(Fila.Frente == Fila.Tras)
    {
        printf("Fila vazia!");
    }
    else
    {
        t = Fila.Frente->Prox;
        while(t != NULL)
        {
            if (t->Item.cod == x.cod)
            {
                printf("Elemento encontrado!\nCodigo: %d\nIdade: %d\n", t->Item.cod,t->Item.idade);
                encontrou = true;
                break;
            }
            t = t->Prox;
        }
        if(!encontrou )
        {
            printf("Elemento nao encontrado");
        }
    }
}

int main()
{
    int opcao, resposta;
    FFVazia(&Fila);
    do
    {
        printf("\n\n--------Menu---------\n");
        printf("\nDigite a opcao desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Fila\n");
        printf("2 - Verificar Fila\n");
        printf("3 - Inserir elemento\n");
        printf("4 - Imprimir elemento(s)\n");
        printf("5 - Retirar elemento\n");
        printf("6 - Procurar elemento pelo codigo\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            printf("PROGRAMA ENCERRADO");
            break;
        case 1:
            FFVazia(&Fila);
            printf("\nFila Esvaziada\n");
            break;
        case 2:
            resposta = Vazia(Fila);
            if(resposta == 1)
                printf("Esta Vazia");
            else
                printf("Nao Vazia");
            break;
        case 3:
            printf("Cod: ");
            scanf("%d",&x.cod);
            printf("Idade: ");
            scanf("%d",&x.idade);
            Enfileira(x, &Fila);
            break;
        case 4:
            Imprime(Fila);
            break;
        case 5:
            Retira(&Fila);
            break;
        case 6:
            printf("Cod do elemento procurado: ");
            scanf("%d",&x.cod);
            Procura(Fila, x);
            break;
        default:
            printf("\nOpcao invalida\n\n");
        }
        _getch(); // Segura a tela
        system("cls"); // limpa a tela
    }
    while (opcao != 0);
    return(0);
}
