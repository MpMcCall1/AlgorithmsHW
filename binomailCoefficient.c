//
//  main.c
//  AlgoHw3
//
//  Created by Matthew McCall on 4/6/18.
//  Copyright © 2018 Matthew McCall. All rights reserved.
//
// I have to reference https://www.geeksforgeeks.org/memset-c-example/ because I looked at it then wrote my program to get an idea of how this worked.


#include<stdio.h>

int min(int a, int b);


int min(int a, int b)
{
    return (a<b)? a: b;
}

// Returns value of Binomial Coefficient C(n, k)
int bc(int x, int y)
{
    int C[x+1][y+1];
    int i, j;
    
    for (i = 0; i <= x; i++)
    {
        for (j = 0; j <= min(i, y); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    
    return C[x][y];
}

/* Driver program to test above function*/
int main()
{
    int a, b;
    printf("Enter number a: ");
    scanf("%d", &a);
    printf("Enter number b: ");
    scanf("%d", &b);
    printf("Value of (%d, %d) is %d ", a, b, bc(a, b));
    return 0;
}
