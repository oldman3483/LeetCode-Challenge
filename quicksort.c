#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 


void swap(int *, int *);

void quicksort(int[], int, int);

int partition(int[], int, int); 

int main(void) { 
    srand(time(NULL)); 
    
    int number[MAX] = {0}; 

    printf("BEFORE: "); 
    int i;
    for(i = 0; i < MAX; i++) { 
        number[i] = rand() % 100; 
        printf("%d ", number[i]); 
    } 
    quicksort(number, 0, MAX-1); 

    printf("\nAFTER: "); 
    for(i = 0; i < MAX; i++) 
        printf("%d ", number[i]); 
    
    printf("\n"); 

    return 0; 
} 



void swap(int *a, int *b)
{
    int *tmp;
    *tmp=*a;
    *a = *b;
    *b = *tmp;
}

int partition(int number[], int left, int right) { 
    int i = left - 1; 
    int j;

    for(j = left; j < right; j++) 
    {
        if(number[j] <= number[right]) { 
            i++; 
            SWAP(number[i], number[j]); 
        } 
    } 

    SWAP(number[i+1], number[right]); 
    return i+1; 
} 

void quicksort(int number[], int left, int right) { 
    if(left < right) { 
        int q = partition(number, left, right); 
        quicksort(number, left, q-1); 
        quicksort(number, q+1, right); 
    } 
} 