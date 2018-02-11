#include <stdio.h>
#include <stdlib.h>
#include "malloc.c"

int main()
{
    printf("Testing the code...\n");
    printf("Trying to get the lower multiple of 8 above12345 (should be 12352) : ");
    printf("%zu\n", word_align(12345));

    printf("Trying to get the multiple of 8 above 7 (should be 8) : ");
    printf("%zu\n", word_align(7));

    printf("Trying to get the multiple of 8 above 9 (should be 16) : ");
    printf("%zu\n", word_align(9));

    

    return 0;
}
