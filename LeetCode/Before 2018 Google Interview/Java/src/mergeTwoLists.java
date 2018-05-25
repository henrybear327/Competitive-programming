public class mergeTwoLists {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode head = new ListNode(0);
		ListNode nextPos = head;
		head.next = null;
		
		while(l1 != null && l2 != null) {
			// System.out.println("Before: " + l1 + " " + l2);

			// System.out.println(l1.val + " " + l2.val);
			if(l1.val < l2.val) {
				nextPos.next = l1; 
				l1 = l1.next;
			} else {
				nextPos.next = l2;
				l2 = l2.next;
			}
			
			nextPos = nextPos.next;
			// System.out.println("After: " + l1 + " " + l2);
		}
		
		if(l1 != null) 
			nextPos.next = l1;
		
		if(l2 != null) 
			nextPos.next = l2; 
		
		return head.next;
	}
	
	
	public static class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
		}
	}
	

	public static void main(String argc[]) {
		ListNode l1 = new ListNode(5);
		l1.next = null;
		
		ListNode l2 = new ListNode(1);
		l2.next = new ListNode(2);
		l2.next.next = new ListNode(4);
		l2.next.next.next = null;
		
		mergeTwoLists s = new mergeTwoLists();
		
		ListNode res = s.mergeTwoLists(l1, l2);
		
		for(int i = 0; res != null; i++, res = res.next)
			System.out.println(i + " " + res.val);
	}
}