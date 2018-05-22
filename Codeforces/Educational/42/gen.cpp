#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n = 6;
    printf("%d\n", n);

    for(int i = 0; i < n; i++) {
        printf("%d ", rand() % n + 1);
    }

    return 0;
}
