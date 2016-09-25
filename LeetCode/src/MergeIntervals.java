import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class MergeIntervals {
	public List<Interval> merge(List<Interval> intervals) {
		// sort it first
		Collections.sort(intervals, new Comparator<Interval>() {
			@Override
			// l - r < 0: small -> large
			public int compare(Interval o1, Interval o2) {
				if (o1.start == o2.start)
					return o1.end - o2.end < 0 ? -1 : (o1.end - o2.end == 0 ? 0 : 1);
				else
					return o1.start - o2.start < 0 ? -1 : 1;
			}
		});

		/*
		 * for (int i = 0; i < intervals.size(); i++)
		 * System.out.println(intervals.get(i).start + " " +
		 * intervals.get(i).end);
		 */

		List<Interval> res = new ArrayList<Interval>();
		int activeLeft = -1, activeRight = -1;
		for (int i = 0; i < intervals.size(); i++) {
			if (activeLeft == -1) { // may have empty collection!
				activeLeft = intervals.get(i).start;
				activeRight = intervals.get(i).end;
			} else {
				if (activeLeft <= intervals.get(i).start
						&& intervals.get(i).start <= activeRight) {
					activeRight = Math.max(intervals.get(i).end, activeRight); // crucial bug
				} else {
					res.add(new Interval(activeLeft, activeRight));

					activeLeft = intervals.get(i).start;
					activeRight = intervals.get(i).end;
				}
			}
		}
		if (activeLeft != -1)
			res.add(new Interval(activeLeft, activeRight));

		return res;
	}

	public static void main(String[] args) {
		MergeIntervals s = new MergeIntervals();
		List<Interval> intervals = new ArrayList<Interval>();
		intervals.add(new Interval(8, 10));
		intervals.add(new Interval(15, 18));
		intervals.add(new Interval(1, 3));
		intervals.add(new Interval(2, 6));

		List<Interval> ans = s.merge(intervals);
		for (int i = 0; i < ans.size(); i++)
			System.out.println(ans.get(i).start + " " + ans.get(i).end);
	}
	
	// needs to be commented when submitting to Leetcode
	public static class Interval {
		int start;
		int end;

		Interval() {
			start = 0;
			end = 0;
		}

		Interval(int s, int e) {
			start = s;
			end = e;
		}
	}

}