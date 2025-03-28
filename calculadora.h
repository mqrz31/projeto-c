#ifndef calculadora_h
#define calculadora_h

int menu();

void lePolinomio(int polinomio[], int grau);

void imprimePolinomio(int polinomio[], int grau);

double calculaPolinomio(int polinomio[], int grau, double x);

void somaPolinomio(int polinomio1[], int grau1, int polinomio2[], int grau2, int vres[], int grauMaior);



#endif