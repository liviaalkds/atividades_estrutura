//Remover em uma Posição Específica
//Encontra o nó anterior ao que será removido.
//Faz o ponteiro prox “pular” o nó que será excluído.

#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *proxendereco;
};

struct cabecalista {
    struct no *cabeca;
};

int removeultimo(struct cabecalista *ptr) {
    if (ptr == NULL || ptr->cabeca == NULL) {
        return 0; // lista vazia ou ponteiro nulo
    }

    struct no *atual = ptr->cabeca;
    struct no *anterior = NULL;

    // Percorre até o penúltimo nó
    while (atual->proxendereco != NULL) {
        anterior = atual;
        atual = atual->proxendereco;
    }

    free(atual);
    anterior->proxendereco = NULL;

    return 1;
}

void exibealista(struct cabecalista lista) {
    struct no *atual = lista.cabeca;
    while (atual != NULL) {
        printf("%d ->", atual ->valor);
        atual = atual->proxendereco;
    }
}

int main() {
    struct cabecalista lista;
    lista.cabeca = NULL;

    struct no *primeiro= malloc(sizeof(struct no));
    struct no *segundo= malloc(sizeof(struct no));
    struct no *terceiro= malloc(sizeof(struct no));
    struct no *quarto= malloc(sizeof(struct no));

    primeiro-> valor = 20;
    segundo-> valor = 45;
    terceiro-> valor = 18;
    quarto-> valor = 12;

    primeiro-> proxendereco = segundo;
    segundo-> proxendereco = terceiro;
    terceiro-> proxendereco = quarto;
    quarto-> proxendereco = NULL;

    lista.cabeca = primeiro;

    printf("Lista antes de remover o último:\n");
    exibealista(lista);

    printf("Após remover o útimo:");
    removeultimo(&lista);
    exibealista(lista);
    return 0;
}
