#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    const char *teams[] = {"RealMadrid", "Malaga", "Barcelona", "Eibar"};

    int data[4];
    for (int i = 0; i < 4; i++) {
        char inp[10000];
        int score;
        scanf("%s %d", inp, &score);

        for (int j = 0; j < 4; j++)
            if (strcmp(inp, teams[j]) == 0) {
                data[j] = score;
                break;
            }
    }

    bool overturn = false;
    if (data[1] > data[0] && data[2] > data[3])
        overturn = true;

    printf("%s\n", overturn == false ? "RealMadrid" : "Barcelona");
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
