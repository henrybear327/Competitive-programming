#include <bits/stdc++.h>

using namespace std;

int main()
{
    char inp[1111];
    scanf("%s", inp);

    int len = strlen(inp);

    int odd = 0, even = 0;
    for(int i = 0; i < len; i++) {
        if(i % 2 == 0)
            odd += inp[i] - '0';
        else
            even += inp[i] - '0';
    }

    printf("%d\n", abs(odd - even));


    return 0;
}
