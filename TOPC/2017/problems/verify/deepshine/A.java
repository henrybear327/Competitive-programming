import java.io.*;
import java.util.*;

public class A{
    
    public static void main(String[] args){
        Scan scan = new Scan();
        int testcases = scan.nextInt();
        if(testcases < 1 || testcases > 25) throw new IllegalArgumentException("wrong test case size : "+testcases);
        while(testcases-- != 0){
            int a = scan.nextInt();
            if(a < 1 || a >10) throw new IllegalArgumentException("wrong m size : "+a);
            int b = scan.nextInt();
            if(b < 1 || b >10) throw new IllegalArgumentException("wrong n size : "+b);
            boolean[] intersect = new boolean[10];
            boolean[] union = new boolean[10];
            for(int i=0;i<a;i++){
                int x = scan.nextInt();
                verify(x, 0, 10);
                union[x] = true;
            }
            for(int i=0;i<b;i++){
                int x = scan.nextInt();
                verify(x, 0, 10);
                intersect[x] = union[x];
                union[x] = true;
            }
            int top = 0, bot = 0;
            for(int i=0;i<10;i++) top += intersect[i] ? 1 : 0;
            for(int i=0;i<10;i++) bot += union[i] ? 1 : 0;
            if(2 * top > bot){
                System.out.println("1");
            }else{
                System.out.println("0");
            }
        }
        if(scan.hasNext()) throw new IllegalArgumentException("tailing input");
    }
    
    static void verify(int value, int min, int max){
        if(value < min || value >= max) throw new IllegalArgumentException("verification failed : "+value); 
    }
    
}

class Scan{
    
    BufferedReader buffer;
    StringTokenizer tok;
    
    Scan(){
        buffer = new BufferedReader(new InputStreamReader(System.in));
    }
    
    boolean hasNext(){
        while(tok==null || !tok.hasMoreElements()){
            try{
                tok = new StringTokenizer(buffer.readLine());
            }catch(Exception e){
                return false;
            }
        }
        return true;
    }
    
    String next(){
        if(hasNext()) return tok.nextToken();
        return null;
    }
    
    int nextInt(){
        return Integer.parseInt(next());
    }
    
}
