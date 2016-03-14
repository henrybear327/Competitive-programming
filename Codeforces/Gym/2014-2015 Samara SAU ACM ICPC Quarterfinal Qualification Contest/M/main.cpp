#include <cstdio>
#include <vector>

using namespace std;

// 3 3
// 3 2 1 6 5 4

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    vector<int> ans;
    for (int i = 1; i <= a; i++) {
        for (int j = i * b; j > (i - 1) * b; j--) {
            ans.push_back(j);
        }
    }

    printf("%d\n", a * b);
    for (int i = 0; i < (int)ans.size(); i++)
        if (i == (int)ans.size() - 1)
            printf("%d\n", ans[i]);
        else
            printf("%d ", ans[i]);

    return 0;
}
