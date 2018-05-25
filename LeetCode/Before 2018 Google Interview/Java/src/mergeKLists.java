import java.util.*;

public class mergeKLists {
	// Sample solution
	/*
	private static final Comparator<ListNode> listComparator = new Comparator<ListNode>() {
		@Override
		public int compare(ListNode x, ListNode y) {
			return x.val - y.val;
		}
	};

	public ListNode mergeKLists(ListNode[] lists) {
		if(lists.length == 0)
			return null;
		Queue<ListNode> queue = new PriorityQueue<>(lists.length, listComparator);
		for (ListNode node : lists) {
			if (node != null) {
				queue.add(node);
			}
		}
		ListNode dummyHead = new ListNode(0);
		ListNode p = dummyHead;
		while (!queue.isEmpty()) {
			ListNode node = queue.poll();
			p.next = node;
			p = p.next;
			if (node.next != null) {
				queue.add(node.next);
			}
		}
		return dummyHead.next;
	}
	*/
	
	
	public ListNode mergeKLists(ListNode[] lists) {
		TreeMap<Integer, HashSet<ListNode> > data = new TreeMap<Integer, HashSet<ListNode> >();
		
		for(int i = 0; i < lists.length; i++) {
			ListNode cur = lists[i];
			for(; cur != null; cur = cur.next) {
				int val = cur.val;
				
				if(!data.containsKey(val)) 
					data.put(val, new HashSet<ListNode>());
				data.get(val).add(cur);
			}
		}
		
		ListNode head = new ListNode(-1), cur = head, prev = null;
		for(HashSet<ListNode> i : data.values()) {
			for(ListNode j : i) {
				// System.out.println(j.val);
				if(prev != null) {
					prev.next = j;
				}
				cur.next = j;
				prev = j;
				cur = j;
			}
		}
		cur.next = null;
		return head.next; // crucial
	}
	
	
	public static class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
			next = null;
		}
	}

	public static void main(String argc[]) {
		ListNode l0 = null;
		
		ListNode l1 = new ListNode(-3);
		l1.next = new ListNode(-2);
		l1.next.next = new ListNode(1);
		
		ListNode l2 = new ListNode(-2);
			
		ListNode[] array = new ListNode[] {l0, l1, l2};
	
		mergeKLists s = new mergeKLists();

		ListNode res = s.mergeKLists(array);
		 

		for (int i = 0; res != null; i++, res = res.next)
			System.out.println(i + " " + res.val);
	}
}