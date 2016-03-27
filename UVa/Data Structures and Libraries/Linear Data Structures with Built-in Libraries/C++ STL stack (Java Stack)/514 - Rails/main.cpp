#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int coach;
    while (scanf("%d", &coach) == 1 && coach) {
        while (1) {
            int seq[coach];
            bool flag = true;
            for (int i = 0; i < coach; i++) {
                scanf("%d", &seq[i]);
                if (seq[0] == 0) {
                    flag = false;
                    break;
                }
            }

            if (flag == false) {
                printf("\n");
                break;
            }

            int idx = 0;
            stack<int> station;

            for (int i = 0; i < coach; i++) {
                if (seq[idx] != i + 1)
                    station.push(i + 1);
                else {
                    idx++;
                    while (!station.empty() && station.top() == seq[idx]) {
                        idx++;
                        station.pop();
                    }
                }
            }

            while (!station.empty() && station.top() == seq[idx]) {
                idx++;
                station.pop();
            }

            if (station.empty() && idx == coach)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
