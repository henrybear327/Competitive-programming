#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    const char *arr[] = {"Sunny", "Cloudy", "Rainy"};
    char inp[100];
    scanf("%s", inp);

    for (int i = 0; i < 3; i++)
        if (strcmp(inp, arr[i]) == 0)
            printf("%s\n", arr[(i + 1) % 3]);

    return 0;
}
