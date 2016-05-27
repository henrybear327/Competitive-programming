import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Day1 {
	
    public static void main(String[] args) {
        int i;
        double d = 4.0;
        String s = "HackerRank ";
		
        Scanner scan = new Scanner(System.in);
                
        i = scan.nextInt();
        d = scan.nextDouble();
        s += scan.nextLine();
        
        System.out.println(i);
        System.out.printf("%.1f\n", d);
        System.out.println(s);
        
        scan.close();
    }
}