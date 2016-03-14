#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> seq;

int main()
{
    int curr;
    while (scanf("%d", &curr) == 1) {
        seq.push_back(curr);
        sort(seq.begin(), seq.end());

        int size = seq.size();
        if (size & 1) { // odd
            printf("%d\n", seq[size / 2]);
        } else {
            printf("%d\n", (seq[size / 2 - 1] + seq[size / 2]) / 2);
        }
    }

    return 0;
}
