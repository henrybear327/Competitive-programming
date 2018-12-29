# Java Notes

## Difference with c++

* True OOP
* Can't compare boolean with integer
```java
boolean ok = false;
if(ok == 1) {
    // WRONG!
}
```
* Use `StringBuilder` for large output! (Educational Codeforces Round 7 Problem D)

## Fast input

```java
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        // Start writing your solution here.

        /*
        int n      = sc.nextInt();        // read input as integer
        long k     = sc.nextLong();       // read input as long
        double d   = sc.nextDouble();     // read input as double
        String str = sc.next();           // read input as String
        String s   = sc.nextLine();       // read whole line as String

    	while(sc.hasNext()) {
    		...
    	}

        int result = 3*n;
        out.println(result);                    // print via PrintWriter
        */

        // Stop writing your solution here.
        out.close();
    }

    // PrintWriter for faster output
    public static PrintWriter out;

    // MyScanner class for faster input
    public static class MyScanner
    {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        boolean hasNext()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    return false;
                }
            }
            return true;
        }

        String next()
        {
            if (hasNext())
                return st.nextToken();
            return null;
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}

```

## StringBuilder

* Basic template
```java
StringBuilder sb = new StringBuilder();
for(int i = 0; i < 2 * n; i++) {
     sb.append(ans[i]);
     if(i == 2 * n - 1)  
        sb.append('\n');
     else  
        sb.append(' ');
}
out.println(sb);
```

## Array

* Fixed size: `int[] name = new int[size];`
* Dynamic: `??`
