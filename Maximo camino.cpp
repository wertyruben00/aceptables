#include<stdio.h>
int maxim(int a , int b){
    if(a>b) return a;

    return b;
}
int main(){
    int m, n;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int i = 0 ; i < m ; i ++)
        for(int j = 0 ; j < n ; j ++)
            scanf("%d",&arr[i][j]);

    int i = m , j = n ;
     for(int k = n - 1 ; k > 0; k --){
        i = m -1;
        j = k;
        while(j <= n - 1 ){
            if(i == m - 1 && j == n - 1){
                i--;
                j++;
            }else if(i == m - 1 && j < n - 1){
                arr[i][j] = arr[i][j]+arr[i][j + 1];
                i--;
                j++;
            }else if(j == n - 1 && i < m - 1){
                arr[i][j] = arr[i][j]+arr[i + 1][j];
                i--;
                j++;
            }else{
                arr[i][j] = arr[i][j] + maxim(arr[i + 1][j],arr[i][j + 1]);
                i--;
                j++;
            }
        }
    }
    for(int k = m - 1 ; k >= 0  ; k--){
        i = k;
        j = 0;
        while(i >= 0 && j < n){
            if(i == m - 1){
                arr[i][j] = arr[i][j]+arr[i][j + 1];
                i--;
                j++;
            }else if(j == n - 1){
                arr[i][j] = arr[i][j]+arr[i + 1][j];
                i--;
                j++;
            }else{
                arr[i][j] = arr[i][j] + maxim(arr[i + 1][j],arr[i][j + 1]);
                i--;
                j++;
            }
        }
    }
    for(int i = 0 ; i < m ; i++){
        for(int  j = 0 ; j < n ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
