#include <bits/stdc++.h>

// python3 interactive_runner.py python local_testing_tool.py 2 -- ./a.out

using namespace std;

void solve(int n)
{
    int inp[n] = {0};
    int idx = 0;
    int cnt = 0;
    while (true) {
        // per 10 queries as a unit
        int offset = 5;
        if (idx != 0)
            offset--;

        int lim = idx + offset;
        for (int i = idx; i < lim; i++, idx++) {
            if (i >= n / 2)
                break;

            // idx n - i - 1
            // ask head
            printf("%d\n", i + 1);
            fflush(stdout);
            scanf("%d", &inp[i]);

            // ask tail
            printf("%d\n", n - i);
            fflush(stdout);
            scanf("%d", &inp[n - i - 1]);

            cnt += 2;
        }

        if (cnt == n) {
            // print ans
            for (int i = 0; i < n; i++)
                printf("%d", inp[i]);
            printf("\n");
            fflush(stdout);

            char ans[10];
            scanf("%s", ans);

            if (ans[0] == 'N')
                exit(0);

            return;
        } else if (cnt > n) {
            assert(1 == -1);
        }

        // gen 4 combination
        int candidates[4][n];
        // orig
        for (int i = 0; i < n; i++)
            candidates[0][i] = inp[i];

        // flip
        for (int i = 0; i < n; i++)
            candidates[1][i] = !inp[i];

        // reverse
        for (int i = 0; i < n; i++)
            candidates[2][i] = inp[n - i - 1];

        // both
        for (int i = 0; i < n; i++)
            candidates[3][i] = !candidates[2][i];

        // determine what change has happened
        // ask 2 more
        // ask pos 0
        int valAt0;
        printf("1\n");
        fflush(stdout);
        scanf("%d", &valAt0);

        vector<int> possibleMove;
        for (int i = 0; i < 4; i++) {
            if (candidates[i][0] == valAt0)
                possibleMove.push_back(i);
        }

        /*
        orig    flip    reverse     both
        0 0     1 1     0 0         1 1
        0 1     1 0     1 0         0 1
        1 0     0 1     0 1         1 0
        1 1     0 0     0 0         1 1
        */

        // get first diff
        int transform = possibleMove[0];
        bool hasDoneShit = false;
        for (int i = 0; i < n; i++) {
            if (candidates[possibleMove[0]][i] != candidates[possibleMove[1]][i]) {
                // ask i
                printf("%d\n", i + 1);
                fflush(stdout);

                int val;
                scanf("%d", &val);

                if (candidates[possibleMove[0]][i] == val)
                    transform = possibleMove[0];
                else
                    transform = possibleMove[1];

                hasDoneShit = true;
                break;
            } else if (candidates[possibleMove[0]][n - i - 1] !=
                       candidates[possibleMove[1]][n - i - 1]) {
                // ask i
                printf("%d\n", n - i);
                fflush(stdout);

                int val;
                scanf("%d", &val);

                if (candidates[possibleMove[0]][n - i - 1] == val)
                    transform = possibleMove[0];
                else
                    transform = possibleMove[1];

                hasDoneShit = true;
                break;
            }
        }

        // Andy 太神了
        if (hasDoneShit == false) {
            printf("%d\n", 1);
            fflush(stdout);
            int val;
            scanf("%d", &val);
        }

        // op on array
        for (int i = 0; i < n; i++) {
            inp[i] = candidates[transform][i];
        }
    }
}

int main()
{
    int ncase, len;
    scanf("%d %d", &ncase, &len);

    for (int i = 1; i <= ncase; i++) {
        solve(len);
    }

    return 0;
}
