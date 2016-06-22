import java.io.*;
import java.util.*;

public class B
{
	public static void shuffleArray(int[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i = 0; i < n; i++){
            int tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }   
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt();
        int[] inp = new int[n];
        for(int i = 0; i < n; i++)
        	inp[i] = sc.nextInt();
        
        shuffleArray(inp);;
        Arrays.sort(inp);
        
        int ans = 1;
        for(int i = 0; i < n; i++) {
        	if(inp[i] >= ans)
        		ans++;
        	else if(inp[i] == ans - 1)
        		continue;
        	else
        		break;
        }
        
        /*
        ArrayList<Integer> inp = new ArrayList<Integer>();
        for(int i = 0; i < n; i++)
        	inp.add(sc.nextInt());
        
        Collections.sort(inp);
        
        int ans = 1;
        for(int i = 0; i < n; i++) {
        	if(inp.get(i) >= ans)
        		ans++;
        	else if(inp.get(i) == ans - 1)
        		continue;
        	else
        		break;
        } 
         
         */
        
        out.println(ans);
        
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
