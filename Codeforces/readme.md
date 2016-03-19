# Codeforces Contest code backup

I started doing Codeforces contest in 2015 summer vacation while participating in **2015CPSTC(competitive programming summer training camp)** @NCTU. Thanks to the teacher and student mentors there. :)

This is a repository that I use for backing up my Codeforces code. I am still new to this competitive programming field, so my code may be really bad. Please don't take it too seriously.

# Compilation parameter

`clang-format-3.7 -style=LLVM -i main.cpp && astyle --style=linux main.cpp && g++ -Wall -Wextra -o main.o main.cpp`

#List format

The following lists will be written as followed.

* (h1 title) Contest name(type)
    * Division(if present)
        1. Round / contest name
            * solved problem

#Contest

* Div 2
    1. Round 312 (The first ever contest that I participated in!)
        * A, B
    2. Round 313
        * A, B, C
    3. Round Pi
        * A, B, C
    4. Round 315
        * A, B, C
    5. Round 316
        * A, B, C
    6. Round 317
        * A, B, C
    7. Round 318
        * A, B, C
    8. Round 319
        * A, B, C
    9. Round 320
        * A, B, D
    10. Round 321
        * A, B, C
    11. Round 322
        * A, B (Test case 53!!), C
    12. Round 323
        * A, B
    13. Round 324
        * A, B
    14. Round 325
        * A, B, C
    15. Round 326
        * A, B, C
    16. Round 327
        * A, B
    17. Round 328
        * A, B
    18. Round 329
        * A, B
    19. Testing Round #12
        * A, B
    20. Educational Round #1
        * A, B, C
    21. Round 332
        * A, B, C
    22. Round 333
        * A, B, C
    23. Educational Round #2
        * A, B
    24. Educational Round #3
        * A, B, C
    25. Round 336
        * A, B, C
    26. Educational Round #4
        * A, B, C, D
    27. Educational Round #5
        * A
    28. Goodbye 2015
        * A, B
    29. Round 339
        * A, B, C
    30. Round 228
        * A, B, C, D, E
    31. Educational Round #6
        * A, B, C, D
    32. Round 234
        * A, B, C
    33. Round 244
        * A, B, C (SCC), E
    34. Round 271
        * A, B
    35. Round 340
        * A, B, C, D
    36. Round 247
        * A, B, C (無限背包), D (unsolved)
    37. Round 338
        * B
    38. Wunder Fund Round 2016 (Div. 1 + Div. 2 combined)
        * A, B
    39. Round 341
        * A, B
    40. Round 311
        * B
    41. AIM Tech Round (Div. 2)
        * A, B
    42. Round 342
        * A, B, C
    43. Educational Round 7
        * A, B, C, D, E
    44. 8VC Venture Cup 2016 - Elimination Round
        * A, B, C, D
    45. Educational Round 8
        * A, B, C
    46. Round 343
        * A, B
    47. Educational Round 9
        * A, B, C
    48. Round 345
        * A, B, C (You will never forget to use long long to do (x * (x - 1) / 2))
    49. CROC 2016 - Qualification
        * A, B
    50. IndiaHacks 2016 - Online Edition
        * A, B

# Gym

1. Acm Aamman Collegiate Programming Contest (3-star)
    * C, E, J, K
2. 2013-2014 Samara SAU ACM ICPC Quarterfinal Qualification Contest (3-star)
    * A, B, H (F TLE)
3. 2014-2015 Samara SAU ACM ICPC Quarterfinal Qualification Contest
    * A, E, F, G, I, M
4. 2015-2016 Samara SAU ACM ICPC Quarterfinal Qualification Contest
    * B, D, F, I, J
5. 2015-2016 ACM ICPC Baltic Selection Contest
    * A, D, F, G, H, K, L
6. 2014 Nordic Collegiate Programming Contest
    * H, K

# Notes

* Test for upper/lower bound input that's given by the problem statement. (Hacks may come from here! Ex: Round 316 Div2 problem B)
*Think of `long long int` before coding.
* Does the problem need a linear scan? Or just look at its left and right? (Round 316 Div2 problem C)
* Read the problem statements carefully. Use pen and paper to finalize thoughts before actually coding them! (Try all test cases first)
* Don't rush! Double check the source code and rethink the program flow before submitting the code. (Rubber duck debugging)
* If `long long int` is required, declare all of the variables using `long long int` in case you miss any of them. (2013-2014 Samara SAU ACM ICPC Quarterfinal Qualification Contest problem C, forgot to use `long long int` for `sum_so_far`, stupid)
* Use `scanf("%s", input)` when there is no spaces in the string. Mix usage of `fgets` and `scanf` will have `\n` problem.
* `scanf()` > `fgets()`
* UVa 11988: when using global variables, don't forget to INITIALIZE it before starting reading in new test cases!!
* Test the special cases, such as 0, -1, 1, or max_value, before even submitting the code.
* When using `double`, don't make mistakes like
  ```
  int x = 1, y = 2;
  double s = y / x;
  ```
* Not all the restrictions are actually possible!! (Round 333 Problem C, Round 327 C)
* Be aware while working with long long int. See `Educational Round 6 problem D`
* Don't use `memset` unless it's necessary!. See `Educational Round 6 problem E`
* `ans -= tmp_cnt * (tmp_cnt - 1LL) / 2LL;`, this way can avoid problems when forget to use ll for tmp_cnt. See `Round 345 Problem C`


# Command

`find . -type f -name '*.orig' -delete`

# bash_profile

* Add `gcc5` in `/usr/local/bin` to `PATH` in `bash_profile`
