public class swapPairs {
	public ListNode swapPairs(ListNode head) {
		// prev -> u -> v -> next
		// prev -> v -> u -> next
		
		ListNode cur = head, prev = null, next = null, u = null, v = null;
		for(int i = 0; cur != null; cur = cur.next, i++) {
			if(i % 2 == 1) {
				// swap
				v = cur;
				next = v.next;
				
				if(prev == null) {
					// head
					head = v;
					v.next = u;
					u.next = next;
				} else {
					prev.next = v;
					v.next = u;
					u.next = next;
				}
				
				// crucial step!! Think about this!
				prev = u; 
				cur = u;
				
				/*
				ListNode tmp = head;
				for (int j = 0; tmp != null; i++, tmp = tmp.next)
					System.out.println(i + " " + tmp.val);
				System.out.println("");
				*/
			} else {
				u = cur;
			}
		}
			
		return head;
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
		ListNode l1 = new ListNode(1);
		l1.next = new ListNode(2);
		l1.next.next = new ListNode(3);
		l1.next.next.next = new ListNode(4);

		swapPairs s = new swapPairs();

		ListNode res = s.swapPairs(l1);

		for (int i = 0; res != null; i++, res = res.next)
			System.out.println(i + " " + res.val);
	}
}