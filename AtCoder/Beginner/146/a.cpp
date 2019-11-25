#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    const char *weekday[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    char inp[10];
    scanf("%s", inp);

    for (int i = 0; i < 7; i++)
        if (strcmp(inp, weekday[i]) == 0) {
            printf("%d\n", 7 - i);
        }

    return 0;
}
