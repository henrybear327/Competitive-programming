#!/usr/bin/env python3

from math import pi, asin, cos
from random import randint as ri
import sys

def bisection(low, up, pred, err):
    while (up-low)/max(1,(up+low))>0.5*err:
        mid = (up+low)/2
        if pred(mid) >= 0:
            low = mid
        else:
            up = mid
    return up

def gen(T):
    yield [[2*2.000001*pi,4],[2,2,4,2]]
    yield [[5*pi*2.000001,4],[6,6,8,8]]
    yield [[18,4],[2,2,2,5]]
    yield [[57,10],[1,2,3,4,5,6,7,8,9,10]]
    yield [[1000,3],[1,1,1]]
    yield [[10,6],[1,2,1,2,1,2]]
    for n in range(3,11):
        r = 1.0 / (2-2*cos(2*pi/n))**0.5
        scale = 1+int(10.0 / r / pi / 2.000001)
        yield [[scale*r*2.000001*pi,n],[scale]*n]
    T -= 14
    for _ in range(20):
        while True:
            n = max(ri(4,10) for __ in range(2))
            e = [1]*(n-1)+[ri(20,100)]
            e.sort()
            while sum(e) <= 2*max(e)+_:
                e[ri(0,n-2)] += 1
            if sum(asin(x/max(e)) for x in e) >= pi:
                continue
            D = bisection(max(e),1e5,lambda d: 2*asin(max(e)/d)-sum(asin(x/d) for x in e), 1e-14)
            C = D*pi*2**(1/ri(2,10000))
            if C <= 1000:
                print('case',_+14,D,2*asin(max(e)/D)-sum(asin(x/D) for x in e),sum(asin(x/D) for x in e),file=sys.stderr)
                yield [[C,n],e]
                break
    T -= 20
    for _ in range(T):
        while True:
            n = max(ri(3,10) for _ in range(3))
            e = [ri(1,200//n) for _ in range(n)]
            if sum(e) < 2*max(e):
                continue
            if sum(asin(x/max(e)) for x in e) >= pi:
                D = bisection(max(e),sum(e),lambda d: sum(asin(x/d) for x in e)-pi,1e-14)
            else:
                D = bisection(max(e),1e5,lambda d: 2*asin(max(e)/d)-sum(asin(x/d) for x in e), 1e-14)
                print('case',_+34,file=sys.stderr)
            C = D*pi*2**(1/ri(2,10000))
            if C <= 1000:
                yield [[C,n],e]
                break

T = 100
print(T)
for testdata in gen(T):
    for line in testdata:
        print(*line)
