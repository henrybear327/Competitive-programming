import java.io.*;
import java.util.*;
 
 
public class Main{
   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      // Start writing your solution here.
	
	int[] a;
        a = new int[6]; // 利用new指令產生物件
	for(int i = 0; i < 6; i++) {
	    int temp = sc.nextInt();	 
   	    a[i] = temp;
	}

	int answer = (a[0] + a[1] + a[2]) * (a[0] + a[1] + a[2]) - (a[0] * a[0]) - (a[2] * a[2]) - (a[4] * a[4]);
	System.out.println(answer);
      // Stop writing your solution here.
      out.close();
   }

   //PrintWriter for faster output
   public static PrintWriter out;
      
   //MyScanner class for faster input
   public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
   }
}

