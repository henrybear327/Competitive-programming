import java.io.*;
import java.util.*;

public class C{
    
    public static void main(String[] args){
        Scan scan = new Scan();
        int testcases = scan.nextInt();
        verify(testcases, 1, 11);
        while(testcases-- != 0){
            int n = scan.nextInt();
            verify(n, 2, 100001);
            PriorityQueue<Event> pq = new PriorityQueue<>((x, y) -> x.time==y.time ? y.value - x.value : Long.compare(x.time, y.time));
            for(int i=0;i<n;i++){
                long a = scan.nextLong();
                long b = scan.nextLong();
                verify(a, 1, 1l<<32);
                verify(b, a, 1l<<32);
                pq.add(new Event(a, 1));
                pq.add(new Event(b, -1));
            }
            int sum = 0, result = 0;
            while(!pq.isEmpty()){
                Event now = pq.poll();
                sum += now.value; 
                result = Math.max(result, sum);
            }
            System.out.println(result);
        }
        if(scan.hasNext()) throw new IllegalArgumentException("trailing input");
    }
    
    static class Event{
        
        long time;
        int value;
        
        Event(long time, int value){
            this.time = time;
            this.value = value;
        }
        
    }
    
    static void verify(long value, long min, long max){
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
    
    long nextLong(){
        return Long.parseLong(next());
    }
    
}
