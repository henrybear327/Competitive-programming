#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

int main()
{
    int total;
    scanf("%d", &total);
    char input[100];
    fgets(input, 100, stdin);

    int data[1000010] = {0};
    int concurrent = 0, max_concurrent = 0;
    for (int i = 0; i < total; i++) {
        // printf("%d %d\n", concurrent, max_concurrent);
        fgets(input, 100, stdin);

        char sign;
        int ID;
        sscanf(input, "%c %d", &sign, &ID);
        // printf("%c %d\n", sign, ID);

        if (sign == '+') {
            if (data[ID] == 0) {
                data[ID] = 1;
                concurrent++;
                max_concurrent = MAX(max_concurrent, concurrent);
            }
        } else {
            if (data[ID] == 0) {
                max_concurrent++;
            } else {
		data[ID] = 0;
                concurrent--;
            }
        }
    }

    printf("%d\n", max_concurrent);

    return 0;
}
