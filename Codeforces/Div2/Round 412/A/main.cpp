#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
int main()
{
    int n;
    scanf("%d", &n);

    int state = 0; // unrated
    vector<ii> inp;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        inp.push_back(ii(a, b));

        if (a != b)
            state = 1; // rated
    }

    bool sorted = true;
    for (int i = 1; i < n; i++) {
        if (inp[i] > inp[i - 1])
            sorted = false;
    }

    if (state == 0 and sorted)
        state = 2;

    if (state == 0)
        printf("unrated\n");
    else if (state == 1)
        printf("rated\n");
    else
        printf("maybe\n");

    return 0;
}
