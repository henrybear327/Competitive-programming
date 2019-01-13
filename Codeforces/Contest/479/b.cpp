#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    char inp[n + 3];
    scanf("%s", inp);

    string ans;
    int best = 0, cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        cnt = 0;
        for (int j = 0; j < n - 1; j++) {
            if (inp[i] == inp[j] && inp[i + 1] == inp[j + 1]) {
                cnt++;
            }
        }

        if (cnt > best) {
            ans = string(inp).substr(i, 2);
            best = cnt;
        }
    }

    printf("%s\n", ans.c_str());

    return 0;
}
