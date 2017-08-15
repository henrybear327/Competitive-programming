#!/usr/bin/env python3

from math import pi, asin

def area(a,b,c):
    s = (a + b + c)/2
    return (s*(s-a)*(s-b)*(s-c))**0.5

def bisection(low, up, pred, err):
    while (up-low)/max(1,(up+low))>0.5*err:
        mid = (up+low)/2
        if pred(mid) >= 0:
            low = mid
        else:
            up = mid
    return (low+up)/2

T = int(input())
for _ in range(T):
    c, n = [float(x) for x in input().split()]
    L = [float(x) for x in input().split()]
    CA = pi*(c/(2*pi))**2
    max_L = max(L)
    angle_sum = sum(asin(x/max_L) for x in L)
    # print(CA, angle_sum)
    if angle_sum >= pi:
        R = bisection(max_L/2, c/pi, lambda R: sum(asin(0.5*x/R) for x in L)-pi, 1e-14)
        print(CA-sum(area(R,R,x) for x in L))
    else:
        ### Key observation! asin and its 1st derivative is monotone in [0,1]
        R = bisection(max_L/2, c/pi, lambda R: 2*asin(0.5*max_L/R)-sum(asin(0.5*x/R) for x in L), 1e-14)
        print(CA-sum(area(R,R,x) for x in L)+2*area(R,R,max_L))
