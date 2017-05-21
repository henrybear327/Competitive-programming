import java.util.Arrays;
import java.util.TreeMap;

/**
 * Created by henrybear327 on 5/21/17.
 */
public class Solution {
    public int distSquare(Pair l) {
        return l.first * l.first + l.second * l.second;
    }

    public boolean right(Pair l1, Pair l2) {
        return (l1.first * l2.first + l1.second * l2.second) == 0;
    }

    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        Pair[] inp = new Pair[4];

        inp[0] = new Pair();
        inp[0].first = p1[0];
        inp[0].second = p1[1];

        inp[1] = new Pair();
        inp[1].first = p2[0];
        inp[1].second = p2[1];

        inp[2] = new Pair();
        inp[2].first = p3[0];
        inp[2].second = p3[1];

        inp[3] = new Pair();
        inp[3].first = p4[0];
        inp[3].second = p4[1];

        Arrays.sort(inp);

//        for(int i = 0; i < 4; i++) {
//            System.out.println(inp[i].first + " " + inp[i].second);
//        }

        Pair l1, l2, l3, l4;
        l1 = new Pair(inp[1].first - inp[0].first, inp[1].second - inp[0].second);
        l2 = new Pair(inp[2].first - inp[0].first, inp[2].second - inp[0].second);
        l3 = new Pair(inp[1].first - inp[3].first, inp[1].second - inp[3].second);
        l4 = new Pair(inp[2].first - inp[3].first, inp[2].second - inp[3].second);

        if(right(l1, l2) == false || right(l2, l4) == false)
            return false;

        int dist1 = distSquare(l1);
        int dist2 = distSquare(l2);
        int dist3 = distSquare(l3);
        int dist4 = distSquare(l4);

        if(dist1 != dist2 || dist2 != dist3 || dist3 != dist4)
            return false;

        if(dist1 == 0)
            return false;

        return true;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.validSquare(new int[]{0, 0},
                                         new int[]{1, 1},
                                         new int[]{2, 0},
                                         new int[]{1, -1}));
    }

    private class Pair implements Comparable<Pair> {
        int first;
        int second;

        public Pair() {
            first = 0;
            second = 0;
        }

        public Pair(int x, int y) {
            first = x;
            second = y;
        }

        @Override
        public int compareTo(Pair o) {
            if(first == o.first) {
                return second - o.second;
            }
            return first - o.first;
        }
    }
}