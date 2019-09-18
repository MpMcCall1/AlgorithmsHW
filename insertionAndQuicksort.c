//
//  main.c
//  AlgoHw2
//
//  Created by Matthew McCall on 2/15/18.
//  Copyright © 2018 Matthew McCall. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
// From https://www.programmingsimplified.com/c/source-code/c-program-insertion-sort
int insertionSort(int array[])
{
    int c, d, t;
    
   // printf("Enter number of elements\n");
   // scanf("%d", &n);
    
   // printf("Enter %d integers\n", n);
    
   // for (c = 0; c < n; c++) {
    //    scanf("%d", &array[c]);
   // }
    time_t start, end;
    double cpu_time_used;
    start = clock();
    for (c = 1 ; c <= 100000 - 1; c++) {
        d = c;
        
        while ( d > 0 && array[d-1] > array[d]) {
            t          = array[d];
            array[d]   = array[d-1];
            array[d-1] = t;
            
            d--;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f \n", cpu_time_used);
    
    return 0;
}
//from https://beginnersbook.com/2015/02/quicksort-program-in-c/
void quicksort(int number[100000],int first,int last){
    int i, j, pivot, temp;
    
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        
        while(i<j){
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
        
    }
}

int main(){
    time_t start1, end1;
    double timea;
    int i;
    srand(0);
    int my_array[100000];
    for (i=0;i<100000;i++){
        my_array[i] = rand();
    }
    int s = sizeof(my_array)/sizeof(my_array[0]);
    insertionSort(my_array);
    start1 = clock();
    quicksort(my_array, 0, s-1);
    end1 = clock();
    timea = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    printf("%f \n", timea);
    return 0;
}
