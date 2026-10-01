#include <stdio.h>

int main()
{
    char a = 5;

    // 0101 & 0001 = 0001 (1)
    printf("\t%d\n", a & 1);

    // 0101 & 0010 = 0000 (0)
    printf("\t%d\n", a & 2);

    // 0101 | 0010 = 0111 (7)
    printf("\t%d\n", a | 2);

    return 0;
}
