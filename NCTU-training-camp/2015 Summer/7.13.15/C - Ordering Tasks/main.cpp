#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef struct edge {
    int from;
    int to;
} Edge;

void check_in_degree(int vertex, int limit, int in_degree[], Edge input[])
{
    // printf("%d %d\n", vertex, limit);
    for (int i = 0; i < limit; i++) {
        if (input[i].from == vertex) {
            in_degree[input[i].to]--;
        }
    }

    return;
}

int main()
{
    int vertex, test_case;
    while (scanf("%d %d", &vertex, &test_case) == 2 &&
           !(vertex == 0 && test_case == 0)) {
        int in_degree[vertex + 1];
        Edge input[test_case];
        memset(in_degree, 0, sizeof(in_degree));
        memset(input, 0, sizeof(input));
        for (int i = 0; i < test_case; i++) {
            int from, to;
            scanf("%d %d", &from, &to);
            in_degree[to]++;
            input[i].from = from;
            input[i].to = to;
        }
        queue<int> data;
        for (int i = 1; i <= vertex; i++) {
            if (in_degree[i] == 0) {
                data.push(i);
                in_degree[i] = -1;
            }
        }

        if (vertex == 1) {
            printf("1\n");
            continue;
        }

        /*
        for (int i = 0; i < test_case; i++) {
            printf("%d %d\n", input[i].from, input[i].to);
        }
        */

        vector<int> answer;
        while (data.size() != 0) {
            // printf("front %d\n", data.front());
            answer.push_back(data.front());
            /*
            printf("before\n");
            for (int i = 1; i <= vertex; i++)
                printf("%d ", in_degree[i]);
            printf("\n");
            */

            check_in_degree(data.front(), test_case, in_degree, input);

            /*
            printf("after\n");
            for (int i = 1; i <= vertex; i++)
                printf("%d ", in_degree[i]);
            printf("\n");
            */
            for (int i = 1; i <= vertex; i++) {
                if (in_degree[i] == 0) {
                    data.push(i);
                    in_degree[i] = -1;
                    // printf("enqueue %d\n", i);
                    check_in_degree(i, test_case, in_degree, input);
                }
            }
            // printf("here\n");
            data.pop();
        }

        for (int i = 0; i < vertex; i++) {
            if (i != vertex - 1)
                printf("%d ", answer.at(i));
            else
                printf("%d\n", answer.at(i));
        }
    }

    return 0;
}
