import java.io.*;
import java.util.*;

public class C
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt(), m = sc.nextInt();
        
        int[] inp = new int[n];
        for(int i = 0; i < n; i++)
        	inp[i] = sc.nextInt();
        Arrays.sort(inp);
        
        int idx = 0, cost = 0;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for(int i = 1;; i++) {
        	if(idx < n && inp[idx] == i) {
        		idx++;
        		continue;
        	}
        	if(cost + i > m)
        		break;
        	ans.add(i);
        	cost += i;
        }
        
        out.println(ans.size());
        for(int i = 0; i < ans.size(); i++)
        	out.print(ans.get(i) + " ");
        
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
