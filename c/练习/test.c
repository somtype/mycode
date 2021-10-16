#include "stdio.h"
#include "stdlib.h"
int main()
{
    FILE *A, *B, *C;
    char a, b;
    A = fopen("A.dat", "r");
    B = fopen("B.dat", "r");
    C = fopen("C.dat", "w");
    return 0;
}