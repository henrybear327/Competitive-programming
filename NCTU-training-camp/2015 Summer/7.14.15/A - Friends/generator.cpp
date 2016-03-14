#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <ctime>

int main()
{
    srand(time(NULL));
    printf("10\n");
    for (int i = 0; i < 10; i++) {
    	int c = rand() % 100 + 2;
    	int d = rand() % 100 + 2;
        printf("%d %d\n", c, d);
        for (int j = 0; j < d; j++) {
            int a = 1, b = 1;
            while (a == b) {
                a = rand() % c + 1;
                b = rand() % c + 1;
            }
            printf("%d %d\n", a, b);
        }
    }

    return 0;
}
