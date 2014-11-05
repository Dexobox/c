#include <stdio.h>


void print_array(int* x,int y ){
    int l;
    printf("\nThe array : {");
    for(l=0; l<y;l++){
        printf(" %d", *(x+l));
    }
    printf(" }\n");
}

void swap(int * x, int *y){
    if(x != y)
    {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}


int main (){
    // the array is generated for the input sorting
    int a[] = {64, 25, 12, 22, 11};
    int *min, *current;
    //   min = current = &a[0];
    int i, j;
    //selection sort is an inplace algorith so it will require swap function and loops for iterating over the array
    for(j = 0; j < 4; j++)
    {
        min = current = &a[j];
        for( i = j; i < 5; i++){
        //printf("\n%d", i);
            if(*min > *(current+i)){
                //printf("\n%d > %d ?",*min, *(current+i));
                min = (current+i);
            }
        }
        swap(min, &a[j]);
    }
    print_array(&a[0], 5);
    return 0;
}