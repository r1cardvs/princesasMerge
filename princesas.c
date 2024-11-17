#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char origem[100];
    int idade;
    char ponto_forte[200];
    char ponto_fraco[100];
    int agressividade;
    int beleza;
} Princesa;

void imprimirPrincesas(Princesa princesas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s, Agressividade: %d\n", princesas[i].nome, princesas[i].agressividade);
    }
}

void merge(Princesa array[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Princesa esquerda[n1], direita[n2];

    for (int i = 0; i < n1; i++)
        esquerda[i] = array[inicio + i];
    for (int j = 0; j < n2; j++)
        direita[j] = array[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (esquerda[i].agressividade <= direita[j].agressividade) {
            array[k] = esquerda[i];
            i++;
        } else {
            array[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(Princesa array[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);

        merge(array, inicio, meio, fim);
    }
}

int main() {
    Princesa princesas[] = {
        {"Branca de Neve", "Reino não especificado", 14, "Gentileza e capacidade de inspirar amizade", "Ingenuidade", 1, 8},
        {"Cinderela", "Reino não especificado", 19, "Resiliência e otimismo", "Dependência de ajuda mágica", 2, 9},
        {"Aurora", "Reino não especificado", 16, "Graça e beleza natural", "Inatividade", 1, 9},
        {"Ariel", "Oceano Atlântico", 16, "Curiosidade e determinação", "Impulsividade", 3, 9},
        {"Bela", "Pequena aldeia francesa", 17, "Inteligência e empatia", "Tendência a se sacrificar pelos outros", 2, 10},
        {"Jasmine", "Agrabah", 15, "Independência e coragem", "Impulsividade", 3, 9},
        {"Pocahontas", "América do Norte", 18, "Espiritualidade e conexão com a natureza", "Tendência a confiar em estranhos", 4, 9},
        {"Mulan", "China", 16, "Astúcia e coragem", "Insegurança inicial sobre suas habilidades", 5, 8}
    };

    int tamanho = sizeof(princesas) / sizeof(princesas[0]);

    printf("Lista original:\n");
    imprimirPrincesas(princesas, tamanho);

    mergeSort(princesas, 0, tamanho - 1);

    printf("\nLista ordenada por agressividade:\n");
    imprimirPrincesas(princesas, tamanho);

    return 0;
}
