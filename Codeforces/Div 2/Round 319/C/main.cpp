#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> ans;

    int data[1010] = {0};
    bool prime[1010] = {false};
    for (int i = 2; i <= n; i++) {
        if (data[i] == 0) {
            ans.push_back(i);
            prime[i] = true;
            int multiple = 1;
            while (i * multiple <= n) {
                data[i * multiple]++;
                multiple++;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (data[i] == 1 && prime[i] == false) {
            ans.push_back(i);
        }
    }

    printf("%d\n", (int)ans.size());
    for (auto i = ans.begin(); i != ans.end(); i++) {
        if (i == ans.begin())
            printf("%d", *i);
        else
            printf(" %d", *i);
    }

    if (ans.size() != 0)
        printf("\n");

    return 0;
}
