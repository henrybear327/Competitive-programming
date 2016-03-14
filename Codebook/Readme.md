# Codebook

Algorithms that I have actually implemented in the past.

# Reminder

1. When using fgets, make sure there are at least 2 spaces for `\n` and `\0`
2. Use `gg=G` to do auto-indent

# To-do

1. Add 找所有因數 code
2. Code all algorithms included.

# What to test before contest

1. Is the type `auto` working?
2. Is `#include <bits/stdc++.h>` working?
3. Use `%lld` or `%I64d`? (Use the following macro to deal with `%I64d`)
```
#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif
```

# Short Code

* GCD
```
long long int gcd(long long int a, long long int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
```

* LCM
```
a * b / gcd(a,b)
```

* Leap year
```
year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)
```

* Matrix multiplication
```
for (int i = 0; i < n; i++) {
  for (int k = 0; k < p; k++) {
    int tmp = 0;
    for (int j = 0; j < m; j++) {
      tmp += a[i][j] * b[j][k];
    }
    if (tmp > max)
    max = tmp;
  }
}
```

# BFS over a graph

#### (Code simplified and commented from UVa 924)
```
int visited[employee]; // to avoid repeatedly enqueueing elements
memset(visited, 0, sizeof(visited)); //init

queue<int> bfs;
bfs.push(inp); // push the starting element into the queue
visited[inp] = 1;

while (bfs.size()) {
    int curr = bfs.front();
    bfs.pop();

    //using vector
    for (vector<int>::iterator i = graph[curr].begin(); i != graph[curr].end(); i++) {
        if (visited[*i] == 0) {
            bfs.push(*i);
            visited[*i] = visited[curr] + 1; //record level
        }
    }

    //using array
    for (int i = 0; i < (int)graph[curr].size(); i++) {
        if (visited[graph[curr][i]] == 0) {
            bfs.push(graph[curr][i]);
            visited[graph[curr][i]] = visited[curr] + 1;
        }
    }
}
```
# Floyd Warshall (APSP - All-Pairs Shortest Paths)

Using a n * n adjacency matrix to store the graph.

Update the distance between vertices a and b by adding 1 vertex, e.g. c, at a time,
and check if going a->c->b can shorten the distance between a and b or not.
```
for (int k = 1; k < max; k++)
  for (int i = 1; i < max; i++)
    for (int j = 1; j < max; j++)
          graph[i][j] = MIN(graph[i][j], graph[i][k] + graph[k][j]);
```
