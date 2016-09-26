import java.util.*;

public class ThreeSum {
	public List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		Arrays.sort(nums);
		
		for(int i = 0; i < nums.length - 2; i++) {
			if(i != 0 && nums[i] == nums[i - 1]) {
				continue;
			}
				
			int j = i + 1, k = nums.length - 1;
			// use 2sum concept
			while(j < k) {
				//System.out.println(i + " " + j + " " + k);
				if(nums[i] + nums[j] + nums[k] == 0) {
					//System.out.println("PushBack = " + i + " " + j + " " + k);
					ArrayList<Integer> cur = new ArrayList<Integer>();
					cur.add(nums[i]);
					cur.add(nums[j]);
					cur.add(nums[k]);
					
					res.add(cur);
					
					k--;
					while(k - 1 > j && nums[k] == nums[k + 1])
						k--;
					j++;
					while(j + 1 < k && nums[j] == nums[j - 1])
						j++;
				} else if (nums[i] + nums[j] + nums[k] > 0) {
					k--;
				} else {
					j++;
				}
			}
		}
		
		return res;
		
		/*
		// TLE 0.14s local machine, but the OJ time limit is 0.15s
		HashMap<Integer, ArrayList<Pair>> set = new HashMap<Integer, ArrayList<Pair>>();
		HashSet<ArrayList<Integer>> check = new HashSet<ArrayList<Integer>>();

		// enumerate all pairs
		for (int i = 0; i < nums.length; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				if (set.containsKey(nums[i] + nums[j]) == false) {
					set.put(nums[i] + nums[j], new ArrayList<Pair>());
					set.get(nums[i] + nums[j]).add(new Pair(i, j));
				} else {
					set.get(nums[i] + nums[j]).add(new Pair(i, j));
				}
			}
		}

		// enumerate the third index
		for (int i = 0; i < nums.length; i++) {
			if (set.containsKey(-nums[i]) == true) {
				ArrayList<Pair> tmp = set.get(-nums[i]);
				for (Pair j : tmp) {
					if (j.first != i && j.second != i) {
						ArrayList<Integer> ans = new ArrayList<Integer>();
						if(nums[i] < nums[j.first])
							ans.add(nums[i]);
						ans.add(nums[j.first]);
						if(nums[j.first] <= nums[i] && nums[i] < nums[j.second])
							ans.add(nums[i]);
						ans.add(nums[j.second]);
						if(nums[i] >= nums[j.second])
							ans.add(nums[i]);

						// Collections.sort(ans);
						if (check.contains(ans) == false) {
							res.add(ans);
							check.add(ans);
						}
					}
				}
			}
		}

		return res;
		*/
	}

	public static class Pair {
		int first, second;

		public Pair(int x, int y) {
			first = x;
			second = y;
		}
	}

	public static void main(String[] args) {
		/*
		int[] nums = { -10, -7, -3, -9, -8, -9, -5, 6, 0, 6, 4, -15, -12, 3, -12, -10, -5, -5, 2, -4, 13, 8, -9, 6, -11,
				11, 3, -13, -3, 14, -9, 2, 14, -5, 8, -9, -7, -12, 5, 1, 2, -6, 1, 5, 4, -4, 3, 7, -2, 12, 10, -3, 6,
				-14, -12, 10, 12, 7, 12, -14, -2, 11, 4, -10, 13, -11, -4, -8, -15, -14, 8, -6, -12, -14, 6, 7, -3, -14,
				-1, 11, 14, -6, -15, 5, -13, -12, 0, 14, 2, -11, -14, 8, -15, -3, 13, 14, -7, -14, 13, -15, 10, -2, -14,
				13 };
		*/
		int[] nums = { 7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,
				-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,
				9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,
				13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6 };
		
				
		// int[] nums = {-1,0,1,2,-1,-4};

		ThreeSum s = new ThreeSum();
		List<List<Integer>> res = s.threeSum(nums);

		/*
		 for(int i = 0; i < res.size(); i++) { 
			 System.out.print("Output: ");
			 for(int j = 0; j < res.get(i).size(); j++) 
				 System.out.printf("%d ", res.get(i).get(j));
			 System.out.println(""); 
		 }
		 */
	}

}