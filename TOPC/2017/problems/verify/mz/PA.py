#!/usr/bin/env python3

T = int(input())
for _ in range(T):
    input()
    A = set(input().split())
    B = set(input().split())
    if len(A & B) * 2 > len(A | B):
        print(1)
    else:
        print(0)
