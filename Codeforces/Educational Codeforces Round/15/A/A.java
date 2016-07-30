import java.util.*;
import java.math.*;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int len = 1, ans = 1;
		int prev = sc.nextInt();
		for(int i = 0; i < n - 1; i++) {
			int cur = sc.nextInt();
			if(cur > prev)
				len++;
			else
				len = 1;

			prev = cur;

			ans = Math.max(ans, len);
		}

		System.out.println(ans);
	}

}
