public class reverseWords {
	public String reverseWords(String s) {
		s = s.trim();
		String[] ss = s.split(" ");

		String res = "";
		for (int i = ss.length - 1; i >= 0; i--) {
			if(ss[i].trim().length() == 0)
				continue;
			res += ss[i].trim();
			if (i != 0)
				res += " ";
		}
		return res;
	}

	public static void main(String argc[]) {
		//String str = "the sky is blue";
		String str = "   a   b ";
		
		reverseWords s = new reverseWords();
		System.out.println(s.reverseWords(str));
	}
}