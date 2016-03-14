#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct score {
    int time, solved, team, active;
    int problem[10];
    int pre_time[10];
} Score;

int cmp(const void *a, const void *b)
{
    Score *c = (Score *)a;
    Score *d = (Score *)b;

    if (c->active == 1 && d->active == 1) {
        if (c->solved == d->solved)
            return c->time - d->time;
        else
            return d->solved - c->solved;
    } else
        return d->active - c->active;
}

int main()
{
    int cases;
    scanf("%d", &cases);

    char input[100];
    fgets(input, 100, stdin);
    fgets(input, 100, stdin);
    while (cases--) {
        Score data[101];
        memset(data, 0, sizeof(data));
        for (int i = 0; i < 101; i++)
            data[i].team = i;

        while (fgets(input, 100, stdin) != NULL && input[0] != '\n') {
            int contestant, problem, time;
            char verdict;
            sscanf(input, "%d %d %d %c", &contestant, &problem, &time, &verdict);

            data[contestant].active = 1;

            if (verdict == 'C') {
                if (data[contestant].problem[problem] != 1) {
                    data[contestant].time += (time + data[contestant].pre_time[problem]);
                    data[contestant].solved++;
                    data[contestant].problem[problem] = 1; // total problem solved
                }
            } else if (verdict == 'I') {
                data[contestant].pre_time[problem] += 20;
            }
        }

        qsort(data, 101, sizeof(Score), cmp); // sizeof Score, not data

        for (int i = 0; i < 101; i++) {
            if (data[i].active == 0)
                break;
            printf("%d %d %d\n", data[i].team, data[i].solved, data[i].time);
        }

        if (cases)
            printf("\n");
    }

    return 0;
}
