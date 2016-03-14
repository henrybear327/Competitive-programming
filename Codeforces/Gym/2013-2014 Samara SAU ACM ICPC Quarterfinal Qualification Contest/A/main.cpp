#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases;
    while(scanf("%d", &cases) != EOF) {
        map<int, int> imax, imid, imin;
        vector<int> inp[cases];
        for(int i = 0; i < cases; i++) {
            int tmp;
            for(int j = 0; j < 3; j++) {
                scanf("%d", &tmp);
                inp[i].push_back(tmp);
            }

            sort(inp[i].begin(), inp[i].end());

            imin[inp[i][0]]++;
            imid[inp[i][1]]++;
            imax[inp[i][2]]++;
        }

        vector<int> ans;
        for(int i = 0; i < cases; i++) {
            imin[inp[i][0]]--;
            imid[inp[i][1]]--;
            imax[inp[i][2]]--;

            auto it = imid.rbegin();
            auto it2 = imin.rbegin();
            if(inp[i][2] > it-> first && inp[i][1] > it2 -> first) {
                ans.push_back(i + 1);
            }

            imin[inp[i][0]]++;
            imid[inp[i][1]]++;
            imax[inp[i][2]]++;
        }

        printf("%d\n", ans.size());
        for(auto i = ans.begin(); i != ans.end(); i++) {
            if(i == ans.begin())
                printf("%d", *i);
            else
                printf(" %d", *i);
        }
        printf("\n");

    }
    return 0;
}
