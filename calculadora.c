#include <stdio.h>
#include "calculadora.h"


int menu(){
    int escolha;
    printf("====Calculadora de Polinômios====\n");
    printf("(1) Calcular Polinômio \n(2) Somar Polinômios \n(3) Multiplicar Polinômios\n");
    printf("Escolha uma das opções: ");
    scanf("%d", &escolha);
    return escolha;
}

void lePolinomio(int polinomio[], int grau){

    printf("Digite os coeficientes: \n");

    for(int i = 0; i <= grau; i++){
        int expoente = grau - i;
        printf("Coeficiente de x^%d: ", expoente );
        scanf("%d", &polinomio[expoente]);  
    }
}


void imprimePolinomio(int polinomio[], int grau){

    printf("Polinômio: ");

    int primeiro = 1;

    for (int i = grau; i >= 0; i--) {
        int coef = polinomio[i];

        if (coef == 0) continue;

        
        if (!primeiro) {
            printf(coef > 0 ? " + " : " - ");
        } else if (coef < 0) {
            printf("-");
        }

        
        if (coef != 1 && coef != -1 || i == 0) {
            printf("%d", coef > 0 ? coef : -coef);
        }

        
        if (i > 0) printf("x");

        
        if (i > 1) printf("^%d", i);

        primeiro = 0;
    }

    printf("\n");
}

double calculaPolinomio(int polinomio[], int grau, double x) {

    double resultado = polinomio[grau]; 

    for (int i = grau - 1; i >= 0; i--) {
        resultado = resultado * x + polinomio[i];
    }
    return resultado;
}

void somaPolinomio(int polinomio1[], int grau1, int polinomio2[], int grau2, int vres[], int grauMaior){
    int soma;
    for(int i = 0; i <= grau1; i++){
        for(int j = 0; j <= grau2; j++){
            soma = polinomio1[i] + polinomio2[j];
            vres[grauMaior] = soma;
        }
    }

}

