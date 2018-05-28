public class isPalindrome {
    public boolean isPalindrome(String s) {
    	/*
    	// Not fast enough
    	String str = "";
    	for(int i = 0; i < s.length(); i++) {
    		char c = s.charAt(i);
    		
    		if(Character.isLetterOrDigit(c) == false)
    			continue;
    		if(Character.isUpperCase(c)) 
    			c = Character.toLowerCase(c);
    			
    		str += c;
    	}
    	System.out.println(str);
    	
    	for(int i = 0; i < str.length() / 2; i++) {
    		if(str.charAt(i) != str.charAt(str.length() - 1- i))
    			return false;
    	}
    	return true;
    	*/
    	
    	int left = 0, right = s.length() - 1;
    	while(left < right) {
    		while(left < right && Character.isLetterOrDigit(s.charAt(left)) == false) // the first condition is crucial!
    			left++;
    		while(left < right && Character.isLetterOrDigit(s.charAt(right)) == false)
    			right--;
    		// System.out.println(left + " " + right);
    		// System.out.println(s.charAt(left) + " " + s.charAt(right));

    		if(Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right)))
    			return false;
    		left++;
    		right--;
    	}
    	return true;
    }
     
    public static void main(String argc[]) {
    	String inp = "A man, a plan, a canal: Panama";
    	//String inp = "race a car";
    	
    	isPalindrome s = new isPalindrome();
    	System.out.println(s.isPalindrome(inp) == true ? "True" : "False");
    }
}