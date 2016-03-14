import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scan scan = new Scan();
        int testcases = Integer.parseInt(scan.nextLine());
        while (testcases-- != 0) {
            StringTokenizer input = new StringTokenizer(scan.nextLine());
            ArrayList<Integer> list = new ArrayList<Integer>();
            while (input.hasMoreElements())
                list.add(Integer.parseInt(input.nextToken()));
            Set<Integer> set = new HashSet<Integer>();
            int result = 0;
            for (int i = list.size() - 1; i >= 0; i--) {
                if (set.contains(list.get(i)))
                    continue;
                result += i + 1;
                set.add(list.get(i));
            }
            System.out.println(result);
        }
    }
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
