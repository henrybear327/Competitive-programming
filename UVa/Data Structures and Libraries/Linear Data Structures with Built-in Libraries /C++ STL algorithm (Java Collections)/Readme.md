# Notes

# 146

Just simple usage of `next_permutation()`

# 10107

1. Straight-forward -> using sorting every time
2. Use `<map>`
3. (Not implemented) Just shift the array to insert an number every time, and do an ` & 1` to test for odd or even.

# 10258

1. `qsort(data, 101, sizeof(Score), cmp);` -->
`sizeof(Score)`, not `sizeof(data)`. Come on, man!

2. Read the problem statement carefully, don't think it's trivial and make stupid mistake. Ex: if there is submission from team 3, but no AC, you need to print 3 0 0
