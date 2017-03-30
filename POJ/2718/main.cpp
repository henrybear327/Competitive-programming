#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int ncase;
    char str[100];
    fgets(str, 100, stdin);
    sscanf(str, "%d", &ncase);

    while (ncase--) {
        vector<int> inp;
        char str[100];
        fgets(str, 100, stdin);

        char *num = strtok(str, " ");
        while (num != NULL) {
            inp.push_back(atoi(num));
            num = strtok(NULL, " ");
        }

        int sz = inp.size();
        int res = INT_MAX;

        do {
            bool error = false;
            int r = 0, l = 0;
            for (int i = 0; i < sz / 2; i++) {
                if (sz > 1 && i == 0 && inp[i] == 0)
                    error = true;
                r *= 10;
                r += inp[i];
            }

            for (int i = sz / 2; i < sz; i++) {
                if (sz - sz / 2 > 1 && i == sz / 2 && inp[i] == 0)
                    error = true;
                l *= 10;
                l += inp[i];
            }

            if (error == false) {
                res = min(res, abs(r - l));
            }
        } while (next_permutation(inp.begin(), inp.end()));
        printf("%d\n", res);
    }

    return 0;
}
