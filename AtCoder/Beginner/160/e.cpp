#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void mySort(vector<int> &inp)
{
    sort(inp.begin(), inp.end());
    reverse(inp.begin(), inp.end());
}

int main()
{
    int x, y, a, b, c;
    scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);

    vector<int> red, green, cand;
    for (int i = 0; i < a; i++) {
        int num;
        scanf("%d", &num);
        red.push_back(num);
    }
    for (int i = 0; i < b; i++) {
        int num;
        scanf("%d", &num);
        green.push_back(num);
    }
    for (int i = 0; i < c; i++) {
        int num;
        scanf("%d", &num);
        cand.push_back(num);
    }

    mySort(red);
    mySort(green);
    mySort(cand);

    vector<int> orig;
    for (int i = 0; i < x; i++)
        orig.push_back(red[i]);
    for (int i = 0; i < y; i++)
        orig.push_back(green[i]);
    mySort(orig);

    int j = 0;
    for (int i = x + y - 1; i >= 0 && j < c; i--) {
        if (cand[j] > orig[i]) {
            orig[i] = cand[j];
            j++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < x + y; i++)
        ans += orig[i];
    printf("%lld\n", ans);

    return 0;
}
