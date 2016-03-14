# Notes

### 11136

1. NEVER attemp to code things like `printf("%d\n", amap.end());`, `.end()` is
the past-the-end element! _OVERFLOW_
2. The total number of all bills is no bigger than 10^6 != The total amount of money
is no bigger than 10^6. Come on, man!! Use `long long int`

### 11849

Basic set operation

## 978

1. Return iterator is IMPORTANT!!! `ig = g.erase(ig);` Precious time lost....
(Using PQ to solve this one is about 1X faster)
2. `multiset<int, greater<int>> g;`
