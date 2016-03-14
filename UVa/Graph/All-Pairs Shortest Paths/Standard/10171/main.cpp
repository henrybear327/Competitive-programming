#include <cstdio>

#define INT_MAX 10000000
#define MIN(x, y) ((x) < (y) ? (x) : (y))

void run(int graph[26][26])
{
    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                graph[i][j] = MIN(graph[i][k] + graph[k][j], graph[i][j]);
}

int main()
{
    int roads;
    while (scanf("%d", &roads) == 1 && roads != 0) {
        getchar();

        int graph_y[26][26];
        int graph_m[26][26];

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                graph_y[i][j] = INT_MAX;
                graph_m[i][j] = INT_MAX;
            }
            graph_y[i][i] = 0;
            graph_m[i][i] = 0;
        }

        for (int i = 0; i < roads; i++) {
            char tmp[100];
            fgets(tmp, 100, stdin);

            char a, b, c, d;
            int e;
            sscanf(tmp, "%c %c %c %c %d", &a, &b, &c, &d, &e);

            if (a == 'Y') {
                if (b == 'U') {
                    graph_y[c - 'A'][d - 'A'] = e;
                } else {
                    graph_y[c - 'A'][d - 'A'] = e;
                    graph_y[d - 'A'][c - 'A'] = e;
                }
            } else {
                if (b == 'U') {
                    graph_m[c - 'A'][d - 'A'] = e;
                } else {
                    graph_m[c - 'A'][d - 'A'] = e;
                    graph_m[d - 'A'][c - 'A'] = e;
                }
            }
        }

        char a, b;
        scanf("%c %c", &a, &b);
        int init_a = a - 'A', init_b = b - 'A';

        // Floyd-Warshall
        run(graph_m);
        run(graph_y);

        for (int i = 0; i < 26; i++) {
            graph_y[i][i] = 0;
            graph_m[i][i] = 0;
        }

        /*
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++)
                printf("%9d ", graph_y[i][j]);
            printf("\n");
        }
        printf("\n\n");

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++)
                printf("%9d ", graph_m[i][j]);
            printf("\n");
        }
        */

        int min_energy = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (graph_y[init_a][i] != INT_MAX && graph_m[init_b][i] != INT_MAX) {
                min_energy = MIN(min_energy, graph_y[init_a][i] + graph_m[init_b][i]);
            }
        }

        if (min_energy != INT_MAX) {
            printf("%d", min_energy);
            for (int i = 0; i < 26; i++) {
                if (graph_y[init_a][i] + graph_m[init_b][i] == min_energy)
                    printf(" %c", i + 'A');
            }
        } else {
            printf("You will never meet.");
        }
        printf("\n");
    }
    return 0;
}
