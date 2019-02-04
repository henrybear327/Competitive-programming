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

    int num[n];
    for (int i = 0; i < n; i++)
        num[i] = inp[i] - '0';

    int pre = 0;
    for (int i = 0; i < n - 1; i++) {
        pre += num[i];

        int idx = i + 1;
        bool error = false;
        while (idx < n) { // 20200
            int start = idx, end = idx + 1;
            int sum = num[start];
            while (end < n && sum + num[end] <= pre) {
                sum += num[end];
                end++;
            }

            if (pre == sum) {
                idx = end;
            } else {
                error = true;
                break;
            }
        }

        if (error == false) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}
