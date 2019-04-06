#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    char sudoku[9][9];
    int contador = 0; // CONTADOR MULTIPLE
    int row[9] = {0,0,0,0,0,0,0,0,0}; // IMPARIEDADES DE CADA SECCION
    int col[9] = {0,0,0,0,0,0,0,0,0};
    int block[9] = {0,0,0,0,0,0,0,0,0};
    int resultado = 0;

    for(int i = 0 ; i < 9 ; i++){ // CAPTURA DE SUDOKU
        for(int j = 0 ; j < 9 ; j++){
            cin >> sudoku[i][j];
        }
    }

    for(int i = 0 ; i < 9 ; i++){ // CUENTA IMPARIEDADES DE ROW
        contador = 0;
        for(int j = 0 ; j < 9 ; j++){
            if (sudoku[i][j] == '1'){
                contador++;
            }
        }
        if(contador%2==0){
            row[i]=0;
        }else{
            row[i]=1;
        }
    }

    for(int i = 0 ; i < 9 ; i++){ // CUENTA IMPARIEDADES DE COL
        contador = 0;
        for(int j = 0 ; j < 9 ; j++){
            if (sudoku[j][i] == '1'){
                contador++;
            }
        }
        if(contador%2==0){
            col[i]=0;
        }else{
            col[i]=1;
        }
    }

    for(int i = 0 ; i < 9 ; i++){ // CUENTA IMPARIEDADES DE BLOCK, DE AQUI, HASTA....
        contador = 0;
        switch(i){
        case 0:
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    if (sudoku[j][k] == '1'){
                contador++;
                    }
                }
            }
            if(contador%2==0){
            block[i]=0;
            }else{
                block[i]=1;
            }
            break;

        case 1:
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 3 ; k < 6 ; k++){
                    if (sudoku[j][k] == '1'){
                contador++;
                    }
                }
            }
            if(contador%2==0){
            block[i]=0;
            }else{
                block[i]=1;
            }
            break;

        case 2:
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 6 ; k < 9 ; k++){ // MAS ABAJO...
                    if (sudoku[j][k] == '1'){
                contador++;
                    }
                }
            }
            if(contador%2==0){
            block[i]=0;
            }else{
                block[i]=1;
            }
            break;

         case 3:
            for(int j = 3 ; j < 6 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    if (sudoku[j][k] == '1'){
                contador++;
                    }
                }
            }
            if(contador%2==0){
            block[i]=0;
            }else{
                block[i]=1;
            }
            break;

        case 4:
            for(int j = 3 ; j < 6 ; j++){
                for(int k = 3 ; k < 6 ; k++){ // MAS ABAJO AUN...
                    if (sudoku[j][k] == '1'){
                contador++;
                    }
                }
            }
            if(contador%2==0){
            block[i]=0;
            }else{
                block[i]=1;
            }
            break;

        case 5:
            for(int j = 3 ; j < 6 ; j++){
                for(int k = 6 ; k < 9 ; k++){
                    if (sudoku[j][k] == '1'){
                contador++;
                    }
                }
            }
            if(contador%2==0){
            block[i]=0;
            }else{
                block[i]=1;
            }
            break;

         case 6:
            for(int j = 6 ; j < 9 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    if (sudoku[j][k] == '1'){
                contador++;
                    }
                }
            }
            if(contador%2==0){
            block[i]=0;
            }else{
                block[i]=1;
            }
            break;

        case 7:
            for(int j = 6 ; j < 9 ; j++){
                for(int k = 3 ; k < 6 ; k++){
                    if (sudoku[j][k] == '1'){
                contador++;
                    }
                }
            }
            if(contador%2==0){
            block[i]=0;
            }else{
                block[i]=1;
            }
            break;

        case 8:
            for(int j = 6 ; j < 9 ; j++){
                for(int k = 6 ; k < 9 ; k++){ // YA MERO...
                    if (sudoku[j][k] == '1'){
                contador++;
                    }
                }
            }
            if(contador%2==0){
            block[i]=0;
            }else{
                block[i]=1;
            }
            break;
        }
    }  // HASTA AQUI xddddddd

    for(int i = 0 ; i < 9 ; i++){// CHECA INTERSECCIONES DE IMPARIEDADES TRIPLES
        switch(i){
            case 0:
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    if((block[i]==1) && (row[j] == 1) && (col[k] == 1)){
                        block[i]=0;
                        row[j]=0;
                        col[k]=0;
                        resultado++;
                    }
                }
            }break;

            case 1:
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 3 ; k < 6 ; k++){
                    if((block[i]==1) && (row[j] == 1) && (col[k] == 1)){
                        block[i]=0;
                        row[j]=0;
                        col[k]=0;
                        resultado++;
                    }
                }
            }break;

            case 2:
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 6 ; k < 9 ; k++){
                    if((block[i]==1) && (row[j] == 1) && (col[k] == 1)){
                        block[i]=0;
                        row[j]=0;
                        col[k]=0;
                        resultado++;
                    }
                }
            }break;

            case 3:
            for(int j = 3 ; j < 6 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    if((block[i]==1) && (row[j] == 1) && (col[k] == 1)){
                        block[i]=0;
                        row[j]=0;
                        col[k]=0;
                        resultado++;
                    }
                }
            }break;

            case 4:
            for(int j = 3 ; j < 6 ; j++){
                for(int k = 3 ; k < 6 ; k++){
                    if((block[i]==1) && (row[j] == 1) && (col[k] == 1)){
                        block[i]=0;
                        row[j]=0;
                        col[k]=0;
                        resultado++;
                    }
                }
            }break;

            case 5:
            for(int j = 3 ; j < 6 ; j++){
                for(int k = 6 ; k < 9 ; k++){
                    if((block[i]==1) && (row[j] == 1) && (col[k] == 1)){
                        block[i]=0;
                        row[j]=0;
                        col[k]=0;
                        resultado++;
                    }
                }
            }break;

            case 6:
            for(int j = 6 ; j < 9 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    if((block[i]==1) && (row[j] == 1) && (col[k] == 1)){
                        block[i]=0;
                        row[j]=0;
                        col[k]=0;
                        resultado++;
                    }
                }
            }break;

            case 7:
            for(int j = 6 ; j < 9 ; j++){
                for(int k = 3 ; k < 6 ; k++){
                    if((block[i]==1) && (row[j] == 1) && (col[k] == 1)){
                        block[i]=0;
                        row[j]=0;
                        col[k]=0;
                        resultado++;
                    }
                }
            }break;

            case 8:
            for(int j = 6 ; j < 9 ; j++){
                for(int k = 6 ; k < 9 ; k++){
                    if((block[i]==1) && (row[j] == 1) && (col[k] == 1)){
                        block[i]=0;
                        row[j]=0;
                        col[k]=0;
                        resultado++;
                    }
                }
            }break;
        }
    }

    for(int i = 0 ; i < 9 ; i++){
        switch(i){
            case 0:
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    if((block[i]==1) && (row[j] == 1)){
                        block[i]=0;
                        row[j]=0;
                        resultado++;
                    }
                    if((block[i]==1) && (col[k] == 1)){
                        block[i]=0;
                        col[k]=0;
                        resultado++;
                    }
                    if((col[k]==1) && (row[j] == 1)){
                        col[k]=0;
                        row[j]=0;
                        resultado++;
                    }
                }
            }break;

            case 1:
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 3 ; k < 6 ; k++){
                    if((block[i]==1) && (row[j] == 1)){
                        block[i]=0;
                        row[j]=0;
                        resultado++;
                    }
                    if((block[i]==1) && (col[k] == 1)){
                        block[i]=0;
                        col[k]=0;
                        resultado++;
                    }
                    if((col[k]==1) && (row[j] == 1)){
                        col[k]=0;
                        row[j]=0;
                        resultado++;
                    }
                }
            }break;

            case 2:
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 6 ; k < 9 ; k++){
                    if((block[i]==1) && (row[j] == 1)){
                        block[i]=0;
                        row[j]=0;
                        resultado++;
                    }
                    if((block[i]==1) && (col[k] == 1)){
                        block[i]=0;
                        col[k]=0;
                        resultado++;
                    }
                    if((col[k]==1) && (row[j] == 1)){
                        col[k]=0;
                        row[j]=0;
                        resultado++;
                    }
                }
            }break;

            case 3:
            for(int j = 3 ; j < 6 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    if((block[i]==1) && (row[j] == 1)){
                        block[i]=0;
                        row[j]=0;
                        resultado++;
                    }
                    if((block[i]==1) && (col[k] == 1)){
                        block[i]=0;
                        col[k]=0;
                        resultado++;
                    }
                    if((col[k]==1) && (row[j] == 1)){
                        col[k]=0;
                        row[j]=0;
                        resultado++;
                    }
                }
            }break;

            case 4:
            for(int j = 3 ; j < 6 ; j++){
                for(int k = 3 ; k < 6 ; k++){
                    if((block[i]==1) && (row[j] == 1)){
                        block[i]=0;
                        row[j]=0;
                        resultado++;
                    }
                    if((block[i]==1) && (col[k] == 1)){
                        block[i]=0;
                        col[k]=0;
                        resultado++;
                    }
                    if((col[k]==1) && (row[j] == 1)){
                        col[k]=0;
                        row[j]=0;
                        resultado++;
                    }
                }
            }break;

            case 5:
            for(int j = 3 ; j < 6 ; j++){
                for(int k = 6 ; k < 9 ; k++){
                    if((block[i]==1) && (row[j] == 1)){
                        block[i]=0;
                        row[j]=0;
                        resultado++;
                    }
                    if((block[i]==1) && (col[k] == 1)){
                        block[i]=0;
                        col[k]=0;
                        resultado++;
                    }
                    if((col[k]==1) && (row[j] == 1)){
                        col[k]=0;
                        row[j]=0;
                        resultado++;
                    }
                }
            }break;

            case 6:
            for(int j = 6 ; j < 9 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    if((block[i]==1) && (row[j] == 1)){
                        block[i]=0;
                        row[j]=0;
                        resultado++;
                    }
                    if((block[i]==1) && (col[k] == 1)){
                        block[i]=0;
                        col[k]=0;
                        resultado++;
                    }
                    if((col[k]==1) && (row[j] == 1)){
                        col[k]=0;
                        row[j]=0;
                        resultado++;
                    }
                }
            }break;

            case 7:
            for(int j = 6 ; j < 9 ; j++){
                for(int k = 3 ; k < 6 ; k++){
                    if((block[i]==1) && (row[j] == 1)){
                        block[i]=0;
                        row[j]=0;
                        resultado++;
                    }
                    if((block[i]==1) && (col[k] == 1)){
                        block[i]=0;
                        col[k]=0;
                        resultado++;
                    }
                    if((col[k]==1) && (row[j] == 1)){
                        col[k]=0;
                        row[j]=0;
                        resultado++;
                    }
                }
            }break;

            case 8:
            for(int j = 6 ; j < 9 ; j++){
                for(int k = 6 ; k < 9 ; k++){
                    if((block[i]==1) && (row[j] == 1)){
                        block[i]=0;
                        row[j]=0;
                        resultado++;
                    }
                    if((block[i]==1) && (col[k] == 1)){
                        block[i]=0;
                        col[k]=0;
                        resultado++;
                    }
                    if((col[k]==1) && (row[j] == 1)){
                        col[k]=0;
                        row[j]=0;
                        resultado++;
                    }
                }
            }break;
        }
    }

    for(int i = 0 ; i < 9 ; i++){
        if(block[i]==1){
            block[i]=0;
            resultado++;
        }
    }

    for(int i = 0 ; i < 9 ; i++){
        if(row[i]==1){
            row[i]=0;
            resultado++;
        }
    }
    for(int i = 0 ; i < 9 ; i++){
        if(col[i]==1){
            col[i]=0;
            resultado++;
        }
    }

    cout << resultado;

    return 0;
}
