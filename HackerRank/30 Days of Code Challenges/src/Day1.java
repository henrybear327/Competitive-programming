import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Day1 {
	
    public static void main(String[] args) {
        int i = 4;
        double d = 4.0;
        String s = "HackerRank ";
		
        Scanner scan = new Scanner(System.in);
                
        i += scan.nextInt();
        d += scan.nextDouble();
        scan.nextLine();
        s += scan.nextLine(); // just like fgets() after scanf()
        
        System.out.println(i);
        System.out.printf("%.1f\n", d);
        System.out.println(s);
        
        scan.close();
    }
}