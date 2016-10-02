public class addTwoNumbers {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode res = new ListNode(-1), nextPos = res;
		
		int carry = 0;
		while(l1 != null && l2 != null) {
			int val = l1.val + l2.val + carry;
			carry = val / 10 > 0 ? 1 : 0;
			val %= 10;
			
			nextPos.next = new ListNode(val);
			nextPos = nextPos.next;
			
			l1 = l1.next;
			l2 = l2.next;
		}
		
		for(; l1 != null; l1 = l1.next) {
			int val = l1.val + carry;
			nextPos.next = new ListNode(val % 10);
			nextPos = nextPos.next;
			carry = val / 10 > 0 ? 1 : 0;
		}
		
		for(; l2 != null; l2 = l2.next) {
			int val = l2.val + carry;
			nextPos.next = new ListNode(val % 10);
			nextPos = nextPos.next;
			carry = val / 10 > 0 ? 1 : 0;
		}
		
		if(carry != 0) {
			// crucial!
			nextPos.next = new ListNode(1);
		}
		
		return res.next;
	}
	
	public static class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
		}
	}

	public static void main(String argc[]) {
		ListNode l1 = new ListNode(2);
		l1.next = new ListNode(4);
		l1.next.next = new ListNode(3);
		l1.next.next.next = null;

		ListNode l2 = new ListNode(5);
		l2.next = new ListNode(6);
		l2.next.next = new ListNode(4);
		l2.next.next.next = null;

		addTwoNumbers s = new addTwoNumbers();

		ListNode res = s.addTwoNumbers(l1, l2);

		for (int i = 0; res != null; i++, res = res.next)
			System.out.println(i + " " + res.val);
	}
}