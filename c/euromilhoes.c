#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

int main()
{
   int nums[5], stars[2], generated_nums[5], generated_stars[2];
   bool check=false;
   read_values(nums, 1); 
   while(check==false)
        check=check_values(1, 5, nums);
        
   read_values(stars, 0);
   while(check==false)
        check=check_values(0, 2, stars);
        
   generate_values(generated_nums, 5, 50);
   generate_values(generated_stars, 2, 10);
   int equal_nums = compare_values(nums, generated_nums, 5);
   int equal_stars = compare_values(stars, generated_stars, 2);
   printf("\nnumbers equals: %d, stars equals: %d", equal_nums, equal_stars);
   return 0;
}

