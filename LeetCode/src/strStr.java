public class strStr {
	public int strStr(String haystack, String needle) {
        if(haystack.length() < needle.length())
        	return -1;
        for(int i = 0; i < haystack.length() - needle.length() + 1; i++) {
        	boolean ok = true;
        	for(int j = 0; j < needle.length(); j++) {
        		if(haystack.charAt(i + j) != needle.charAt(j)) {
        			ok = false;
        			break;
        		}
        	}
        	
        	if(ok == true)
        		return i;
        }
        return -1;
    }
     
    public static void main(String argc[]) {
    	String haystack = "KerKerIsGood";
    	String needle = "Is";
    	
    	strStr s = new strStr();
    	System.out.println(s.strStr(haystack, needle));
    }
}