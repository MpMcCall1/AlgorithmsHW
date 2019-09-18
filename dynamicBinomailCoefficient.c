//
//  main.c
//  AlgoHwP2
//
//  Created by Matthew McCall on 4/6/18.
//  Copyright © 2018 Matthew McCall. All rights reserved.
//

// C program for space optimized Dynamic Programming
// Solution of Binomial Coefficient
// I have to reference https://www.geeksforgeeks.org/memset-c-example/ because I looked at it then wrote my program to get an idea of how this worked.

#include<stdio.h>

int mem[2000][2000];

int bc(int x, int y)
{
    if (y==0 || y==x)
        return 1;
    
    if (mem[y][x] != 0)
        return  mem[y][x];
    
    mem[y][x] = bc(x-1, x-1) + bc(y-1, x);
    return mem[y][x];
}

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
