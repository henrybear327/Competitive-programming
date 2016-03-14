#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    char input[100];
    fgets(input, 100, stdin);
    char *week = strstr(input, "week");

    int number;
    sscanf(input, "%d", &number);

    int ans;
    if (week == NULL) {
        // month
        if (number <= 29)
            ans = 12;
        else if (number == 30)
            ans = 11;
        else
            ans = 7;
    } else {
        // week

        if (number == 5 || number == 6)
            ans = 53;
        else
            ans = 52;
    }

    printf("%d\n", ans);

    return 0;
}
