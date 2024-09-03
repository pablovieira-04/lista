#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Fila;

void inicializarFila(Fila *f) {
    f->front = 0;
    f->rear = -1;
}

int filaVazia(Fila *f) {
    return f->front > f->rear;
}

int filaCheia(Fila *f) {
    return f->rear == MAX - 1;
}

void enfileirar(Fila *f, int item) {
    if (filaCheia(f)) {
        printf("A fila está cheia!\n");
        return;
    }
    f->items[++f->rear] = item;
}

int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila está vazia!\n");
        return -1;
    }
    return f->items[f->front++];
}

int frenteFila(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila está vazia!\n");
        return -1;
    }
    return f->items[f->front];
}

void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila está vazia!\n");
        return;
    }
    printf("Itens na fila: ");
    for (int i = f->front; i <= f->rear; i++) {
        printf("%d ", f->items[i]);
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializarFila(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    mostrarFila(&f);

    printf("Item removido: %d\n", desenfileirar(&f));
    mostrarFila(&f);

    printf("Frente da fila: %d\n", frenteFila(&f));

    return 0;
}
