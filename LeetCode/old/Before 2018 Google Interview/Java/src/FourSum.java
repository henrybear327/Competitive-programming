import java.util.*;
import java.util.Map.Entry;

public class FourSum {
	public List<List<Integer>> fourSum(int[] nums, int target) {
		ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();

		Arrays.sort(nums);

		// for every pair of indices, make a (sum, (i, j)) pair
		HashMap<Integer, ArrayList<Pair>> pre = new HashMap<Integer, ArrayList<Pair>>();
		for (int i = 0; i < nums.length; i++)
			for (int j = i + 1; j < nums.length; j++) {
				int sum = nums[i] + nums[j];
				if (!pre.containsKey(sum))
					pre.put(sum, new ArrayList<Pair>());
				pre.get(sum).add(new Pair(i, j));
			}

		// iterate over all pairs and check condition
		HashSet<ArrayList<Integer>> check = new HashSet<ArrayList<Integer>>();
		for (Entry<Integer, ArrayList<Pair>> i : pre.entrySet()) {
			if (pre.containsKey(target - i.getKey())) { 
				// don't need to iterate for j, just check for existence
				ArrayList<Pair> j = pre.get(target - i.getKey());

				for (Pair x : i.getValue()) {
					for (Pair y : j) {
						ArrayList<Integer> cur = new ArrayList<Integer>();
						if (x.getFirst() == y.getFirst() || x.getFirst() == y.getSecond())
							continue;
						if (x.getSecond() == y.getFirst() || x.getSecond() == y.getSecond())
							continue;

						cur.add(nums[x.getFirst()]);
						cur.add(nums[x.getSecond()]);
						cur.add(nums[y.getFirst()]);
						cur.add(nums[y.getSecond()]);

						Collections.sort(cur);

						if (check.contains(cur) == false) {
							check.add(cur);
							res.add(cur);
						}
					}
				}
			}
		}

		return res;
	}

	public static class Pair implements Comparable<Pair> {
		int first, second;

		public Pair(int x, int y) {
			first = x;
			second = y;
		}

		public int getFirst() {
			return this.first;
		}

		public int getSecond() {
			return this.second;
		}

		public int compareTo(Pair o) {
			if (this.first == o.getFirst())
				return this.second - o.getSecond();
			return this.first - o.getFirst();
		}

	}

	public static void main(String[] args) {
		int[] nums = { 1, 0, -1, 0, -2, 2 };
		int target = 0;

		FourSum s = new FourSum();
		List<List<Integer>> res = s.fourSum(nums, target);

		for (int i = 0; i < res.size(); i++) {
			System.out.print("Output: ");
			for (int j = 0; j < res.get(i).size(); j++)
				System.out.printf("%d ", res.get(i).get(j));
			System.out.println("");
		}
	}

}