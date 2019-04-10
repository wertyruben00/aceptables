#include <iostream>

using namespace std;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
int main()
{
    int t,n,l; // Test cases, N Cota superior para primos, L largo del pangrama
    cin >> t;
    while(t--){
        int alpha[26] = {0}; // Alfabeto
        int flag = 0; // Variable de control
        cin >> n;
        cin >> l;
        int arr[l]; // Arrgelo de produtos
        int arrT[l+1]; // Arreglo de los factores
        for(int i = 0 ; i < l ; i++){
            cin >> arr[i];
        }

        for(int i = 0 ; i < l ; i++){
            if(arr[i]==arr[i+1]){ // Checar si los primeros elementos son iguales
                flag = i+1; // Saber hasta donde llegan los elementos iguales
            }else{
                break; // Dentener el for
            }
        }
        arrT[flag+1] = gcd(arr[flag],arr[flag+1]); // Se obtiene los factores del primer numero que no es igual a todos los anteriores (si es que hay)
        arrT[flag] = arr[flag] / arrT[flag+1];
        for(int i = flag + 1; i < l ; i++){ // Comienza a sacar los factores de los elementos despues de los primeros elementos iguales
            arrT[i+1] = arr[i] / arrT[i];
        }
        if(flag != 0){ // Si al principio hubieron elementos iguales, entra esta condicion
            for(int i = flag ; i >= 0 ; i--){
                arrT[i-1]=arr[i]/arrT[i]; // Obtiene los factores de los primeros elementos
            }
        }
        for(int i = 0 ; i < l+1 ; i++){
            cout << arrT[i] << " ";
        }

    }
    return 0;
}
