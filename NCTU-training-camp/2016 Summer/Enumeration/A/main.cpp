#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%d\n", 4 * (int)(sqrt(a*b/c) + sqrt(b*c/a) + sqrt(a*c/b)));
    
    return 0;
}
