# Reminders

1. Deal with `NULL` pointer case and `sz = 0` cases first!
2. Carefully consider the input conditions that is given
    * range/sign of input! (leetcode 166, 7)
    * input datatype (int, float; string, vector, array)
3. Come up with the sub-optimal/naive solution first
4. Testcases:
    * no element
    * one element
    * extreme value
    * duplicated values
5. When doing recursion, think of the terminating conditions first
6. Set the initial values carefully (leetcode 228)
7. For binary search, consider the monotonic property carefully first!
8. For linked list, don't forget to more the the cursor forward
9. If you mean to use reference, double check for it!
10. When doing `min()` `max()`, make sure the answer is updated every time and AFTER the last iteration
11. When doing `mn` and `mx` updating, make sure we keep the original value first!!!! (leetcode 152)
12. `int *a, *b;` for a and b both to be declared as pointer!
13. When brute forcing, think if you can keep a memo of the search space (leetcode 139, 96)
14. Brute force: for every position... (leetcode 42)
15. Clarify if `int` might be enough! If using long long, make sure that the conversion is done properly! (leetcode 50)
16. Might need to deal with negative numbers! (Leetcode 326)
17. Use bit trick to save space (Leetcode 289)
18. Use `(ternary stuff)`!
19. If you use `while` and needs to manually maintain the pointer, add comments first!
20. When checking strings, vectors: watch out for out-of-bound error
21. Think of all cases before you type `+=` and `return` (leetcode 124, cases could be thought of when typing)
22. When pushing things onto the stack, we can just push the index, instead of value-index pair! (84)
23. Do **NOT** be afraid when you see problems being labelled as hard!

# Compilation

1. `PROBLEM=...`
2.
```
clang-format -style=LLVM -i $PROBLEM.cpp && astyle --style=linux $PROBLEM.cpp && rm $PROBLEM.cpp.orig && time g++ -Wall -Wextra -Wshadow -O2 -std=c++14 -DLOCAL $PROBLEM.cpp && time ./a.out
```

* check for total problems solved `ls *.cpp | wc -l`

# TreeNode code

```c++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

# Singly linked list

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

# sstream

```c++
string item;
stringstream ss;
ss.str(input);

while(!getline(ss, item, ',')) {

}
```

# conversion

string version of `atoi()` is `stoi()`

# Questions that I messed up

* Simply good one: 240 (581 talked about it, now finally understands it)
* Good but hard greedy: 316
* Two pointer: 683 (nlogn is easy though), 239 (deque), 340, 76 (hard)
* Iterator: 341, 26 (implement unique)
* Trie
    * (easy) 421
    * (design) 208
* Heavy implementation skill: 388 (stack), 166, 315, 10, 336 (don't be afraid to enumerate), 681 (100 lines 1 AC!, but time conversion can be done in a more elegant way), 218 (skyline)
* Good DP: 10, 312 (cutting stick, but in a different approach), 96(1D), 309(state machine approach, wow!)
* Math: 172 (I can't believe how bad my math is)
* Tree: 124 (wow, path! 3 cases)
* Geometry: 149
* Easy DP: 221 (first time coming up with a DP solution!), 85 (based on max rect in histogram)
* Good observation: 11
* Recursion: 114, 140, 298 (good one)
* Pointer: 237 (never thought of it!), 328
* Recursion `O(2^N)`, with memoization `O(N^2)` because you kept all possible pairs of `(start, end)` in DP!
* Do it from the front or back, coding complexity differs: 482
* Basic DP: 72 (edit distance)
* To graph (753)
* DS: 308 (2d bit)
* UFDS: 737

# Procedure

* Ask for spec
* Generate basic testcases, and add more while coding
