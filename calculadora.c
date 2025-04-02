#include <stdio.h>
#include "calculadora.h" // Inclusão do cabeçalho contendo as funções para manipulação de polinômios

// Função para exibir o menu e capturar a escolha do usuário
int menu() {
    int escolha;
    printf("==== Calculadora de Polinômios ====\n");
    printf("(1) Calcular Polinômio \n(2) Somar Polinômios \n(3) Multiplicar Polinômios\n");
    printf("Escolha uma das opções: ");
    scanf("%d", &escolha);
    return escolha; // Retorna a opção escolhida pelo usuário
}

// Função para ler os coeficientes de um polinômio
void lePolinomio(int poli[], int grau) {
    printf("Digite os coeficientes: \n");

    for (int i = 0; i <= grau; i++) {
        int expoente = grau - i;
        printf("Coeficiente de x^%d: ", expoente);
        scanf("%d", &poli[expoente]);  // Armazena os coeficientes na posição correspondente
    }
}

// Função para imprimir um polinômio formatado
void imprimePolinomio(int poli[], int grau) {
    printf("Polinômio: ");

    int primeiro = 1; // controlar a impressão do primeiro termo

    for (int i = grau; i >= 0; i--) {
        int coef = poli[i];

        if (coef == 0) {
            continue; // Ignora coeficientes iguais a zero
        }

        // Adiciona sinais corretamente entre os termos
        if (!primeiro) {
            if (coef > 0) {
                printf(" + ");
            } 
            else {
                printf(" - ");
            }
        } 
        else if (coef < 0) {
            printf("-");
        }

        // Imprime o coeficiente, exceto quando for 1 ou -1 (exceto no termo independente)
        if ((coef != 1 && coef != -1) || i == 0) {
            if (coef > 0) {
                printf("%d", coef);
            } 
            else {
                printf("%d", -coef);
            }
        }

        // Imprime a variável x quando necessário
        if (i > 0) {
            printf("x");
        }
        // Imprime o expoente quando for maior que 1
        if (i > 1) {
            printf("^%d", i);
        }

        primeiro = 0; // Após o primeiro termo, ativa a impressão dos sinais
    }

    printf("\n");
}

// Função para calcular o valor do polinômio para um dado x
double calculaPolinomio(int poli[], int grau, double x) {
    double resultado = poli[grau]; // Inicializa com o coeficiente do maior grau

    for (int i = grau - 1; i >= 0; i--) {
        resultado = resultado * x + poli[i]; // Algoritmo de Horner para avaliação eficiente
    }
    return resultado;
}

// Função para somar dois polinômios e armazenar o resultado em vres
void somaPolinomio(int poli1[], int grau1, int poli2[], int grau2, int vres[], int grauMaior) {

    // Percorre o vetor e declara os coeficientes 1 e 2
    for (int i = 0; i <= grauMaior; i++) {
        int coef1;
        int coef2;

    // Condição para atribuir o valor contido no indice i do polinomio 1 ao coeficiente 1     
        if (i <= grau1) {
            coef1 = poli1[i];
        } 
        else {
            coef1 = 0;
        }
    // Condição para atribuir o valor contido no indice i do polinomio 2 ao coeficiente 2     
        if (i <= grau2) {
            coef2 = poli2[i];
        } 
        else {
            coef2 = 0;
        }

        vres[i] = coef1 + coef2; // Soma os coeficientes correspondentes
    }
}


// Função para multiplicar dois polinômios e armazenar o resultado simplificado
void multiplicaPolinomios(int poli1[], int poli2[], int grau1, int grau2, int vres[]) {
    int grauRes = grau1 + grau2;

    // Inicializa o polinômio resultante com coeficientes zerados
    for (int i = 0; i <= grauRes; i++) {
        vres[i] = 0;
    }

    // Multiplica cada termo de poli1 por cada termo de poli2
    for (int i = 0; i <= grau1; i++) {
        for (int j = 0; j <= grau2; j++) {
            vres[i + j] += poli1[i] * poli2[j];
        }
    }
}
