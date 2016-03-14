# Notes

### 821

Just a Floyd-Warshall!

Make sure to initialize the graph first(be aware of the equal sign)

Two coding style improvements:
1. When initializing, the diagonal can be initialized by `graph[i][i]`
2. ```max = MAX(MAX(a, b), max);```
3. The core comparing function can be written as
```
for (int i = 1; i < max; i++) {
      for (int j = 1; j < max; j++) {
          for (int k = 1; k < max; k++) {
              /*
              if (graph[j][k] > graph[j][i] + graph[i][k]) {
                  graph[j][k] = graph[j][i] + graph[i][k];
              }
              */
              graph[j][k] = MIN(graph[j][k], graph[j][i] + graph[i][k]);
          }
      }
}
```

### 10171

1. Critical input, where two guys start at the same place, must be considered!!!!
```
2
Y B A A 2
M B A A 3
A A
```
2. Better use ```min(g1[x][y], val)``` to update vertices to avoid stupid error

### 11463

Key Idea: ```ans = Maximum value of start->vertex + vertex->end```
