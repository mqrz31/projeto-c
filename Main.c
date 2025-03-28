#include <stdio.h>
#include "calculadora.h"

int main(){

    int escolha = menu();
    
    if (escolha == 1){
        int grau;
        int resultado;
        double x;
        
        printf("Digite o grau do polinômio (expoente de maior valor): ");
        scanf("%d", &grau);
        int polinomio[grau + 1];

        lePolinomio(polinomio, grau);
        imprimePolinomio(polinomio, grau);

        printf("Digite o valor de x para P(x): ");
        scanf("%lf", &x);

        resultado = calculaPolinomio(polinomio, grau, x);
        printf("RESULTADO: %d\n", resultado); 
    }

    else if(escolha == 2){
        int grau1;
        int grau2;
        int grauMaior;
               
        printf("Digite o grau do primeiro polinômio (expoente de maior valor): ");
        scanf("%d", &grau1);
        int polinomio1[grau1 + 1];

        lePolinomio(polinomio1, grau1);
        imprimePolinomio(polinomio1, grau1);

        printf("Digite o grau do segundo polinômio (expoente de maior valor): ");
        scanf("%d", &grau2);
        int polinomio2[grau2 + 1];

        lePolinomio(polinomio2, grau2);
        imprimePolinomio(polinomio2, grau2);
        
        if(grau1 > grau2){
            grauMaior = grau1;
        }
        else{
            grauMaior = grau2;
        }

        int vres[grauMaior];

        somaPolinomio(polinomio1, grau1, polinomio2, grau2, vres, grauMaior);
        printf("RESULTADO: ");
        imprimePolinomio(vres, grauMaior);
    }

return 0;
}