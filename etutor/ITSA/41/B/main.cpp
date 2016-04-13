#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> line;
        for (int i = 1; i <= n; i++)
            line.push_back(i);

        vector<int>::iterator it = line.begin();
        int cnt = 0;
        while (line.size() != 1) {
            cnt++;
            if (cnt % k == 0) {
                line.erase(it);
                it = it == line.end() ? line.begin() : it;
                continue;
            }
            it = (it == (line.end() - 1) ? line.begin() : it + 1);
        }

        printf("%d\n", *it);
    }

    return 0;
}
