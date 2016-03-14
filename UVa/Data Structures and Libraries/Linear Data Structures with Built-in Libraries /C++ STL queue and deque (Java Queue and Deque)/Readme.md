# Notes

### 10901

#### The trickiest problem ever coded! Lots of conditions to take into account!

Add this one to favorite :)

1. The problem statement asked for the answer to be _in the same order as the input_! The third case in the `in.txt` tests this requirement!
2. The `.front()` seems unable to change the value of the member of the structure.
3. `now = now > l.front().time ? now : l.front().time;` This time updating equation is pretty tricky!
4. When discussing cases, you really need to think of EVERY POSSIBILITY before coding! You need to consider the `ferry position L/R` and `<= or > current time`
5. You need to wait for the car to show up in order to take action!

### 10172

1. Study the buggy code to think of the stupid bug again!!! Logical flaw!
2. Watch out for the empty and over capacity limit problem
3. Long problem statement, but simple simulation.
4. Not a bad way to check if all are empty or not.
```
bool is_empty = s.empty();
for (int i = 1; i <= station; i++)
    is_empty &= q[i].empty();
if (is_empty)
    break;
```
