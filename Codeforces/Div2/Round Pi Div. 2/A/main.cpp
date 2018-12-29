#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

int main() {
  int cases;
  scanf("%d", &cases);
  int DP[100100] = {0};

  int prev;
  scanf("%d", &prev);
  for (int i = 1; i < cases; i++) {
    int tmp;
    scanf("%d", &tmp);
    DP[i] = DP[i - 1] + abs(tmp - prev);
    prev = tmp;
  }

  for (int i = 0; i < cases; i++) {
    if (i == 0)
      printf("%d %d\n", DP[1], DP[cases - 1]);
    else if (i == cases - 1)
      printf("%d %d\n", DP[cases - 1] - DP[cases - 2], DP[cases - 1]);
    else
      printf("%d %d\n", MIN(abs(DP[i] - DP[i - 1]), abs(DP[i + 1] - DP[i])),
             MAX(abs(DP[i] - DP[0]), abs(DP[cases - 1] - DP[i])));
  }

  return 0;
}
