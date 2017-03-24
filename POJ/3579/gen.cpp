#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        printf("%d\n", 4);
        for(int j = 0; j < 4; j++) {
            printf("%d ", rand() % 10);
        }
        printf("\n");
    }
    return 0;
}
