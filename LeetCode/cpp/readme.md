# Reminders

1. Deal with `NULL` pointer case and `sz = 0` cases first!
2. Carefully consider the input conditions that is given
3. Come up with the sub-optimal/naive solution first
4. Testcases:
    * no element
    * one element
    * extreme value
    * duplicated values
5. When doing recursion, think of the terminating conditions first
6. Set the initial values carefully
7. For binary search, consider the monotonic property carefully first!
8. For linked list, don't forget to more the the cursor forward
9. If you mean to use reference, double check for it!
10. When doing `min()` `max()`, make sure the answer is updated every time and AFTER the last iteration
11. When doing `mn` and `mx` updating, make sure we keep the original value first!!!! (leetcode 152)
12. `int *a, *b;` for a and b both to be declared as pointer!
13. When brute forcing, think if you can keep a memo of the search space (leetcode 139)
14. Brute force: for every position... (leetcode 42)
15. Clarify if `int` might be enough! If using long long, make sure that the conversion is done properly! (leetcode 50)

# Compilation

1. `PROBLEM=...`
2. 
```
clang-format -style=LLVM -i $PROBLEM.cpp && astyle --style=linux $PROBLEM.cpp && rm $PROBLEM.cpp.orig && g++ -Wall -Wextra -Wshadow -O2 -std=c++11 -DLOCAL $PROBLEM.cpp && time ./a.out
```

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

# Questions that I messed up

* Leetcode 388