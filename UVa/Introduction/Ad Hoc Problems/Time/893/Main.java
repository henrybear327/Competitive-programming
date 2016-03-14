import java.io.*;
import java.util.*;
import java.util.Calendar;

public class Main
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int f, d, m, y;
        Calendar calendar = Calendar.getInstance();

        for(;;) {
            f = sc.nextInt();
            d = sc.nextInt();
            m = sc.nextInt();
            y = sc.nextInt();

            if(f == 0 && d == 0 & m == 0 & y == 0) break;

            m--;
            calendar.set(y, m, d);
            calendar.add(Calendar.DAY_OF_YEAR, f);

            //System.out.println(); //slower, but no flush needed.

            out.printf("%d %d %d\n",
                       calendar.get(Calendar.DAY_OF_MONTH),
                       calendar.get(Calendar.MONTH) + 1,
                       calendar.get(Calendar.YEAR));
        }

        out.close();
    }

    //PrintWriter for faster output
    public static PrintWriter out;

    //MyScanner class for faster input
    public static class MyScanner
    {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }
    }
}


