# Competitive programming

> Never, never, never give up.

Winston Churchill

# Categorized problems

## Binary Search

* [Hard Process](http://codeforces.com/contest/660/problem/C): Watch out for the initial condition!
* [Worms](http://codeforces.com/contest/474/problem/B): lower_bound
* [11057 - Exact Sum](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1998)

## Two pointer

```
1. Let the right pointer go as far as it could
2. Update the answer
3. Increment the left pointer by Online
4. Repeat the entire procedure
```

* [Hard Process](http://codeforces.com/contest/660/problem/C)
* [Kefa and Company](http://codeforces.com/problemset/problem/580/B)

## Math

* Modulo
    * [Round House](http://codeforces.com/contest/659/problem/A)
* Set
    * [Watchmen](http://codeforces.com/contest/651/problem/C)

## Fun   

* [Bicycle Race](http://codeforces.com/contest/659/problem/D)

## String

* Implementation
  * [Simple Strings](http://codeforces.com/contest/665/problem/C)

## Graph

* DFS
    * [New Reform](http://codeforces.com/contest/659/problem/E)
    * [Apple Tree](http://poj.org/problem?id=3321)
* BFS
    * [Expressions](http://poj.org/problem?id=3367)

## UFDS  

* [New Reform](http://codeforces.com/contest/659/problem/E)
* [Cube Stacking](http://poj.org/problem?id=1988)
* [Navigation Nightmare](http://poj.org/problem?id=1984)

## BIT

* [Apple Tree](http://poj.org/problem?id=3321)

## Extended Euclidean Algorithm

*

## Fast power

## Time

* [Buses Between Cities](http://codeforces.com/contest/665/problem/A)

## Segment Tree

* [Balanced Lineup](http://poj.org/problem?id=3264): Very basic segment tree min/max problem
* [A Simple Problem with Integers](http://poj.org/problem?id=3468): Very basic segment tree with lazy propagation

## Articulation point

* [Network](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=251)

## Bridge

* [Critical Links](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737)

### Using Struct for Segment Tree Notes

```
You have to define a destructor and destroy your objects (someMutex and someString).

But, as you have allocated someMutex with malloc, you must free it with free.

Take care for not to mix them.

Remember:

allocated with malloc, freed with free
allocated with new, freed with delete
allocated with new[], freed with delete[]
```
