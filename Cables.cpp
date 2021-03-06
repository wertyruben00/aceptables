#include<stdio.h>
int recorrer(int ar[], int SumC, int n, int mid){
    //Funcion que busca cuantos posibles numeros dan K al hacer la sumatoria y regresa el mayor
    int SumTemp = SumC;
    // Variable comodin
    while(SumC == SumTemp){
        // Mientras la sumatoria siga dando K, este while corre
        mid++;
        SumTemp = 0;
        for(int i = 0 ; i < n ; i ++){
            // Obtencion de sumatorias posteriores
            SumTemp += ar[i]/mid;
        }
    }
    // Al salir del while, la condicion se dejo de cumplir, y como mid iba aumentando tenemos que regresarlo al valor anterior, que si cumplia con la condicion
    mid --;
    return mid;
}
int maxM(int ar[],int n, int k, int top){
    // Se cambia cG por top, refiriendose a el tope de nuestra busqueda binaria
    int bot = 0;
    // Piso de la busqueda binaria
    while(bot < top){
        int mid = (top + bot) / 2;
        // Obtencion de la mitad de la busqueda binaria
        int SumC = 0;
        // Sumatoria de todos los cables al ser dividios por mid (cada uno de ellos es truncado antes de ser sumado)
        for(int i = 0 ; i < n ; i ++){
            SumC += ar[i]/mid;
            // Obtencion de la sumatoria
        }
        if(SumC > k){
            // si la sumatoria es mayor que los cables que deseamos, nuestro piso cambia a ser mid + 1
            bot = mid + 1;
        }else if(SumC < k){
            // si la sumatoria es menor que los cables que deseamos, nuestro tope cambia a ser mid - 1
            top = mid - 1;
        }else{
            return recorrer(ar, SumC, n, mid);
        }
    }
}
int main()
{
    int t,n,k,i;
    // t = test cases, n = cables disponibles, k = cables que se necesitan e i = un simple iterador
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        int ar[n];
        // Arreglo de cables disponibles
        int cG = 0;
        // Cable mas grande
        for(i = 0 ; i < n ; i++){
            scanf("%d",&ar[i]);
            // Obtencion de datos
            if(cG < ar[i]){
                cG = ar[i];
                // Obtencion del cable mas grande
            }
        }
        printf("%d\n",maxM(ar,n,k,cG));
    }
}
