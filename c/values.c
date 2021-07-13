#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "check.h"

void read_values(int *nums_stars,char flag){
    char values[20], c=1;
    
    if(flag==1)
        printf( "Enter the numbers :");
    else if(flag==0)
        printf("Enter the stars: ");
    scanf("%s", values);
    
    char * token = strtok(values, ",");
    nums_stars[0]=atoi(token);
    
    while( token != NULL ) {
      //printf( " %s\n", token ); //printing each token
      token = strtok(NULL, ",");
      
      if(token != NULL){    
        nums_stars[c]=atoi(token);
        c++;}
    }
}

void generate_values(int* values, char size, int max){
    bool x = false;
    srand(time(NULL));
    for(int i=0; i<size; i++)
        values[i] = rand() % max + 1; 
        
    while(x==false)
        x=check_genarated_values(values, size, max);
        
    for(int i=0; i<size; i++){
        if(size==5 && i==0)
            printf("\ngenerated nums: %d, ", values[i]);
        else if(size==2 && i==0)
            printf("\ngenerated stars: %d, ", values[i]);
        else
            printf("%d, ", values[i]);
    }
}