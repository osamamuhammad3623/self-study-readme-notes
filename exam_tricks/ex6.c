#include <stdio.h>

int main()
{
    int a[]={0,1,2,3,4,5,6,7,8,9};
    /* a and &a are NOT the same, they have different types, 
        but hold the same memory address 
    */
    /*
    &a is of type int (*)[10] (a pointer to an array)
    a is of type int [10] (pointer to a single element)

    The pointer will be offset by the size of the type that the address contains.
    a+1 offsets by the size of int, i.e. to the second element in the array.
    &a+1 offsets completely past the whole array.
    */
    printf("a = %u , &a = %u\n",a,&a); 
    printf("a+1 = %u , &a+1 = %u\n",a+1,&a+1);
}