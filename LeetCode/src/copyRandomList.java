import java.util.*;

public class copyRandomList {
	public RandomListNode copyRandomList(RandomListNode head) {
		if(head == null) // come on...
			return null;
		
		HashMap<RandomListNode, RandomListNode> mapping = new HashMap<RandomListNode, RandomListNode>();
		
		for(RandomListNode cur = head; cur != null; cur = cur.next) {
			RandomListNode newNode = new RandomListNode(cur.label);
			mapping.put(cur, newNode);
		}
		mapping.put(null, null);
		
		for(RandomListNode cur = head; cur != null; cur = cur.next) {
			RandomListNode next = mapping.get(cur.next);
			RandomListNode rndNext = mapping.get(cur.random);
			
			mapping.get(cur).next = next;
			mapping.get(cur).random = rndNext;
		}
				
		// connect head
		return mapping.get(head);
	}

	public static class RandomListNode {
		int label;
		RandomListNode next, random;

		RandomListNode(int x) {
			this.label = x;
		}
	};

	public static void main(String argc[]) {
		RandomListNode head = new RandomListNode(0);
		head.next = new RandomListNode(1);
		head.next.next = new RandomListNode(2);
		
		head.random = head.next;
		head.next.random = head;
		head.next.random = head.next.next;
		
		copyRandomList s = new copyRandomList();

		RandomListNode res = s.copyRandomList(head);

		for (int i = 0; res != null; i++, res = res.next)
			System.out.println(i + " " + res.label);
	}
}