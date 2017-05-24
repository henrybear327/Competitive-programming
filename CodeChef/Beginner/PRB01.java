import java.math.*;
import java.util.*;
import java.io.*;

class PRB01 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		while(n-- > 0) {
			int num = sc.nextInt();

			BigInteger hey = new BigInteger(Integer.toString(num));
			if(hey.isProbablePrime(50))
				System.out.println("yes");
			else
				System.out.println("no");
		}
	}
}
