import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] argv) {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNext() == true) {
			BigInteger a = sc.nextBigInteger();
			BigInteger b = sc.nextBigInteger();

			System.out.println(a.multiply(b));
		}
	}
}
