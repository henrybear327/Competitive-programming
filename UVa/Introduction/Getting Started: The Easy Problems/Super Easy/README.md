# Notes

### 12250

Use ```const char * array[]``` instead of  ```char * array[]```

Without the ```const```, the compiler will throw ```warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]```

[Stackoverflow](http://stackoverflow.com/questions/21529194/c-warning-deprecated-conversion-from-string-constant-to-char-wwrite-stri) has a good article about this issue.
