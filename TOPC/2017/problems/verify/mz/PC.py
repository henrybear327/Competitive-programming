#!/usr/bin/env python3

T = int(input())
for _ in range(T):
    p = [int(x) for x in input().split()]
    a, b = p[1::2], p[2::2]
    a.sort()
    b.sort()
    iter_a = iter_b = 0
    n = len(b)
    ans = 0
    depth = 0
    while iter_a < n:
        if a[iter_a] <= b[iter_b]:
            iter_a += 1
            depth += 1
        else:
            iter_b += 1
            depth -= 1
        ans = max(ans,depth)
    print(ans)
