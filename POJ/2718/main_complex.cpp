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
        for (int i = 0; i < (1 << sz); i++) {
            if (__builtin_popcount(i) == (sz / 2)) {
                vector<int> left, right;
                for (int j = 0; j < sz; j++) {
                    if ((i >> j) & 1)
                        right.push_back(inp[j]);
                    else
                        left.push_back(inp[j]);
                }

                vector<int> r, l;
                if (sz / 2 == 1 && right[0] == 0) {
                    r.push_back(0);
                }
                do {
                    if (right[0] == 0)
                        continue;

                    int rnum = 0;
                    for (int j = 0; j < (int)right.size(); j++) {
                        rnum *= 10;
                        rnum += right[j];
                    }
                    r.push_back(rnum);
                } while (next_permutation(right.begin(), right.end()));

                if ((sz - sz / 2) == 1 && left[0] == 0) {
                    l.push_back(0);
                }
                do {
                    if (left[0] == 0)
                        continue;

                    int lnum = 0;
                    for (int j = 0; j < (int)left.size(); j++) {
                        lnum *= 10;
                        lnum += left[j];
                    }
                    l.push_back(lnum);
                } while (next_permutation(left.begin(), left.end()));

                for (int j = 0; j < (int)l.size(); j++) {
                    for (int k = 0; k < (int)r.size(); k++) {
                        res = min(res, abs(l[j] - r[k]));
                    }
                }
            }
        }
        printf("%d\n", res);
    }

    return 0;
}
