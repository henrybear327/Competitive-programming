import java.io.*;
import java.util.*;

public class B{
    
    public static void main(String[] args){
        Scan scan = new Scan();
        int testcases = scan.nextInt();
        verify(testcases, 1, 26);
        while(testcases-- != 0){
            int[] counter = new int[13];
            for(int i=0;i<6;i++){
                counter[scan.nextInt()-1]++;
            }
            int[] comb = new int[5];
            for(int i=0;i<13;i++) comb[counter[i]]++;
            String result;
            if(comb[4]==1 && comb[2]==1) result = "tiki pair";
            else if(comb[3]==1 && comb[2]==1) result = "full house";
            else if(comb[4]==1) result = "tiki";
            else if(comb[3]==2) result = "two triples";
            else if(comb[3]==1) result = "one triple";
            else if(comb[2]==3) result = "three pairs";
            else if(comb[2]==2) result = "two pairs";
            else if(comb[2]==1) result = "one pair";
            else result = "single";
            System.out.println(result);
        }
        if(scan.hasNext()) throw new IllegalArgumentException("trailing input");
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
