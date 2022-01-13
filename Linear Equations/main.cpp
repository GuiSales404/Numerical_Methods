#include <iostream>
#include <fstream>

using namespace std;

double* substituicoes_retroativas(double *a, double *b, int n)
{
    double *x;
    x = (double*) malloc(n * sizeof(double));
    
    *(x + (n - 1)) = (*(b + (n - 1))) / (*(a + (n * n) - 1));        

    for(int i  = n - 2; i >= 0; i--)
    {
        double soma = 0;
        for(int j = i + 1; j <= n - 1; j++)
        {
            soma = soma + (*(a + (n * i) + j) * *(x + j));
        }
        *(x + i) = (*(b + i) - soma) / *(a + (n * i) + i);
    }
    return x;
}

double* eliminacao_gauss(double *a, double *b, int n)
{
    for(int k = 0; k < n - 1; k++)
    {
        
        for(int i  = k + 1; i < n; i++)
        {
            double m = -(*(a + (n * i) + k)) / (*(a + (n * k) + k));
            *(a + (n * i) + k) = 0;

            for(int j = k + 1; j < n; j++)
            {
                *(a + (n * i) + j) = *(a + (n * i) + j) + (m * *(a + (n * k) + j));
            }
            *(b + i) = *(b + i) + (m * *(b + k));
        }
    }
    return substituicoes_retroativas(a, b, n);
}

int main(){
    double *x;              //vetor de solução
    double matrCoef[] =  { 1, -3, 2,  // Matriz dos coeficientes
                          -2, 8, -1,
                          4, -6, 5};

    /*double a[] = 
        {10, 1, 1,
        1, 10, 1,
        1, 1, 10};
    double b[] = {12, 12, 12};
    */
   /*
    double a[] = 
        {7, 1, 12,
        4, 3, -1,
        -1, 1, 8};
    double b[] = {13, 1, -2};
    */
   /*
    double a[] = 
        {1, 1, 0,
        1, 0, -1,
        1, 1, 1};
    double b[] = {2, 4, 3};
    */

    double matrTermInd[3] =   {11, -15, 29};   //Matriz dos termos independentes(coluna)
    x = eliminacao_gauss(matrCoef, matrTermInd, 3);


    cout<<"Solucao do sistema: [ ";
    for(int i = 0; i<3; i++){
        cout << x[i] << ' ';
    }
    cout<<"] ";
}