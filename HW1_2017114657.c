#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void sortFunction();
void printarrayFunction();
void PnormFunction();
void findmedianFunction();

int main(){

    srand(time(NULL));
    int vector_array[10];
    int num;
    for(int i =0; i<10; i++)
    {
        vector_array[i] = rand()%(-19)-10;
    }
    printf("1-1) The vector with 10 random integers is :\n");
    printarrayFunction(vector_array,10);
    sortFunction(vector_array,0,9);

    printf("1-2) The vector after passing sort function is :\n");
    printarrayFunction(vector_array,10);

    printf("1-3) Calculation of p-norm : \n");
    scanf("%d", &num);
    PnormFunction(vector_array,num);

    printf("1-3) Calculation of median : \n");
    findmedianFunction(vector_array);
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
}// i used quicksort

void printarrayFunction(int arr[],int agrc){
    printf("v = [ ");
    for(int i=0; i<agrc; i++){
        printf("%d ",arr[i]);
    }
    printf("]\n\n");
}// I made print function so i can easily print my array. 

void PnormFunction(int arr[], int argc){
    int sum = 0;
    float result = 0.0;
    for(int i =0; i<10; i++){
        sum += pow(fabs(arr[i]),argc);
    }
    result = pow(sum,(1 / (float)argc));
    printf("%.4f\n",result);
}
//Adds the absolute values of all array elements to the power of n
//And square the value n/1

void findmedianFunction(int arr[]){
    float result;
    result = ((double)arr[4] + (double)arr[5])/2;
    printf("%f\n", result);
}// finds 5th element and 6th element. and add them up and divide by 2.
//in this case, the integer was cast to (double) and made a real number.