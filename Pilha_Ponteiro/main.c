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
    TipoApontador Fundo, Topo;
    int TAM;
} TipoPilha;
TipoPilha Pilha;
TipoItem x;

void FPVazia (TipoPilha *Pilha)
{
    Pilha->Topo = (TipoApontador)malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->TAM = 0;
}
int Vazia(TipoPilha Pilha)
{
    return(Pilha.Topo == Pilha.Fundo);
}
void Empilha (TipoItem x, TipoPilha *Pilha)
{
    TipoApontador aux;
    aux = (TipoApontador)malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    aux->Prox = Pilha->Topo;
    Pilha->Topo = aux;
    Pilha->TAM = Pilha->TAM + 1;
}

void ImprimeTopoFundo(TipoPilha Pilha)
{
    TipoApontador aux;
    aux = Pilha.Topo->Prox;
    while(aux != NULL)
    {
        printf("\nCodigo: %d",aux->Item.cod);
        printf("\nIdade: %d",aux->Item.idade);
        aux = aux->Prox;
    }
}

void RetiraUltimo(TipoPilha *Pilha, TipoItem *x)
{
    TipoApontador q;
    q = (TipoApontador)malloc(sizeof(TipoCelula));
    q = Pilha->Topo->Prox;
    if(Pilha->Topo == Pilha->Fundo)
    {
        printf("Lista vazia!");
    }
    else
    {
        q = Pilha->Topo;
        Pilha->Topo = q->Prox;
        *x = q->Prox->Item;
        printf("O elemento retirado foi o de codigo: %d\n",x->cod);
        free(q);
        Pilha->TAM = Pilha->TAM -1;
    }
}

void Procura(TipoPilha Pilha, TipoItem x)
{
    TipoApontador aux;
    bool encontrou = false;
    if(Vazia(Pilha))
    {
        printf("Erro: Lista Vazia!");
    }
    else
    {
        aux = Pilha.Topo->Prox;
        while(aux != NULL)
        {
            if(aux->Item.cod == x.cod)
            {
                printf("\nCodigo: %d",aux->Item.cod);
                printf("\nIdade: %d",aux->Item.idade);
                encontrou = true;
                break;
            }
            aux = aux->Prox;
        }
        if(!encontrou)
        {
            printf("Elemento nao encontrado!");
        }
    }
}
void QtdParesImpares(TipoPilha Pilha, TipoItem x)
{
    int contpar = 0, contimpar = 0;
    TipoApontador aux;
    aux = Pilha.Topo->Prox;
    while(aux != NULL)
    {
        if(aux->Item.idade%2 == 0)
        {
            contpar ++;
        }
        else
        {
            contimpar ++;
        }
        printf("\nCodigo: %d",aux->Item.cod);
        printf("\nIdade: %d",aux->Item.idade);
        aux = aux->Prox;
    }
    printf("\nIdades pares: %d",contpar);
    printf("\nIdades impares: %d",contimpar);

}
int main()
{
    int opcao, resposta;
    FPVazia(&Pilha);
    do
    {
        printf("\n\n--------Menu---------\n");
        printf("\nDigite a opcao desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Pista\n");
        printf("2 - Verificar Pista\n");
        printf("3 - Inserir elemento\n");
        printf("4 - Imprimir elementos\n");
        printf("5 - Retirar ultimo elemento\n");
        printf("6 - Procurar elemento pelo codigo\n");
        printf("7 - Verificar quantidade de idades pares e impares\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            printf("PROGRAMA ENCERRADO");
            break;
        case 1:
            FPVazia(&Pilha);
            printf("\nPilha Esvaziada\n");
            break;
        case 2:
            resposta = Vazia(Pilha);
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
            Empilha(x, &Pilha);
            break;
        case 4:
            ImprimeTopoFundo(Pilha);
            break;
        case 5:
            RetiraUltimo(&Pilha, &x);
            break;
        case 6:
            printf("Digite o codigo do elemento: ");
            scanf("%d",&x.cod);
            Procura(Pilha, x);
            break;
        case 7:
            QtdParesImpares(Pilha, x);
            break;
        default:
            printf("\nOpcao invalida\n\n");
        }
        _getch(); // Segura a tela
        system("cls"); // limpa a tela
    }
    while (opcao != 0);
}
