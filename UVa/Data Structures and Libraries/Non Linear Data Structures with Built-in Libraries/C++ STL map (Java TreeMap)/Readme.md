# Notes

### 10226

1. `cout` won't flush unless you manually do it or use endl!
2. When using cout, the precision setting must be done using `setprecision(digits)`,but this will set the *total* digits. In order to set only the floating point digits, use [fixed + setprecision](http://stackoverflow.com/questions/3923202/set-the-digits-after-decimal-point). For example: ` cout << i->first << " " << fixed << setprecision(4) << ans << '\n'; ` is equivalent to `printf("%.4f", ans);`
3. It's a better idea to use `string` type instead of `char *` for map key.
Declaration example:  `map<string, int> data;`
4. Map traversal using iterator: `for (map<string, int>::iterator i = data.begin(); i != data.end(); i++)`
5. Don't forget to use

```
ios::sync_with_stdio(false);
cin.tie(0);
```
### 11572

The main idea behind this problem is to find the maximum distinct sequence using `<map>`

The test data may mislead you into believing that this is an easy `<map>` problem, but _every snowflake in a package must be different from the others_ is the key point and the trickiest thing to consider!!

BTW, the performance difference of this problem between `<map>` and `<unordered_map>` is significant!

### 11286

Think of a special way to record every sequence of input in order to store it into a `<map>`. I choose to use a string to store sorted sequence of numbers so if they chose the same set of courses, they will have the same string!
