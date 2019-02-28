#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

vector<int> squareList;

bool isSquare(int num)
{
    return binary_search(squareList.begin(), squareList.end(), num);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= 31623; i++)
        squareList.push_back(i * i);

    vector<int> square, notSquare;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (isSquare(num))
            square.push_back(num);
        else
            notSquare.push_back(num);
    }

    ll ans = 0;
    sort(square.begin(), square.end());
    reverse(square.begin(), square.end());
    if (square.size() == notSquare.size())
        ans = 0;
    else if (square.size() > notSquare.size()) {
        for (int i = 0; i < (int)square.size() - n / 2; i++)
            if (square[i] == 0)
                ans += 2;
            else
                ans += 1;
    } else {
        int diff[notSquare.size()];
        for (int i = 0; i < (int)notSquare.size(); i++) {
            int j = notSquare[i];
            auto ub = upper_bound(squareList.begin(), squareList.end(), j);
            auto lb = ub;
            lb--;
            diff[i] = min(abs(*ub - j), abs(*lb - j));
        }

        sort(diff, diff + notSquare.size());

        for (int i = 0; i < (int)notSquare.size() - n / 2; i++)
            ans += diff[i];
    }
    printf("%lld\n", ans);

    return 0;
}
