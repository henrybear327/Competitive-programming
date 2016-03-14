#include <cstdio>
#include <vector>

using namespace std;

vector<int> position[1000001];

int main()
{
    int total, query;
    while (scanf("%d %d", &total, &query) == 2) {
        /*
        for (int i = 0; i < 1000001; i++)
                    position[i].clear();
        */

        for (int i = 1; i <= total; i++) {
            int tmp;
            scanf("%d", &tmp);

            position[tmp].push_back(i);
        }

        while (query--) {
            int occurence, number;
            scanf("%d %d", &occurence, &number);

            if ((int)position[number].size() < occurence) {
                printf("0\n");
                continue;
            }

            // auto i = position[number].begin() + occurence - 1;

            // vector<int>::iterator i = position[number].begin() + occurence - 1;
            // printf("%d\n", *i);

            printf("%d\n", position[number][occurence - 1]);
        }
    }

    return 0;
}
