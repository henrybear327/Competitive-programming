import java.util.*;

import org.omg.CosNaming.NamingContextExtPackage.StringNameHelper;

public class LongestPalindromicSubstring {
	public String longestPalindrome(String s) {
		// O(n^2)
		if(s.length() == 0)
			return "";
		
		String result = "";
		
		int left = -1, right = -1;

		// handle odd length aba
		for(int i = 0; i < s.length(); i++) { // for every position
			int j;
			for(j = 1; (i - j) >= 0 && (i + j) < s.length(); j++) {
				// check
				if(s.charAt(i + j) != s.charAt(i - j)) {
					break;
				}
			}
			j--;
			
			if ((i - j) >= 0 && (i + j) < s.length() && right - left < 1 + 2 * j) {
				left = i - j;
				right = i + j + 1;
			}
		}
		
		// handle even length bbbbbb
		for(int i = 0; i < s.length(); i++) { // for every position
			if(i + 1 < s.length() && s.charAt(i) == s.charAt(i + 1)) {				
				int j;
				for(j = 1; (i - j) >= 0 && (i + j + 1) < s.length(); j++) {
					// check
					if(s.charAt(i + j + 1) != s.charAt(i - j)) {
						break;
					}
				}
				j--;
				
				if ((i - j) >= 0 && (i + j + 1) < s.length() && right - left < 2 * (j + 1)) {
					left = i - j;
					right = i + j + 2;
				}	
			}
		}
		
		return left != -1 ? s.substring(left, right) : "";
	}
	
	public static void main(String argc[]) {
		LongestPalindromicSubstring s = new LongestPalindromicSubstring();
		System.err.println(s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	}
}
