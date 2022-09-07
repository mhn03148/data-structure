#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortFunction();

int main(){
    srand(time(NULL));
    int vector_array[10];
    for(int i =0; i<10; i++)
    {
        vector_array[i] = rand()%(-19)-10;
    }
    for (int j=0; j<10; j++){
        printf("%d \n",vector_array[j]);
    }
    return 0;
}