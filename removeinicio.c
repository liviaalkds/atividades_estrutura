#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *proximo;
};

struct cabecaLista {
    struct no *cabeca;
};

// funções
void iniciarLista(struct cabecaLista *ptr);
void inserirFinal(struct cabecaLista *ptr);
void exibirLista(struct cabecaLista *ptr);
int removeUltimo(struct cabecaLista *ptr);
int ordenarLista(struct cabecaLista *ptr);

int main() {
    struct cabecaLista *cabecas = malloc(sizeof *cabecas);
    cabecas->cabeca = NULL; // importante!
    bool continuar = 1;
    int escolhaUser;

    while (continuar) {
        printf("================================\n");
        printf("\nEscolha:\n [0] Sair;\n [1] Iniciar Lista;\n [2] Inserir no final;\n [3] Exibir Lista;\n [4] Remover último;\n [5] Ordenar Lista;\n");
        printf("================================\n");
        scanf("%d", &escolhaUser);

        switch (escolhaUser) {
        case 0:
            continuar = 0;
            break;

        case 1:
            iniciarLista(cabecas);
            break;

        case 2:
            inserirFinal(cabecas);
            break;

        case 3:
            exibirLista(cabecas);
            printf("\n");
            break;

        case 4:
            if (removeUltimo(cabecas)) {
                printf("Lista atualizada: ");
                exibirLista(cabecas);
                printf("\n");
            } else {
                printf("A lista está vazia!\n");
            }
            break;

        case 5:
            ordenarLista(cabecas);
            exibirLista(cabecas);
            printf("\n");
            break;
        }
    }
}

void iniciarLista(struct cabecaLista *ptr) {
    struct no *novo = malloc(sizeof *novo);
    printf("Insira o valor inicial: ");
    scanf("%d", &novo->valor);
    novo->proximo = NULL;
    ptr->cabeca = novo;
}

void inserirFinal(struct cabecaLista *ptr) {
    struct no *novo = malloc(sizeof *novo);
    printf("Insira o valor: ");
    scanf("%d", &novo->valor);
    novo->proximo = NULL;

    if (ptr->cabeca == NULL) {
        ptr->cabeca = novo;
        return;
    }

    struct no *atual = ptr->cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
}

void exibirLista(struct cabecaLista *ptr) {
    struct no *atual = ptr->cabeca;
    if (atual == NULL) {
        printf("Lista vazia!");
        return;
    }

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int removeUltimo(struct cabecaLista *ptr) {
    if (ptr->cabeca == NULL) return 0;

    struct no *atual = ptr->cabeca;
    struct no *anterior = NULL;

    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        free(ptr->cabeca);
        ptr->cabeca = NULL;
    } else {
        anterior->proximo = NULL;
        free(atual);
    }

    return 1;
}

int ordenarLista(struct cabecaLista *ptr) {
    if (ptr->cabeca == NULL) {
        printf("A lista está vazia.\n");
        return 0;
    }

    struct no *pa, *pb;
    struct no *fim = NULL;
    int temp;

    // Bubble Sort
    for (pa = ptr->cabeca; pa->proximo != NULL; pa = pa->proximo) {
        for (pb = ptr->cabeca; pb->proximo != fim; pb = pb->proximo) {
            if (pb->valor > pb->proximo->valor) {
                temp = pb->valor;
                pb->valor = pb->proximo->valor;
                pb->proximo->valor = temp;
            }
        }
        fim = pb;
    }
    return 1;
}
