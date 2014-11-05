#include <stdio.h>
#include <stdlib.h>

#define DEBUG

//prototype
unsigned int factorial(unsigned int x){
    /*if(x < 0)
        printf("Out of range x<0 ");
        return EXIT_FAILURE;*/
    if(x == 0)
        return 1;
    else
        return (x*factorial(x-1));
        
}

int main(){
    unsigned int n; /* set_size */
    unsigned int k; /* combination_space */
    
    /*Getting user input for combination space and set space*/
    printf("What is the set size of the set:");
    scanf("%d", &n);
    
    printf("What is the size of combination space:");
    scanf("%d", &k);
    
    #ifdef DEBUG
    printf("set size : %d , comb_size: %d\n", n, k);
    #endif
    
    //Now we perform the factorial of n, k and n-k
    unsigned int n_fact, k_fact, n_k_fact;
    
    n_fact = factorial(n);
    k_fact = factorial(k);
    n_k_fact = factorial(n - k);
    
    printf("n_factorial :  %d\n", n_fact);
    printf("k_factorial :  %d\n", k_fact);
    printf("n_k_factorial :  %d\n", n_k_fact);
    
    float num_comb;
    //calculating the number of combinations
    num_comb = n_fact*1.00/( k_fact * n_k_fact );
    //rounding off
    num_comb = num_comb;
    
    printf("The number of possible combinations are : %f\n", num_comb);
    return 0;
}