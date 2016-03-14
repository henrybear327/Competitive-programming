#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    char inp[60000];
    fgets(inp, 60000, stdin);
    int ncase;
    sscanf(inp, "%d", &ncase);
    while (ncase--) {
        fgets(inp, 60000, stdin);

        int n = 0;
        vector<int> array;
        char *num = strtok(inp, " \n");
        while (num != NULL) {
            n++;
            array.push_back(atoi(num));
            num = strtok(NULL, " \n");
        }

        sort(array.begin(), array.end());

        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++)
            ans = min(ans, abs(array[i + 1] - array[i]));
        printf("%d\n", ans);
    }

    return 0;
}
