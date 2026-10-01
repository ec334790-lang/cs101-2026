#include <stdio.h>

int main() {
    char a = 5;
    printf("\t%d\n", a ^ 1)
    // 0000 0101 ^ 0000 0001 = 0000 0100 XOR
    printf("\t%d\n", ~a);
    // ~0000 0101 = 1111 1010 (~NOT)
    printf("\t%d\n", a >> 1);
    // 0000 0101 >> 1 = 0000 0010  
    printf("\t%d\n", a << 1);
    // 0000 0101 << 1 = 0000 1010
    return 0;
}
