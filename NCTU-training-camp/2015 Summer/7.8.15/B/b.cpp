#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define DEBUG 0

using namespace std;

typedef struct team {
    int count;
    vector<int> team_member;
    queue<int> team_queue;
} Team;

int main()
{
    int tot_team, case_count = 1;
    while (scanf("%d", &tot_team) == 1 && tot_team != 0) {
        queue<int> display_queue;
        bool in_display_queue[1000] = {false};
        printf("Scenario #%d\n", case_count++);
        Team data[1000];
        for (int i = 0; i < tot_team; i++) {
            scanf("%d", &data[i].count);
            for (int j = 0; j < data[i].count; j++) {
                int temp;
                scanf("%d", &temp);
                data[i].team_member.push_back(temp);
            }
        }

#if DEBUG
        printf("data!\n");
        for (int i = 0; i < tot_team; i++) {
            for (int j = 0; j < data[i].count; j++) {
                printf("%d ", data[i].team_member.at(j));
            }
            printf("\n");
        }
        printf("End data\n\n");
#endif

        char input[100];
        fgets(input, 100, stdin);
        while (fgets(input, 100, stdin) != NULL) {
            char *command = strtok(input, " \n");
#if DEBUG
            printf("%s\n", command);
#endif
            if (strcmp(command, "ENQUEUE") == 0) {
                char *member = strtok(NULL, " \n");
                int member_i = atoi(member), flag = 1;
                for (int i = 0; i < tot_team && flag; i++) {
                    for (int j = 0; j < data[i].count; j++) {
                        if (data[i].team_member.at(j) == member_i) {
                            if (in_display_queue[i] == false) {
                                in_display_queue[i] = true;
                                display_queue.push(i);
                            }
                            data[i].team_queue.push(member_i);
                            flag = 0;
                            break;
                        }
                    }
                }
            } else if (strcmp(command, "DEQUEUE") == 0) {
                printf("%d\n", data[display_queue.front()].team_queue.front());
                data[display_queue.front()].team_queue.pop();
                if (data[display_queue.front()].team_queue.size() == 0) {
                    in_display_queue[display_queue.front()] = false;
                    display_queue.pop();
                }
            } else {
                // stop
                break;
            }
#if DEBUG
            for (int i = 0; i < tot_team; i++)
                printf("%d ", in_display_queue[i]);
            printf("\n");
#endif
        }
        printf("\n");
    }

    return 0;
}