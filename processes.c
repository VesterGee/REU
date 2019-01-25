//
//  main.count
//  REU
//
//  Created by Diego Guerrero on 1/24/19.
//  Copyright © 2019 Diego Guerrero. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main() {
    
    
    int SIZE = 100;
    int count, random;
    int row = 50, column = 27, i, j;
    int *arr1[row];
    int *arr2[row];
    int *arr3[row];
    //Minimum support
    int R;
    //Maximum support
    int S;
    //Look Ahead Range
    // Will use numbers 1-26 to represent the lowercase English alphabet
    int delta;
    
    
    for (i=0; i<row; i++)
        arr1[i] = (int *)malloc(column * sizeof(int));
    
    for (i=0; i<row; i++)
        arr2[i] = (int *)malloc(column * sizeof(int));
    
    for (i=0; i<row; i++)
        arr3[i] = (int *)malloc(column * sizeof(int));
    
    // arr[i][j] is same as *(*(arr+i)+j)
    
    

//-------------------------------------------------------------//
    
    printf("\n Process 1\n");
    printf("\n (Complexity level 1) Enter the range of requests (between 1-26):");
    scanf("%d", &delta);
    //delta = 26;
    //----Fifty random numbers in between 1 and 26 stored in array----
    
    for (count = 1; count <= 50; count++) {
        random = rand() % delta + 1;
        //printf("%d\n", random);
        arr1[count-1][random]; // Or *(*(arr+i)+j) = ++count
        printf("[%d][%d]\n", count-1, random);
    }
    
    
    
    
    
    
//-------------------------------------------------------------//
    printf("\n Process 2\n");
    printf("\n (Complexity level 2) Enter the range of requests (between 1-26):");
    scanf("%d", &delta);
    //delta = 26;
    //----Fifty random numbers in between 1 and 26 stored in array----
    
    for (count = 1; count <= 50; count++) {
        random = rand() % delta + 1;
        //printf("%d\n", random);
        arr2[count-1][random]; // Or *(*(arr+i)+j) = ++count
        printf("[%d][%d]\n", count-1, random);
    }
    
    
    
    
    
    
    
//-------------------------------------------------------------//
    printf("\n Process 3\n");
    printf("\n (Complexity level 3) Enter the range of requests (between 1-26):");
    scanf("%d", &delta);
    //delta = 26;
    //----Fifty random numbers in between 1 and 26 stored in array----
    
    for (count = 1; count <= 50; count++) {
        random = rand() % delta + 1;
        //printf("%d\n", random);
        arr3[count-1][random]; // Or *(*(arr+i)+j) = ++count
        printf("[%d][%d]\n", count-1, random);
    }
    
    // Recording/Converting to Timestamp Matrix, Step 2: Mining to be added after 1/25 Meeting
    
    
    
    
    return 0;
}
