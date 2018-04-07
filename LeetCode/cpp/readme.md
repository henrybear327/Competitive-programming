# Reminders

1. Deal with `NULL` pointer case and `sz = 0` cases first!
2. Carefully consider the input conditions that is given
    * range/sign of input! (leetcode 166)
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

```
string item;
stringstream ss;
ss.str(input);

while(!getline(ss, item, ',')) {

}
```

# conversion

string versio of `atoi()`: `stoi()`

# Questions that I messed up

* Simply good one: 388, 240 (581 talked about it, now finally understands it)
* Good but hard greedy: 316
* Iterator: 341, 26 (implement unique)
* Trie
    * (easy) 421
    * (design) 208
* Heavy implementation skill: 166, 315, 10
* Good DP: 10, 312 (cutting stick, but in a different approach), 309(state machine approach, wow!)
* Math: 172 (I can't believe how bad my math is)
* Tree: 124 (wow, path! 3 cases)
* Geometry: 149
* Easy DP: 221 (first time coming up with a DP solution!)
* Good observation: 11
* Recursion: 114