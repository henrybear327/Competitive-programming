#!/usr/bin/env python3

T = int(input())
for _ in range(T):
    hand = {}
    for c in input().split():
        c = int(c)
        hand.setdefault(c,0)
        hand[c] += 1
    if len(hand) == 6:
        print('single')
    elif len(hand) == 5:
        print('one pair')
    elif len(hand) == 4:
        if any(v==3 for v in hand.values()):
            print('one triple')
        else:
            print('two pairs')
    elif len(hand) == 3:
        if any(v==4 for v in hand.values()):
            print('tiki')
        elif any(v==3 for v in hand.values()):
            print('full house')
        else:
            print('three pairs')
    elif len(hand) == 2:
        if any(v==3 for v in hand.values()):
            print('two triples')
        else:
            print('tiki pair')
