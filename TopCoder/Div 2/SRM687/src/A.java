import java.io.*;
import java.util.*;

public class A
{
	public static class Quorum
	{
		public static int count(int[] arr, int k)
		{
			Arrays.sort(arr);
			int ans = 0;
			for(int i = 0; i < k; i++)
				ans += arr[i];
		
			return ans;
		}
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        // Start writing your solution here.
        
        int n = sc.nextInt(), k = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++)
        	arr[i] = sc.nextInt();
       
        out.println(Quorum.count(arr, k));

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

/*
import java.io.*;
import java.util.*;	
public class Quorum
{
	public int count(int[] arr, int k)
	{
		Arrays.sort(arr);
		int ans = 0;
		for(int i = 0; i < k; i++)
			ans += arr[i];
	
		return ans;
	}
} 
*/
