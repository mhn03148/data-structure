#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortFunction();
void printarrayFunction();

int main(){

    srand(time(NULL));
    int vector_array[10];
    for(int i =0; i<10; i++)
    {
        vector_array[i] = rand()%(-19)-10;
    }
    for (int j=0; j<10; j++){
        printf("%d ",vector_array[j]);
    }
    printf("\n");
    sortFunction(vector_array,0,9);
    printarrayFunction(vector_array,10);
    return 0;
}

void sortFunction(int *vector_array, int start, int end){
    if(start>=end){
        return;
    }
    int pivot = start;
    int i = pivot+1;
    int j = end;
    int temp;

    while(i<=j){
        while(i<end && vector_array[i]<=vector_array[pivot]){
            ++i;
        }
        while(j>start && vector_array[j] >= vector_array[pivot]){
            --j;
        }
        if (i>=j){
            break;
        }

        temp = vector_array[i];
        vector_array[i] = vector_array[j];
        vector_array[j] = temp;
    }

    temp = vector_array[j];
    vector_array[j] = vector_array[pivot];
    vector_array[pivot] = temp;

    sortFunction(vector_array, start, j-1);
    sortFunction(vector_array, j+1, end);
}

void printarrayFunction(int arr[],int agrc){
    for(int i=0; i<agrc; i++){
        printf("%d ",arr[i]);
    }
}