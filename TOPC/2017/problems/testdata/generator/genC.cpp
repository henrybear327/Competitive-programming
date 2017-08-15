#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unordered_map>
#define MAX_NUM_CASES 10
#define MAX_NUM_INTERVALS 100000
#define MAX_ENDPOINT 4294967295 // 2^32 - 1
// long long endpoints[MAX_NUM_INTERVALS * 2];

int
main(int argc, const char **argv) {
  int max_num_intervals = atoi(argv[1]);
  assert(max_num_intervals >= 2 && max_num_intervals <= MAX_NUM_INTERVALS);
  printf("%d\n", MAX_NUM_CASES);
  assert(strcmp(argv[3], "general") == 0 || strcmp(argv[3], "special") == 0);

//std::cout << argv[3] << std::endl;

  if (strcmp(argv[3], "general") == 0)
    printf("4 4 7 5 5 3 9 1 8\n"); // must have a test case with a_i = b_i
  else
    printf("4 4 7 5 6 3 9 1 8\n"); // the special case forbids degenerate intervals

  long long max_endpoint = atoll(argv[2]);
  assert(max_endpoint <= MAX_ENDPOINT);

  for (int i = 0; i < MAX_NUM_CASES - 1; ++i) {
    printf("%d ", max_num_intervals);
//    long long *endpoints = new long long[max_num_intervals * 2];
//    for (int j = 0; j < max_num_intervals * 2; ++j)
//      endpoints[j] = 0;
    std::unordered_map<long long, long long> endpoints;
    endpoints.clear();
    int index;
    index = 0;

    for (int j = 0; j < max_num_intervals; ++j) {
      long long temp1 = (long long)rand() % (long long)max_endpoint + 1;
      long long temp2 = (long long)rand() % (long long)max_endpoint + 1;
      bool skip;
      skip = false;

//      for (int k = 0; k < max_num_intervals * 2; ++k)
//        if (endpoints[k] == temp1 || endpoints[k] == temp2 || temp1 == max_endpoint || temp2 == max_endpoint)
//          found = true;
      if (temp1 == max_endpoint || temp2 == max_endpoint
        || endpoints.find(temp1) != endpoints.end()
        || endpoints.find(temp2) != endpoints.end())
          skip = true;

      if (strcmp(argv[3], "special") == 0 && temp1 == temp2)
        skip = true;

      if (skip) {
        --j;
        continue;
      } else if (j < max_num_intervals - 1) {
        assert(!skip);
        assert(temp1 < max_endpoint && temp2 < max_endpoint);
        printf("%lld %lld ", (temp1 < temp2 ? temp1 : temp2), (temp1 < temp2 ? temp2 : temp1));
        endpoints[temp1] = temp1;
        endpoints[temp2] = temp2;
//        endpoints[index++] = temp1;
//        endpoints[index++] = temp2;
      } else // j == max_num_intervals - 1
        printf("%lld %lld\n", (temp1 < temp2 ? temp1 : temp2), max_endpoint); // must have max_endpoint in a test case
    }

//    delete endpoints;
  }

  return 0;
}

