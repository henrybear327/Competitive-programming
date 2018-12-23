#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Data {
    int op;
    int i;
    int x;
};

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        // (ai + x) % (ai + x - i) = i
        // if ai + x - i > floor((ai + x)) / 2)
        // => ai + x - i >= (ai + x + 1) / 2 // by adding denominator - 1 to the
        // numerator, we can take the floor away
        // => ai + x - 2i >= 1
        // => x >= 1 + 2i - ai
        // now we have the min n that satisfy the condition
        sum = max(sum, 1 + 2 * i - inp[i]);
    }

    vector<Data> ans;
    ans.push_back({1, n, sum});
    for (int i = 0; i < n; i++) {
        ans.push_back({2, i + 1, inp[i] + sum - i});
    }

    printf("%d\n", (int)ans.size());
    for (auto i : ans)
        printf("%d %d %d\n", i.op, i.i, i.x);

    return 0;
}
