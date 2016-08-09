# [How to connect to TopCoder on Mac](https://www.topcoder.com/tc?module=Static&d1=help&d2=getStarted)

1. Download the app [here](http://www.topcoder.com/contest/arena/ContestAppletProd.jnlp)
2. Add the following links to `Control Panel -> Java -> Security -> Exception list`, or the app won't be able to open
```
http://topcoder.com
http://www.topcoder.com
http://arena.topcoder.com
```
3. Launch the app via terminal `javaws  ContestAppletProd.jnlp`, or right-click on `ContestAppletProd.jnlp` and then click `Open with -> Java Web Start`


You should be good to go.

# How to compete in Java

```java
import java.io.*;
import java.util.*;

public class $CLASSNAME$ {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// code for reading the input

        // send in the argument and print out the answer
		System.out.println(findPassword(x));
	}

	public static $MATHOD_NAME_ARG_AND_TYPE$ {
		TYPE res;

        // code

		return res;
	}
}

```

# How to compete in C++

```c++
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

class $CLASSNAME$ {
    public:
    $RC$ $METHODNAME$($METHODPARMS$) {

    }

    $TESTCODE$
};

int main() {
    $CLASSNAME$ ___test;
    ___test.run_test(-1);
}
```
