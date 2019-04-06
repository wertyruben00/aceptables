#include <stdio.h>
//El babilonico es un sistema sexagesimal compuesto por "L" e "I"
int babilonico(int n); // Funcion de conversion
int main()
{
    int numero; // Numero a convertir
    scanf(" %i",&numero);
    babilonico(numero);
    return 0;
}
int babilonico(int n){
    int a = n % 60; //Obtenemos el modulo del numero a convertir
    n=(n-a)/60; // Hacemos que se el divisor de 60 mas proximo
    int aL=a/10; // Obtenemos la cantidad de "L"s
    int aI=a%10;// Obtenemos la cantidad de "I"s
    for(int i=0;i<aL;i++){ // Imprimimos "L"s
            printf("L");
        }
    for(int i=0;i<aI;i++){ // Imprimimos "I"s
            printf("I");
        }
    if(n<1){
        return 0; // Cuando n llegue a 0 nos detenemos
    }else{
        printf(".");
        return babilonico(n);
    }
}
