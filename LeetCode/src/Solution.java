import java.util.*;

import org.omg.CosNaming.NamingContextExtPackage.StringNameHelper;

public class Solution {
	public static void main(String argc[]) {
		StringBuilder sb = new StringBuilder();
		
		for(int i = 0; i < 500; i++) 
			for(int j = 0; j < 500; j++)
				sb.append(i + j).append("\n");
		System.out.println(sb);
	}
}
