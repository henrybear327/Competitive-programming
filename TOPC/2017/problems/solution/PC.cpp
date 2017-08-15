#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_NUM_CASES 10
#define MAX_INTERVALS 100000

typedef struct {
  long long x;
  bool is_start;
} endpoint_t;

int
compare(const void *a, const void *b) {
  int ans;

  if ((*(endpoint_t *)a).x < (*(endpoint_t *)b).x)
    ans = -1;
  else if ((*(endpoint_t *)a).x > (*(endpoint_t *)b).x)
    ans = 1;
  else if ((*(endpoint_t *)a).is_start && !(*(endpoint_t *)b).is_start)
    ans = -1;
  else if ((*(endpoint_t *)b).is_start && !(*(endpoint_t *)a).is_start)
    ans = 1;
  else
    ans = 0;

  return ans;
}

int
main() {
  int num_cases, temp;
  temp = scanf("%d", &num_cases);
  assert(temp == 1 && num_cases >= 1);

  while (num_cases-- > 0) {
    int num_intervals;
    temp = scanf("%d", &num_intervals);
    endpoint_t endpoints[MAX_INTERVALS * 2];
    assert(temp == 1 && num_intervals >= 2 && num_intervals <= MAX_INTERVALS);

    for (int i = 0; i < num_intervals * 2; i += 2) {
      temp = scanf("%lld", &(endpoints[i].x));
      assert(temp == 1);
      endpoints[i].is_start = true;
      temp = scanf("%lld", &(endpoints[i + 1].x));
      assert(temp == 1);
      assert(endpoints[i].x <= endpoints[i + 1].x);
      assert(endpoints[i].x >= 1);
      endpoints[i + 1].is_start = false;
    }

    qsort(endpoints, num_intervals * 2, sizeof(endpoint_t), compare);
    int thickness, max_thickness;

    for (int i = thickness = max_thickness = 0; i < 2 * num_intervals; ++i) {
      thickness += (endpoints[i].is_start ? 1 : -1);
      assert(thickness >= 0);
      max_thickness = (thickness > max_thickness ? thickness : max_thickness);

      if (i < 2 * num_intervals - 1) {
        assert(endpoints[i].x <= endpoints[i + 1].x);
        assert(endpoints[i].x < endpoints[i + 1].x || (endpoints[i].is_start && !endpoints[i + 1].is_start));
      }
    }

    printf("%d\n", max_thickness);
  }

  return 0;
}


