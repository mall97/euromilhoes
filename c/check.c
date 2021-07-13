#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool check_genarated_values(int *values, char size, int max){
    srand(time(NULL));
    for(int i=0; i<size; i++){
        for(int a=0; a<size; a++){
            if(values[i]==values[a] && i!=a){
                values[i] = rand() % max + 1;
                return false;
            }
        }
    }
    return true;
}

bool check_values(int flag,int size, int *values){
    for(int i=0; i<size; i++){
        for(int a=0; a<size; a++){
            if(values[i]==values[a] && i!=a){
                //printf("same number");
                printf("equal value, change the value %d: ", values[i]);
                scanf("%d", &values[i]);
                return false;
            }
            
            if((values[i]>51 ||values[i]<1) && flag==1 || (values[i]>11 ||values[i]<1) && flag==0){
                printf("value %d is invalid, change: ", values[i]);
                scanf("%d", &values[i]);
                return false;
            }
        }
    }
    return true;
}

int compare_values(int *values, int *generated_values, int size){
    int cnt = 0;
    for(int i=0; i<size; i++){
        for(int a=0; a<size; a++){
            if(values[i]==generated_values[a]){
                cnt++;
            }
        }
    }
    return cnt;
}