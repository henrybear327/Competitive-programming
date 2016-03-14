import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scan sc = new Scan();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int ncase =
            Integer.parseInt(sc.nextLine()); // Think of scanf("%d", &ncase);

        while (ncase-- != 0) {
            String test = sc.nextLine();
            System.err.println("String: " + test);

            StringTokenizer inp = new StringTokenizer(test);

            int[] data = new int[inp.countTokens()];
            int idx = 0;
            while (inp.hasMoreElements()) {
                data[idx++] = Integer.parseInt(inp.nextToken());
            }

            int[] cnt = new int[1010];
            int ans = 0;
            for (int i = idx - 1; i >= 0; i--) {
                if (cnt[data[i]] == 0) {
                    cnt[data[i]] = 1;
                    ans += i + 1;
                }
            }

            out.println(ans);
        }
        out.close();
    }

    // PrintWriter for faster output
    public static PrintWriter out;
}

class Scan
{

    BufferedReader buffer;
    StringTokenizer tok;

    Scan()
    {
        buffer = new BufferedReader(new InputStreamReader(System.in));
    }

    boolean hasNext()
    {
        while (tok == null || !tok.hasMoreElements()) {
            try {
                tok = new StringTokenizer(buffer.readLine());
            } catch (Exception e) {
                return false;
            }
        }
        return true;
    }

    String nextLine()
    {
        if (hasNext())
            return tok.nextToken("\n");
        return null;
    }
}
