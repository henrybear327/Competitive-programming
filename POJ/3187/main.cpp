#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, target;
    scanf("%d %d", &n, &target);

    vector<int> seq;
    for (int i = 0; i < n; i++) {
        seq.push_back(i + 1);
    }

    do {
        int prev[n];
        for (int i = 0; i < n; i++)
            prev[i] = seq[i];
        int tmp[n];
        tmp[0] = prev[0]; // special case, n = 1
        for (int i = n; i > 1; i--) {
            for (int j = 0; j < i - 1; j++) {
                tmp[j] = prev[j] + prev[j + 1];
            }

            for (int j = 0; j < i - 1; j++)
                prev[j] = tmp[j];
        }

        if (tmp[0] == target) {
            for (int i = 0; i < n; i++)
                printf("%d%c", seq[i], i == n - 1 ? '\n' : ' ');

            break;
        }
    } while (next_permutation(seq.begin(), seq.end()));

    return 0;
}
