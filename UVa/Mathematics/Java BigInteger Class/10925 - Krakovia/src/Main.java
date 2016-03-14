import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int cnt = 1;
        while(true) {
        	int n = sc.nextInt(), f = sc.nextInt();
        	if(n == 0 && f == 0)
        		break;
        	
        	BigInteger tot = BigInteger.ZERO;
        	for(int i = 0; i < n; i++) {
        		tot = tot.add(sc.nextBigInteger());
        	}
        	
        	// Bill #1 costs 16200000000: each friend should pay 5400000000
        	System.out.println("Bill #" + cnt++ + " costs " + 
        			tot + ": each friend should pay " + tot.divide(BigInteger.valueOf(f)) + "\n");
        }
    }
}
