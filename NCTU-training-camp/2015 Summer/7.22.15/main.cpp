#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX
#include <cmath>

using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    int years;
    while (scanf("%d", &years) == 1 && years >= 0) {
        long long int data[3] = {0, 0, 1}; // male, female, immortal female
        while (years--) {
            long long int temp[3] = {0, 0, 1};
            if (data[0] > 0)
                temp[1] += data[0];
            if (data[1] > 0) {
                temp[0] += data[1];
                temp[1] -= data[1];
            }
            temp[0] += data[0];
            temp[1] += data[1];
            temp[0]++;

            for (int i = 0; i < 3; i++) {
                // printf("%d ", temp[i]);
                data[i] = temp[i];
            }
            // printf("\n");
        }
        printf("%lld %lld\n", data[0], data[0] + data[1] + data[2]);
    }

    return 0;
}
