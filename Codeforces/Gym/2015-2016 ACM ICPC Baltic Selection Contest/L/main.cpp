#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n + 10];
    scanf("%s", inp);

    int happy = 0, sad = 0;
    for (int i = 0; i < n; i++) {
        if (inp[i] == ':') {
            if (i - 1 >= 0) {
                if (inp[i - 1] == '(')
                    happy++;
                else if (inp[i - 1] == ')')
                    sad++;
            }

            if (i + 1 < n) {
                if (inp[i + 1] == ')')
                    happy++;
                else if (inp[i + 1] == '(')
                    sad++;
            }
        }
    }

    if (happy == sad)
        printf("BORED\n");
    else {
        if (happy > sad)
            printf("HAPPY\n");
        else
            printf("SAD\n");
    }

    return 0;
}
