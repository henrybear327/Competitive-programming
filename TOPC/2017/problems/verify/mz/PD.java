import java.lang.*;
import java.io.*;
import java.util.*;

class PD{
	static class Coin {
		char type;
		int cnt;
		Coin(char t, int count)
		{
			type = t;
			cnt = count;
		}
	}
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		while(T-->0)
		{
			int N = Integer.parseInt(br.readLine());
			Queue<Coin> q = new LinkedList<Coin>();
			Stack<Coin> s = new Stack<Coin>();
			for(int i = 0; i < N; i++)
			{
				String line = br.readLine();
				q.add(new Coin(line.charAt(0), Integer.parseInt(line.substring(2))));
			}
			while(!q.isEmpty())
			{
				Coin cq = q.poll(), cs = s.empty()?null:s.peek();
				if(cs!=null && cq.type==cs.type)
				{
					int sum = cq.cnt+cs.cnt;
					cs.cnt = sum % 3;
					if(cs.cnt==0)
						s.pop();
					if(sum>=3)
					{
						cq.cnt = sum/3;
						q.add(cq);
					}
				}
				else
				{
					if(cq.cnt>=3)
						q.add(new Coin(cq.type, cq.cnt/3));
					cq.cnt %= 3;
					if(cq.cnt!=0)
						s.push(cq);
				}
			}
			long ans = 0L;
			for(Coin c: s)
				ans += c.cnt;
			System.out.println(ans);
		}
	}
}
