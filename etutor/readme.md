# ITSA

ITSA submission backup.

# Common pitfalls

* Think of `long long int` before coding.
* Use `scanf("%s", input)` when there is no spaces in the string. Mix usage of `fgets` and `scanf` will have `\n` problem.
* `scanf()` > `fgets()`
* UVa 11988: when using global variables, don't forget to INITIALIZE it before starting reading in new test cases!!
* Test the special cases, such as 0, -1, 1, or max_value, before even submitting the code.
* When using `double`, don't make mistakes like
  ```
  int x = 1, y = 2;
  double s = y / x;
  ```
* Don't get trapped in "I have solved this before!"
* Compare function: Don't do ```return a - b``` if a and b are floating point numbers!! (problem B)
* Don't use copy paste unless the code is identical! Messed up problem D with this
stupid mistake.
