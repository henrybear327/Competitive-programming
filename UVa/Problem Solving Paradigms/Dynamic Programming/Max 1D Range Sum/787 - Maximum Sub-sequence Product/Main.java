// http://www.itread01.com/content/1496586127.html

import java.util.*;
import java.math.*;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            BigInteger n;

            if (sc.hasNext() == false)
                break;

            n = sc.nextBigInteger();
            BigInteger ans = new BigInteger(n.toString());
            BigInteger mx = new BigInteger(n.toString());
            BigInteger mn = new BigInteger(n.toString());
            n = sc.nextBigInteger();

            BigInteger cmpTo = new BigInteger("-999999");
            while (n.compareTo(cmpTo) != 0) {
                BigInteger origMx = new BigInteger(mx.toString());
                BigInteger origMn = new BigInteger(mn.toString());

                // key is here
                // compare with n, not mx / mn, because we need CONSECUTIVE product
                mx = n.max(origMx.multiply(n)).max(origMn.multiply(n));
                mn = n.min(origMx.multiply(n)).min(origMn.multiply(n));

                // this update is crucial too
                ans = ans.max(mx);

//                num.add(n);
//                mx = mx.max(n);

                n = sc.nextBigInteger();
            }

//            for (int i = 0; i < num.size(); i++) {
//                BigInteger tmp = new BigInteger(num.get(i).toString());
//                for (int j = i + 1; j < num.size(); j++) {
//                    tmp = tmp.multiply(new BigInteger(num.get(j).toString()));
//                    mx = mx.max(tmp);
//                }
//            }

            System.out.println(ans);
        }
    }
}
