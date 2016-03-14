#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    char input[1000000];
    fgets(input, 1000000, stdin);
    while(cases--) {
        fgets(input, 1000000, stdin);
        char *num = strtok(input, " \n");
        vector< pair<int, int> > inp;
        int idx = 1;
        while(num != NULL) {
            int tmp = atoi(num);
            inp.push_back(make_pair(tmp, idx));
            idx++;
            num = strtok(NULL, " \n");
        }

        sort(inp.begin(), inp.end());

        int curr = inp[inp.size() - 1].first;
        int ans = inp[inp.size() - 1].second;
        for(int i = inp.size() - 1; i >= 0; i--) {
            if(inp[i].first < curr) {
                curr = inp[i].first;
                ans += inp[i].second;
            }
        }

        printf("%d\n", ans);

    }



    return 0;
}
