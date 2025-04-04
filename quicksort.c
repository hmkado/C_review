#include <stdio.h>

void swap(int* n, int* m){
    int temp = *n;
    *n = *m;
    *m = temp;
}

int partition(int arr[], int n, int m){
    swap(&arr[(n+m)/2],&arr[m]);
    int pivot = arr[m];
    int p = (n - 1);
    for (int i = n;i < m;i++){
        if(arr[i] <= pivot){
            p++;
            swap(&arr[i],&arr[p]);
        }
    }
    swap(&arr[m],&arr[p+1]);
    return p+1;
}

void quicksort(int arr[], int n, int m){
    int p = 0;
    if (n < m){
        p = partition(arr,n,m);
        quicksort(arr,n,p-1);
        quicksort(arr,p+1,m);
    }
}

void printarr(int arr[],int size){
    for(int i = 0;i < size;i++){
        printf("%2d",arr[i]);
    }
    printf("\n");
}

void main(){
    int arr[9] = {9,8,7,6,5,4,3,2,1};
    printarr(arr,9);
    quicksort(arr,0,9-1);
    printarr(arr,9);
}