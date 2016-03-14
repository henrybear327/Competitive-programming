#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    const int pf[4] = {6, 28, 496, 8128};
    while (scanf("%d", &n) == 1) {
        vector<int> ans;
        for (int i = 0; i < 4; i++)
            if (n >= pf[i])
                ans.push_back(pf[i]);
        for (int i = 0; i < (int)ans.size(); i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
