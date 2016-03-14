#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  int test_cases;
  while (scanf("%d", &test_cases) == 1) {
    int data[test_cases];
    for (int i = 0; i < test_cases; i++) {
      int temp;
      scanf("%d", &temp);
      data[i] = temp + i;
    }

    qsort(data, test_cases, sizeof(int), cmp);

    int prev = data[0];
    bool flag = true;
    for (int i = 1; i < test_cases; i++) {
      if (data[i] == prev) {
        flag = false;
        break;
      }
      prev = data[i];
    }

    int answer[test_cases];
    for (int i = 0; i < test_cases; i++) {
      answer[i] = data[i] - i;
    }

    if (flag) {
      for (int i = 0; i < test_cases; i++) {
        if (i == 0)
          printf("%d", answer[i]);
        else
          printf(" %d", answer[i]);
      }
      printf("\n");
    } else {
      printf(":(\n");
    }
  }

  return 0;
}