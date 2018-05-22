#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int check(int sq, int inp)
{
    // convert inp to sq
    string de_sq = to_string(sq), de_inp = to_string(inp);

    int i = 0;
    for (int j = 0; j < (int)de_inp.size(); j++) {
        if (de_sq[i] == de_inp[j]) {
            i++;
        }
    }

    if (i != (int)de_sq.size()) // can't do it
        return INT_MAX;

    // leading zero? 10064->64
    return (int)de_inp.size() - (int)de_sq.size();
}

int main()
{
    // sqrt(2*10^9) = 44722
    int inp;
    scanf("%d", &inp);
    int mn = INT_MAX;
    for (int i = 1; i < 44722; i++) {
        mn = min(mn, check(i * i, inp));
    }
    printf("%d\n", mn == INT_MAX ? -1 : mn);

    return 0;
}
