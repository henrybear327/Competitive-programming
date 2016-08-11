import java.io.*;
import java.util.*;

public class Ropestring {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.nextLine();

		System.out.println(makerope(s));
	}

	public static String makerope(String s) {
		String res = "";

		ArrayList<Integer> odd = new ArrayList<Integer>();
		ArrayList<Integer> even = new ArrayList<Integer>();

		int cnt = 0, dot = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '.') {
				if (cnt > 0) {
					if (cnt % 2 == 0)
						even.add(cnt);
					else
						odd.add(cnt);
					cnt = 0;
				}
				dot++;
			} else {
				cnt++;
			}
		}

		if (cnt > 0) {
			if (cnt % 2 == 0)
				even.add(cnt);
			else
				odd.add(cnt);
			cnt = 0;
		}

		Collections.sort(odd);
		Collections.sort(even);

		for (int i = even.size() - 1; i >= 0; i--) {
			for (int j = 0; j < even.get(i); j++) {
				res += '-';
			}
			if (dot > 0) {
				dot--;
				res += '.';
			}
		}

		for (int i = odd.size() - 1; i >= 0; i--) {
			for (int j = 0; j < odd.get(i); j++) {
				res += '-';
			}
			if (dot > 0) {
				dot--;
				res += '.';
			}
		}
		
		for(int i = 0; i < dot; i++) 
			res += '.';

		return res;
	}
}
