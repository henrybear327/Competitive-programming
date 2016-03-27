#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

map<string, int> duplicate;

char input[100];
char input2[100];
char io_string[200];
int len;

int used[200];
int ans[200];
int cur_i, cur_o;

bool test()
{
    stack<char> tmp;
    int idx = 0, idx2 = 0;
    for (int i = 0; i < 2 * len; i++) {
        if (io_string[ans[i]] == 'i')
            tmp.push(input[idx++]);
        else {
            if (tmp.top() != input2[idx2++])
                return false;
            else
                tmp.pop();
        }
    }

    return true;
}

void dfs(int level)
{
    // permutation
    if (level == 2 * len) {
        if (test() == false)
            return;

        string check;
        for (int i = 0; i < 2 * len; i++) {
            check += io_string[ans[i]];
        }

        if (duplicate[check] != 1)
            duplicate[check] = 1;
        else
            return;

        // print the output
        for (int i = 0; i < 2 * len; i++) {
            if (i != 2 * len - 1)
                printf("%c ", io_string[ans[i]]);
            else
                printf("%c\n", io_string[ans[i]]);
        }

        return;
    }

    for (int i = 0; i < 2 * len; i++) {
        if (used[i] == 0) {
            if (i >= len && cur_o + 1 > cur_i)
                continue;

            if (i < len)
                cur_i++;
            else
                cur_o++;

            used[i] = 1;
            ans[level] = i;

            dfs(level + 1);

            if (i < len)
                cur_i--;
            else
                cur_o--;
            used[i] = 0;
            ans[level] = 0;
        }
    }
}

int main()
{
    while (fgets(input, 100, stdin) != NULL &&
           fgets(input2, 100, stdin) != NULL) {
        memset(used, 0, sizeof(used));
        memset(ans, 0, sizeof(ans));
        duplicate.clear();
        cur_i = cur_o = 0;

        printf("[\n");

        len = (int)strlen(input) - 1;
        int len2 = (int)strlen(input2) - 1;

        if (len != len2) {
            printf("]\n");
            continue;
        }

        for (int i = 0; i < 2 * len; i++)
            io_string[i] = i < len ? 'i' : 'o';

        dfs(0);

        printf("]\n");
    }

    return 0;
}
