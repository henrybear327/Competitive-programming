import java.util.TreeMap;

/**
 * Created by henrybear327 on 5/21/17.
 */
public class A {
    public int findLHS(int[] nums) {
        if(nums.length == 0)
            return 0;

        TreeMap<Integer, Integer> cnt = new TreeMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++) {
            int tmp = cnt.getOrDefault(nums[i], 0);
            tmp++;
            cnt.put(nums[i], tmp);
        }

        int res = 0;
        for(int i = 0; i < nums.length; i++) {
            int cur = cnt.getOrDefault(nums[i], 0);
            int nxt = cnt.getOrDefault(nums[i] + 1, 0);
            int prev = cnt.getOrDefault(nums[i] - 1, 0);

            if(cur > 0 && nxt > 0)
                res = Math.max(res, cur + nxt);
            if(cur > 0 && prev > 0)
                res = Math.max(res, cur + prev);
        }

        return res;
    }

    public static void main(String[] args) {
        A s = new A();
        System.out.println(s.findLHS(new int[] {1,1,1,1}));
    }
}