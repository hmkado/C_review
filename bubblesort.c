#include <stdio.h>

void main(){
    int arr[10] = {3,2,3,6,7,3,8,3,5,9};
    int temp = 0;
    for (int i = 0;i<10;i++){
        printf("%2d",arr[i]);
    }
    printf("\n");
    for (int i=0;i<10-1;i++){
        for(int j=0;j<10-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0;i<10;i++){
        printf("%2d",arr[i]);
    }
    printf("\n");
}