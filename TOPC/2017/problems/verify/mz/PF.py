#!/usr/bin/env python3

MOD = 10**9 + 7
factorial = [[1],[1]]
for i in range(1,10001):
    factorial[0].append(factorial[0][-1]*i%MOD)
    factorial[1].append(pow(factorial[0][-1],MOD-2,MOD))

def Compute(a, b):
    if b > a: return 0
    if b == 0 or b == a: return 1
    ans = factorial[0][a]*factorial[1][b]%MOD
    ans = ans*factorial[1][a-b]%MOD
    return ans

TCs = int(input())
for _ in range(TCs):
    N = [[0]*35,[0]*35]
    N[0][0], N[1][0], M = [int(x) for x in input().split()]
    for i in range(1,35):
        N[0][i], N[1][i] = N[0][i-1]//M, N[1][i-1]//M
        N[0][i-1], N[1][i-1] = N[0][i-1]%M, N[1][i-1]%M
    ans = 1
    for a, b in zip(N[0],N[1]):
        ans = ans * Compute(a,b) % MOD
    print(ans)
