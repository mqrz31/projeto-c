#include <stdio.h>
#include "calculadora.h" // Inclusão do cabeçalho contendo as funções utilizadas

int main() {
    
    while(1){

        // Apresenta o menu e recebe a escolha do usuário
        int escolha = menu();
        
        // Caso o usuário escolha a opção de calcular P(x)
        if (escolha == 1) { 
            int grau;
            int resultado;
            double x;
            
            // Solicita ao usuário o grau do polinômio
            printf("Digite o grau do polinômio (expoente de maior valor): ");
            scanf("%d", &grau);
            
            // Declaração do array para armazenar os coeficientes do polinômio
            int polinomio[grau + 1];

            // Função para leitura dos coeficientes do polinômio
            lePolinomio(polinomio, grau);
            
            // Função para exibição do polinômio formatado
            imprimePolinomio(polinomio, grau);

            // Solicita ao usuário o valor de x para cálculo de P(x)
            printf("Digite o valor de x para P(x): ");
            scanf("%lf", &x);

            // Chama a função que calcula o valor do polinômio para x
            resultado = calculaPolinomio(polinomio, grau, x);
            
            // Exibe o resultado do cálculo
            printf("RESULTADO: %d\n", resultado);
            break;
        }
        
        // Caso o usuário escolha a opção de somar polinômios
        else if (escolha == 2) { 
            int grau1, grau2, grauMaior;
                
            // Solicita ao usuário o grau do primeiro polinômio
            printf("Digite o grau do primeiro polinômio (expoente de maior valor): ");
            scanf("%d", &grau1);
            
            // Declaração do array para armazenar os coeficientes do primeiro polinômio
            int polinomio1[grau1 + 1];

            // Função para leitura dos coeficientes do primeiro polinômio
            lePolinomio(polinomio1, grau1);
            
            // Exibição do primeiro polinômio
            imprimePolinomio(polinomio1, grau1);

            // Solicita ao usuário o grau do segundo polinômio
            printf("Digite o grau do segundo polinômio (expoente de maior valor): ");
            scanf("%d", &grau2);
            
            // Declaração do array para armazenar os coeficientes do segundo polinômio
            int polinomio2[grau2 + 1];

            // Função para leitura dos coeficientes do segundo polinômio
            lePolinomio(polinomio2, grau2);
            
            // Exibição do segundo polinômio
            imprimePolinomio(polinomio2, grau2);
            
            // Determina o maior grau entre os dois polinômios
            if (grau1 > grau2) {
                grauMaior = grau1;
            } else {
                grauMaior = grau2;
            }

            // Declaração do array para armazenar o resultado da soma dos polinômios
            int vres[grauMaior];

            // Chama a função que realiza a soma dos polinômios
            somaPolinomio(polinomio1, grau1, polinomio2, grau2, vres, grauMaior);
            
            // Exibe o polinômio resultante da soma
            printf("RESULTADO: ");
            imprimePolinomio(vres, grauMaior);
            break;
        }

        else if(escolha == 3) {
            int grau1, grau2, grauRes;

            // Solicita ao usuário o grau do primeiro polinômio
            printf("Digite o grau do primeiro polinômio (expoente de maior valor): ");
            scanf("%d", &grau1);
            
            // Declaração do array para armazenar os coeficientes do primeiro polinômio
            int poli1[grau1 + 1];

            // Função para leitura dos coeficientes do primeiro polinômio
            lePolinomio(poli1, grau1);
            
            // Exibição do primeiro polinômio
            imprimePolinomio(poli1, grau1);

            // Solicita ao usuário o grau do segundo polinômio
            printf("Digite o grau do segundo polinômio (expoente de maior valor): ");
            scanf("%d", &grau2);
            
            // Declaração do array para armazenar os coeficientes do segundo polinômio
            int poli2[grau2 + 1];

            // Função para leitura dos coeficientes do segundo polinômio
            lePolinomio(poli2, grau2);
            
            // Exibição do segundo polinômio
            imprimePolinomio(poli2, grau2);
            
            // Declara o grau resultante como a soma dos graus 1 e 2
            grauRes = grau1 + grau2;
            int vres[grauRes];

            // Função para a multiplicação dos polinômios
            multiplicaPolinomios(poli1, poli2, grau1, grau2, vres);

            printf("RESULTADO: ");
            imprimePolinomio(vres,grauRes);
            break;
        }
        else{
            printf("Opção inválida!");
        }  
    }
    return 0; // Indica que o programa foi executado com sucesso
}
