#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

vector<int> inp[6];

int ans[6];
void dfs(int level)
{
    if (level == 5) {
        for (int i = 0; i < (int)inp[5].size(); i++) {
            ans[5] = inp[5][i];
            for (int j = 0; j < 6; j++) {
                printf("%d%c", ans[j], j == 5 ? '\n' : ',');
            }
        }
        return;
    }

    for (int i = 0; i < (int)inp[level].size(); i++) {
        ans[level] = inp[level][i];
        dfs(level + 1);
    }
}

int main()
{
    for (int i = 0; i < 6; i++) {
        char input[10000];
        fgets(input, 10000, stdin);

        char *num = strtok(input, ", \n\r");
        while (num != NULL) {
            inp[i].push_back(atoi(num));
            num = strtok(NULL, ", \r\n");
        }
    }

    /*
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < (int)inp[i].size(); j++)
            printf("%d%c", inp[i][j], j == (int)inp[i].size() - 1 ? '\n' : ' ');
    */

    dfs(0);

    return 0;
}
