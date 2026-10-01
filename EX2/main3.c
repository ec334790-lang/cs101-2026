#include <stdio.h>

int main()
{
    int i =1;
    i= i++<<3+2<<--i;
    printf(" i= %d\n",i);
    return 0;
}
