import java.io.*;
import java.util.*;

public class Main{

	public static void main(String[] args){
		Scan scan = new Scan();
		int cases = scan.nextInt();
		
		int result = 0;
		
		for(int i = 0; i < cases; i++) {
		    if(scan.nextInt() == 1) {
		        result = 1;
		    }
		}
		
		if(result == 1) System.out.println("-1");
		else System.out.println("1");
	}

}

class Scan{

	BufferedReader buffer;
	StringTokenizer tok;

	Scan(){
		buffer = new BufferedReader(new InputStreamReader(System.in));
	}

	boolean hasNext(){
		while(tok==null || !tok.hasMoreElements()){
			try{
				tok = new StringTokenizer(buffer.readLine());
			}catch(Exception e){
				return false;
			}
		}
		return true;
	}

	String next(){
		if(hasNext()) return tok.nextToken();
		return null;
	}

	int nextInt(){
		return Integer.parseInt(next());
	}
}
