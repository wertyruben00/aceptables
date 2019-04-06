#include <stdio.h>
#include <string.h>
int main(){
    int x;
    int contador = 0;
    scanf(" %i",&x);
    char arreglo[x];   //arreglo a modificar
    char arregloT[x];  //arreglo temporal
    scanf(" %s",&arreglo);
    int condicion = 1;
    while(condicion==1){    //while infinito
        for(int i = 0; i < x; i++){             //iguala los arreglos
            arregloT[i]=arreglo[i];
        }
        for(int i = 0; i < x; i++){             //lee de izquierda a derecha y modifica
            if(arregloT[i]=='R'){
                if(arregloT[i+1]=='1'){
                    if(arregloT[i+2]!='L'){
                        arreglo[i+1]='R';
                        i++;
                    }
                }
            }
        }
        for(int i = x-1; i >=0; i--){            //lee de derecha a izquierda y modifica
            if(arregloT[i]=='L'){
                if(arregloT[i-1]=='1'){
                    if(arregloT[i-2]!='R'){
                        arreglo[i-1]='L';
                        i--;
                    }
                }
            }
        }
        if(strncasecmp(arreglo,arregloT, x-1)==0){  // caso base (compara arreglos)
            for(int i = 0; i < x; i++){
                if(arreglo[i]=='1'){
                    contador++;
                }
            }
            printf("%i",contador);
            return 0;
        }
    }
}
