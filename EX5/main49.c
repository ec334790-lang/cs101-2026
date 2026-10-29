#include <stdio.h>

void toH(int n, char f_r, char t_r, char a_r) {
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", f_r, t_r);
        return;
    } 
    toH(n - 1, f_r, a_r, t_r);
    printf("\nMove disk %d from rod %c to rod %c", n, f_r, t_r);
    toH(n - 1, a_r, t_r, f_r);
}

int main() {
    int n = 3;
    toH(n, 'A', 'B', 'C');
    return 0;
}
