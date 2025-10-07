#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *enderecoProx;
};

struct cabecaLista {
    struct no *cabeca;
};

int iniciarLista(struct cabecaLista *ptr);

int inserirInicio(struct cabecaLista *ptr);

int exibirLista(struct cabecaLista *ptr);

int removercabecaLista (struct cabecaLista *ptr);

int main() {
    struct cabecaLista *cabecas = malloc(sizeof *cabecas);
    bool continuar = 1;
    int escolhaUser;

    while (continuar) {
        printf("================================\n");
        printf("Escolha:\n [0] Sair;\n [1] Iniciar Lista;\n [2] Inserir numero no Início da lista;\n [3] Exibir a Lista;\n [4] Remover a cabeca da lista;\n");
        printf("================================\n");
        scanf("%d", &escolhaUser);

        switch (escolhaUser){

        case 0:
            continuar = 0;
            break;

        case 1:
            iniciarLista(cabecas);
            break;

        case 2:
            inserirInicio(cabecas);
            break;

        case 3:
            exibirLista(cabecas);
            break; 
            
        case 4:
        if (removercabecaLista(cabecas)) {
            printf("Lista atualizada: \n ");
            exibirLista(cabecas);
            printf("\n");
        
        }
        else {
            printf("A lista está vazia!\n");
        
        break;
        }
        

        default:
            printf("Valor nao aceito!\n");
        break;
        }
    }
}

int iniciarLista(struct cabecaLista *ptr) {
    struct no *no = malloc(sizeof *no);
    ptr->cabeca = no;
    
    printf("Insira o valor: \n");
    scanf("%d", &no->valor);
    no->enderecoProx = NULL;
}

int inserirInicio(struct cabecaLista *ptr) {
    struct no *no = malloc(sizeof *no);
    no->enderecoProx = ptr->cabeca; 
    
    printf("Insira o valor: \n");
    scanf("%d", &no->valor);
    ptr->cabeca = no;
}

int exibirLista(struct cabecaLista *ptr) {
    struct no *ptrI;
    ptrI = ptr->cabeca;

    while(ptrI != NULL){
        //printf("%d", ptr->cabeca->valor);
        
        printf("%d ", ptrI->valor);
        ptrI = ptrI->enderecoProx;
    }
}
int removercabecaLista(struct cabecaLista *ptr) {
    if (ptr->cabeca == NULL) {
        return 0;
    }

    struct no *temp = ptr->cabeca;             // guarda a cabeça atual
    ptr->cabeca = ptr->cabeca->enderecoProx;   // move para o próximo nó
    free(temp);                                // libera o nó antigo

    return 1; // indica que removeu
}
