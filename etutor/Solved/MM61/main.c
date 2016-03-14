#include <stdio.h>
#include <stdlib.h>

/*
assume 
A = total number of these animals
B =  the number of legs of these animals
C =  and the number of tails of these animals
列出方程式，可以發現
z = crabs個數 = A - C
y = chicken個數 = (B - 8 * z - 2 * C) / 2
x = rabbit個數 = C - y
所以只要ABC都>=零，且(B - 8 * z - 2 * C) / 2可以整除，且xyz也都>=零，就可了!
*/

int main()
{
    int A, B, C;
    while (scanf("%d %d %d", &A, &B, &C) == 3) {
        if (A < 0 || B < 0 || C < 0) {
            printf("No solution\n");
            continue;
        }

        int x, y, z;
        z = A - C;
        if ((B - 8 * z - 2 * C) % 2 != 0)
            printf("No solution\n");
        else {
            y = (B - 8 * z - 2 * C) / 2;
            x = C - y;
            if (x < 0 || y < 0 || z < 0)
                printf("No solution\n");
            else
                printf("%d %d %d\n", x, y, z);
        }
    }

    return 0;
}

