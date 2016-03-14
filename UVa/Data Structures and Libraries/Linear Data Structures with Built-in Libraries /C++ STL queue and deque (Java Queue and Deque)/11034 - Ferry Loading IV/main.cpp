#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int max_len, query;
        scanf("%d %d", &max_len, &query);
        max_len *= 100;
        queue<int> left;
        queue<int> right;
        for (int i = 0; i < query; i++) {
            int len;
            char pos[10];
            scanf("%d %s", &len, pos);

            if (pos[0] == 'l')
                left.push(len);
            else
                right.push(len);
        }

        int cnt = 0;
        bool is_left = true; // init ferry pos.
        while (!left.empty() || !right.empty()) {
            cnt++;
            if (is_left && !left.empty()) {
                int tmp = 0;
                while (!left.empty() && tmp + left.front() <= max_len) {
                    tmp += left.front();
                    left.pop();
                }
                is_left = !is_left;
            } else if (!is_left && !right.empty()) {
                int tmp = 0;
                while (!right.empty() && tmp + right.front() <= max_len) {
                    tmp += right.front();
                    right.pop();
                }
                is_left = !is_left;
            } else {
                is_left = !is_left;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
