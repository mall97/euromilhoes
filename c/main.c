#include <stdio.h>
#include <stdbool.h>

#include "values.h"
#include "check.h"

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